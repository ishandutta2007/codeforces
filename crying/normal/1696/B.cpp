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
const int MAXN=1e5+10;
int T,n,a[MAXN],ans;
void solve(){
    cin>>n;ans=0;
    rep(i,1,n)cin>>a[i];
    rep(i,1,n)if(a[i] && !a[i-1])ans++;
    cout<<min(ans,2)<<endl;
}
int main(){
    cin>>T;
    while(T--)solve();

    return 0;
}