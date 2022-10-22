/*
 * @Author: BilyHurington
 * @Date: 2020-07-17 22:22:05
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-07-24 11:38:23
 */ 
#include<bits/stdc++.h>
using namespace std;
struct Linear_Base{
    int val[5];
    Linear_Base(){memset(val,0,sizeof(val));}
    bool Insert(int x){
        for(int i=4;i>=0;i--){
            if(!((x>>i)&1)) continue;
            if(val[i]){x^=val[i];continue;}
            val[i]=x;
            for(int j=0;j<i;j++) if(val[j]&&((x>>j)&1)) val[i]^=val[j];
            for(int j=i+1;j<=4;j++) if((val[j]>>i)&1) val[j]^=val[i]; 
            return 1;
        }
        return 0;
    }
};
int Hash_Function(Linear_Base LB){
    int ans=0;
    for(int i=0;i<5;i++) ans|=LB.val[i]<<(i*(i+1)/2);
    return ans; 
}
unordered_map<int,int> mp;
unordered_map<int,Linear_Base> mp_inv; 
int lb_cnt;
void dfs_linear_base(Linear_Base LB){
    if(mp.count(Hash_Function(LB))) return;
    mp[Hash_Function(LB)]=++lb_cnt;
    mp_inv[lb_cnt]=LB;
    for(int i=1;i<(1<<5);i++){
        Linear_Base tmp=LB;
        if(tmp.Insert(i)) dfs_linear_base(tmp);
    }
}
int Merge[410][410],f[100010][410];
int n,m,dis[100010],rt[100010],len[100010],dfn[100010],dfn_tot;
vector<pair<int,int> > v[100010];
bool is_ok[100010],ltk[100010];Linear_Base LB[100010];
void dfs(int x,int fa,int R){
    rt[x]=R;dfn[x]=++dfn_tot;
    // printf("%d %d\n",x,dis[x]);
    for(int i=0;i<v[x].size();i++){
        if(v[x][i].first==fa) continue;
        if(!rt[v[x][i].first]) dis[v[x][i].first]=dis[x]^v[x][i].second,dfs(v[x][i].first,x,R);
        else if(dfn[v[x][i].first]<dfn[x]){
            is_ok[R]&=LB[R].Insert(dis[x]^dis[v[x][i].first]^v[x][i].second);
        }
    }
}
const int mod=1e9+7;
void Add(int &x,int y){x+=y;if(x>=mod) x-=mod;}
int main(){
    dfs_linear_base(Linear_Base());
    for(int i=1;i<=lb_cnt;i++){
        for(int j=1;j<=lb_cnt;j++){
            Linear_Base L=mp_inv[i];
            bool tag=1;
            for(int k=0;k<5;k++) if(mp_inv[j].val[k]) tag&=L.Insert(mp_inv[j].val[k]);
            if(tag) Merge[i][j]=mp[Hash_Function(L)];
        }
    }
    scanf("%d %d",&n,&m);
    for(int i=1,x,y,z;i<=m;i++){
        scanf("%d %d %d",&x,&y,&z);
        if(y!=1) v[x].push_back(make_pair(y,z));
        if(x!=1) v[y].push_back(make_pair(x,z));
    }
    for(int i=1;i<=n;i++) reverse(v[i].begin(),v[i].end());
    for(int i=0;i<v[1].size();i++){
        if(!rt[v[1][i].first]){
            is_ok[v[1][i].first]=1;
            dfs(v[1][i].first,0,v[1][i].first);
            len[v[1][i].first]=v[1][i].second;
        }
        else{
            for(int j=0;j<v[v[1][i].first].size();j++){
                if(v[v[1][i].first][j].first==rt[v[1][i].first]){
                    len[rt[v[1][i].first]]^=v[1][i].second^v[v[1][i].first][j].second;
                    ltk[rt[v[1][i].first]]=1;
                }
            }
        }
    }
    f[0][1]=1;
    for(int i=0;i<v[1].size();i++){
        memcpy(f[i+1],f[i],sizeof(f[i]));
        if(rt[v[1][i].first]!=v[1][i].first||!is_ok[v[1][i].first]) continue;
        if(!ltk[v[1][i].first]){
            int now=mp[Hash_Function(LB[v[1][i].first])];
            for(int j=1;j<=lb_cnt;j++) Add(f[i+1][Merge[now][j]],f[i][j]);
        }
        else{
            int now=mp[Hash_Function(LB[v[1][i].first])];
            for(int j=1;j<=lb_cnt;j++) Add(f[i+1][Merge[now][j]],f[i][j]*2%mod);
            Linear_Base L=LB[v[1][i].first];
            if(L.Insert(len[v[1][i].first])){
                now=mp[Hash_Function(L)];
                for(int j=1;j<=lb_cnt;j++) Add(f[i+1][Merge[now][j]],f[i][j]);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=lb_cnt;i++) ans=(ans+f[v[1].size()][i])%mod;
    printf("%d",ans);
    return 0;
}