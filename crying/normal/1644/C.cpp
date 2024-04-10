#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
const int MAXN=5010,INF=1.1e9;
int T,n,x,a[MAXN],s[MAXN];
int val[MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--){
        cin>>n>>x;
        rep(i,1,n)cin>>a[i],s[i]=s[i-1]+a[i];
        rep(i,1,n)val[i]=-INF;val[0]=0;
        rep(i,1,n)rep(j,i,n){
            val[j-i+1]=max(val[j-i+1],s[j]-s[i-1]);
        }
        per(j,n-1,0)val[j]=max(val[j],val[j+1]);
        rep(j,0,n)val[j]=val[j]+x*j;
        rep(j,1,n)val[j]=max(val[j],val[j-1]);
        rep(j,0,n)cout<<val[j]<<' ';cout<<endl;
    }

    return 0;
}