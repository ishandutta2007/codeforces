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
const int MAXN=2e5+100;
int T,n,a[MAXN],b[MAXN];
int d[MAXN];
int f[MAXN];
void solve(){
    cin>>n;
    rep(i,1,n)cin>>a[i];
    rep(i,1,n)cin>>b[i];
    //min
    int cur=0;
    rep(i,1,n){
        while(cur<n && b[cur+1]<a[i])cur++;
        cout<<b[cur+1]-a[i]<<" ";
    }
    cout<<"\n";
    //max
    rep(i,0,n+10)d[i]=f[i]=0;
    rep(i,2,n)d[i]=(a[i]<=b[i-1]);
    per(i,n,1){
        f[i]=(d[i])?(f[i+1]+1):(0);
    }
    rep(i,1,n){
        cout<<b[i+f[i+1]]-a[i]<<" ";
    }
    cout<<"\n";
}
int main(){
    //ios::sync_with_stdio(false);
    cin>>T;while(T--)solve();


    return 0;
}
/*
1
4
1 2 3 4
1 2 3 4
*/