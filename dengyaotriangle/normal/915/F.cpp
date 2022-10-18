#include<bits/stdc++.h>

using namespace std;

const int maxn=1000006;

struct ed{
    int u,v;
    long long w;
};
int dsu[maxn],szu[maxn];
long long v[maxn];
ed e[maxn];

int grt(int u){
    if(dsu[u]==u) return u;
    dsu[u]=grt(dsu[u]);
    return dsu[u];
}

void mrg(int u,int v){
    u=grt(u);v=grt(v);
    if(szu[u]>szu[v]) swap(u,v);
    szu[v]+=szu[u];
    dsu[u]=v;
}

bool ism(int u,int v){
    return grt(u)==grt(v);
}

int gsz(int u){
    return szu[grt(u)];
}

int n;

long long f(long long a,long long b,bool c){
    return (c?(max(a,b)):(min(a,b)));
}

bool cmp(ed a,ed b){
    return a.w<b.w;
}
long long calc(bool t){
    long long ans=0;
    for(int i=1;i<n;i++) e[i].w=f(v[e[i].u],v[e[i].v],t);
    sort(e+1,e+n,cmp);
    if(!t) reverse(e+1,e+n);
    for(int i=1;i<=n;i++){
        dsu[i]=i;szu[i]=1;
    }
    for(int i=1;i<n;i++){
        long long s1=gsz(e[i].u),s2=gsz(e[i].v);
        mrg(e[i].u,e[i].v);
        ans+=s1*s2*e[i].w;
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>v[i];
    for(int i=1;i<n;i++)cin>>e[i].u>>e[i].v;
    cout<<calc(1)-calc(0);
    return 0;
}