/*
 * @Author: BilyHurington
 * @Date: 2020-09-03 13:04:25
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-09-03 13:57:53
 */
#include<bits/stdc++.h>
using namespace std;
struct state{
    int cnt[5];
    state(){memset(cnt,0,sizeof(cnt));}
};
int Hash(state S){int ans=0;for(int i=0;i<=4;i++) ans=ans*9+S.cnt[i];return ans;}
state Unhash(int x){state ans;for(int i=4;i>=0;i--) ans.cnt[i]=x%9,x/=9;return ans;}
int sta_id[100010],sta_tot;state sta_mp[100010];
void dfs(state S,int x=0,int sum=8){
    if(x==4){
        S.cnt[x]=sum;
        sta_id[Hash(S)]=++sta_tot;
        sta_mp[sta_tot]=S;
        return;
    }
    for(int i=sum;i>=0;i--){
        S.cnt[x]=i;
        dfs(S,x+1,sum-i);
    }
}
int bg[250010],to[40000010],nxt[40000010],ed_tot;
void add_edge(int x,int y){
    to[++ed_tot]=y;
    nxt[ed_tot]=bg[x];
    bg[x]=ed_tot;
}
int num(state S1,state S2){return (sta_id[Hash(S1)]-1)*sta_tot+sta_id[Hash(S2)]-1;}
void Init(int *a,state S){
    int tot=0;
    for(int i=0;i<=4;i++){
        while(S.cnt[i]>0) S.cnt[i]--,a[tot++]=i;
    }
}
queue<int> que;
int ans[250010],in[250010];//012
int main(){
    dfs(state());
    // for(int i=1;i<=sta_tot;i++){
    //     for(int j=0;j<5;j++) printf("%d ",sta_mp[i].cnt[j]);printf("\n");
    // }
    int P[8],Q[8];
    for(int i=1;i<=sta_tot;i++){
        for(int j=1;j<=sta_tot;j++){
            state S1=sta_mp[i],S2=sta_mp[j],S3;
            Init(P,S1);Init(Q,S2);
            int x=num(S1,S2);
            for(int p=S1.cnt[0];p<8;p++){
                for(int q=S2.cnt[0];q<8;q++){
                    S3=S1;
                    S3.cnt[P[p]]--;
                    S3.cnt[(P[p]+Q[q])%5]++;
                    // for(int k=0;k<=4;k++) printf("%d ",S1.cnt[k]);printf("\n");
                    // for(int k=0;k<=4;k++) printf("%d ",S2.cnt[k]);printf("\n");
                    // for(int k=0;k<=4;k++) printf("%d ",S3.cnt[k]);printf("\n");
                    int y=num(S2,S3);
                    add_edge(y,x);in[x]++;
                    // printf("%d %d\n",y,x);
                }
            }
        }
        // printf("%d\n",i);
    }
    for(int i=2;i<=sta_tot;i++) ans[num(sta_mp[i],sta_mp[1])]=1,que.push(num(sta_mp[i],sta_mp[1]));
    while(que.size()){
        int x=que.front();que.pop();
        // printf("%d\n",x);
        for(int i=bg[x];i;i=nxt[i]){
            if(ans[to[i]]) continue;
            if(ans[x]==1){ans[to[i]]=2;que.push(to[i]);}
            if(ans[x]==2){
                in[to[i]]--;
                if(!in[to[i]]) ans[to[i]]=1,que.push(to[i]);
            }
        }
    }
    int T,pd;scanf("%d",&T);
    while(T--){
        state S1,S2;scanf("%d",&pd);
        for(int i=0,x;i<8;i++) scanf("%d",&x),S1.cnt[x]++;
        for(int i=0,x;i<8;i++) scanf("%d",&x),S2.cnt[x]++;
        if(pd) swap(S1,S2);
        int x=ans[num(S1,S2)];
        if(!x) puts("Deal");
        else if((pd&&x==1)||(!pd&&x==2)) puts("Alice");
        else puts("Bob");
    }
    return 0;
}