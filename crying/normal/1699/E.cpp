#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
const int MAXN=1e6+10,MAXM=5e6+10,LIM=5e6,INF=1e9;
int T,n,m,a[MAXN],tag[MAXM];
int f[MAXM],ans;
int bucket[MAXM];
int maxn;
void Add(int v){
    bucket[v]++;
}
void Del(int v){
    bucket[v]--;
}
void Upd(){
    while(!bucket[maxn])maxn--;
}
void solve(){
    cin>>n>>m;
    rep(i,1,m+1)tag[i]=0,f[i]=m+1,bucket[i]=0;
    rep(i,1,n)cin>>a[i],tag[a[i]]=1;
    sort(a+1,a+1+n);
    maxn=0;
    rep(i,1,m)if(tag[i])bucket[f[i]]++,maxn=max(maxn,f[i]);
    ans=INF;
    per(i,a[n],1){
        if(tag[i])Del(f[i]);
        f[i]=i;
        if(tag[i])Add(f[i]);
        Upd();
        if(i>1)rep(j,i,m)if(1ll*i*j>a[n])break;else{
            if(tag[i*j])Del(f[i*j]);
            f[i*j]=min(f[i*j],max(i,f[j]));
            if(tag[i*j])Add(f[i*j]);
            Upd();
        }
        if(maxn>a[n])continue;
        ans=min(ans,maxn-i);
    }
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)solve();

    return 0;
}