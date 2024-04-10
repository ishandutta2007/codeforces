#include<bits/stdc++.h>
using namespace std;
struct Line{
    long long k,b;
    Line(long long K=0,long long B=1e18){k=K;b=B;}
    long long value(long long x){return x*k+b;}
}L[100010];
struct Node{
    int ls,rs,id;
}N[3000010];int Node_tot;
int n,a[100010],b[100010],rt[100010];
long long f[100010];
vector<int> v[100010];
void Push(int &k,int l,int r,int x){
    if(!k){k=++Node_tot,N[k].id=x;return;}
    if(L[N[k].id].value(l)<L[x].value(l)&&L[N[k].id].value(r)<L[x].value(r)) return;
    if(L[N[k].id].value(l)>=L[x].value(l)&&L[N[k].id].value(r)>=L[x].value(r)){N[k].id=x;return;}
    int mid=(l+r)>>1;
    if(L[x].k<L[N[k].id].k){
        if(L[x].value(mid)>L[N[k].id].value(mid)) Push(N[k].rs,mid+1,r,x);
        else Push(N[k].ls,l,mid,N[k].id),N[k].id=x;
    }
    else{
        if(L[x].value(mid)>L[N[k].id].value(mid)) Push(N[k].ls,l,mid,x);
        else Push(N[k].rs,mid+1,r,N[k].id),N[k].id=x;
    }
}
long long Query(int k,int l,int r,int x){
    if(!k) return 1e18;
    if(l==r) return L[N[k].id].value(x);
    int mid=(l+r)>>1;
    if(x<=mid) return min(Query(N[k].ls,l,mid,x),L[N[k].id].value(x));
    else return min(Query(N[k].rs,mid+1,r,x),L[N[k].id].value(x));
}
int Merge(int k1,int k2,int l,int r){
    if(!k1||!k2) return k1|k2;
    int mid=(l+r)>>1;
    if(l==r) return L[N[k1].id].value(mid)>L[N[k2].id].value(mid)?k2:k1;
    N[k1].ls=Merge(N[k1].ls,N[k2].ls,l,mid);
    N[k1].rs=Merge(N[k1].rs,N[k2].rs,mid+1,r);
    Push(k1,l,r,N[k2].id);
    return k1;
}
void dfs(int x,int fa){
    for(int i=0;i<v[x].size();i++){
        if(v[x][i]==fa){v[x].erase(v[x].begin()+i);break;}
    }
    if(!v[x].size()){L[x]=Line(b[x],0);Push(rt[x],-100000,100000,x);return;}
    for(int i=0;i<v[x].size();i++){
        dfs(v[x][i],x);
        rt[x]=Merge(rt[x],rt[v[x][i]],-100000,100000);
    }
    f[x]=Query(rt[x],-100000,100000,a[x]);
    L[x]=Line(b[x],f[x]);
    Push(rt[x],-100000,100000,x);
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) scanf("%d",&b[i]);
    for(int i=1,x,y;i<n;i++){
        scanf("%d %d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++) printf("%lld ",f[i]);
    return 0;
}