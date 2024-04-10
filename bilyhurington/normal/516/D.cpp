/*
 * @Author: BilyHurington
 * @Date: 2020-10-10 13:25:40
 * @LastEditors: BilyHurington
 * @LastEditTime: 2020-10-10 14:07:47
 */
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,q;ll f[100010];
vector<pair<int,int> > T[100010];
void calc1(int x,int fa){
    for(int i=0;i<T[x].size();i++){
        if(T[x][i].first==fa) continue;
        calc1(T[x][i].first,x);
        f[x]=max(f[x],f[T[x][i].first]+T[x][i].second);
    }
}
void calc2(int x,int fa,ll max_dis=0){
    f[x]=max(f[x],max_dis);
    if(T[x].size()-(fa>0)==0) return;
    if(T[x].size()-(fa>0)==1){
        for(int i=0;i<T[x].size();i++){
            if(T[x][i].first==fa) continue;
            calc2(T[x][i].first,x,max_dis+T[x][i].second);
        }
        return;
    }
    priority_queue<ll> q;
    for(int i=0;i<T[x].size();i++){
        if(T[x][i].first==fa) continue;
        q.push(f[T[x][i].first]+T[x][i].second);
    }
    for(int i=0;i<T[x].size();i++){
        if(T[x][i].first==fa) continue;
        ll tmp=max_dis;
        if(q.top()==f[T[x][i].first]+T[x][i].second){
            ll t=f[T[x][i].first]+T[x][i].second;
            q.pop();tmp=max(tmp,q.top());q.push(t);
        }
        else tmp=max(tmp,q.top());
        calc2(T[x][i].first,x,tmp+T[x][i].second);
    }
}
int rt,id[100010],fa[100010];
bool cmp(int x,int y){return f[x]>f[y];}
void dfs(int x,int F){
    fa[x]=F;
    for(int i=0;i<T[x].size();i++){
        if(T[x][i].first==F) continue;
        dfs(T[x][i].first,x);
    }
}
struct Union_Set{
    vector<int> Fa,Siz;
    void Init(int N){
        Fa.resize(N+1);Siz.resize(N+1);
        for(int i=1;i<=N;i++) Fa[i]=i,Siz[i]=1;
    }
    int Find(int x){return Fa[x]==x?x:Fa[x]=Find(Fa[x]);}
    void Link(int x,int y){
        int fx=Find(x),fy=Find(y);
        if(x==y) return;
        if(Siz[fx]>Siz[fy]) swap(fx,fy);
        Fa[fx]=fy;Siz[fy]+=Siz[fx];
    }
}U;
int main(){
    scanf("%d",&n);
    for(int i=1,x,y,z;i<n;i++){
        scanf("%d %d %d",&x,&y,&z);
        T[x].push_back(make_pair(y,z));
        T[y].push_back(make_pair(x,z));
    }
    calc1(1,0);calc2(1,0);
    // for(int i=1;i<=n;i++) printf("%lld ",f[i]);
    for(int i=1;i<=n;i++) id[i]=i;
    sort(id+1,id+n+1,cmp);
    rt=id[n];dfs(rt,0);//printf("%d\n",rt);
    // for(int i=1;i<=n;i++) printf("%d\n",fa[i]);
    scanf("%d",&q);ll x;
    while(q--){
        scanf("%lld",&x);U.Init(n);
        int ans=0;
        for(int i=1,j=1;i<=n;i++){
            while(j<=n&&f[id[j]]>f[id[i]]+x) U.Siz[U.Find(id[j])]--,j++;
            ans=max(ans,U.Siz[U.Find(id[i])]);
            U.Link(id[i],fa[id[i]]);
        }
        printf("%d\n",ans);
    }
    return 0;
}