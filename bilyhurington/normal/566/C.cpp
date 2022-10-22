/*
 * @Author: BilyHurington
 * @Date: 2020-08-10 17:03:17
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-08-10 20:13:13
 */
#include<bits/stdc++.h>
using namespace std;
int n,val[200010],sz[200010],max_siz[200010],rt;
vector<pair<int,int> > v[200010];
bool vis[200010];
void calc_sz(int x,int fa){
    sz[x]=1;
    for(int i=0;i<v[x].size();i++){
        if(v[x][i].first==fa||vis[v[x][i].first]) continue;
        calc_sz(v[x][i].first,x);
        sz[x]+=sz[v[x][i].first];
    }
}
void find_rt(int x,int fa,int S){
    max_siz[x]=S-sz[x];
    for(int i=0;i<v[x].size();i++){
        if(v[x][i].first==fa||vis[v[x][i].first]) continue;
        find_rt(v[x][i].first,x,S);
        max_siz[x]=max(max_siz[x],sz[v[x][i].first]);
    }
    if(max_siz[x]<=S/2) rt=x;
}
int Ans;
double Ans_val=1e50,V[200010],sum_val;
double calc_der(int x,int fa,int dep){
    sum_val+=pow(dep,1.5)*val[x];
    double sum=pow(dep,0.5)*1.5*val[x];
    for(int i=0;i<v[x].size();i++){
        if(v[x][i].first==fa) continue;
        sum+=calc_der(v[x][i].first,x,dep+v[x][i].second);
    }
    return sum;
}
void solve(int x,int S){
    calc_sz(x,0);find_rt(x,0,S);x=rt;vis[x]=1;
    double sum=0;sum_val=0;
    for(int i=0;i<v[x].size();i++){
        V[v[x][i].first]=calc_der(v[x][i].first,x,v[x][i].second);
        sum+=V[v[x][i].first];
    }
    if(sum_val<Ans_val) Ans_val=sum_val,Ans=x;
    calc_sz(x,0);
    if(sz[x]==1) return;
    for(int i=0;i<v[x].size();i++){
        if(vis[v[x][i].first]) continue;
        if(sum<V[v[x][i].first]*2){
            solve(v[x][i].first,sz[v[x][i].first]);
            break;
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&val[i]);
    for(int i=1,x,y,z;i<n;i++){
        scanf("%d %d %d",&x,&y,&z);
        v[x].push_back(make_pair(y,z));
        v[y].push_back(make_pair(x,z));
    }
    solve(1,n);
    printf("%d %.10lf\n",Ans,Ans_val);
    return 0;
}
// 10
// 8 100 62 38 26 51 26 23 77 32
// 6 8 29
// 4 1 82
// 7 8 66
// 7 10 67
// 8 9 98
// 6 1 14
// 1 5 48
// 3 1 58
// 2 9 90