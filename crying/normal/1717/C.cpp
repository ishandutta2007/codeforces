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
const int MAXN=2e5+10;
int t,n,a[MAXN],b[MAXN];
int f[MAXN],pre[MAXN],suf[MAXN];
void solve(){
    cin>>n;
    rep(i,1,n)cin>>a[i];
    rep(i,1,n)cin>>b[i];
    int minb=b[1];rep(i,2,n)minb=min(minb,b[i]);
    rep(i,1,n)a[i]=max(a[i],minb);
    a[n+1]=a[1];b[n+1]=b[1];
    rep(i,1,n){
        if(a[i]>b[i] || (a[i]<b[i] && b[i]>b[i+1]+1))f[i]=0;
        else f[i]=1;
    }
    pre[0]=1;rep(i,1,n)pre[i]=pre[i-1]&f[i];
    suf[n+1]=1;per(i,n,1)suf[i]=suf[i+1]&f[i];

    rep(i,1,n)if(b[i]==minb && a[i]<=b[i] && pre[i-1] && suf[i+1]){
        cout<<"YES\n";
        return;
    }
    cout<<"NO\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--)solve();

    return 0;
}