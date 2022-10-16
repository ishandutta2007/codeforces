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
int T,n,a[MAXN];
map<int,int>f;
void solve(){
    cin>>n;
    f.clear();
    rep(i,1,n)cin>>a[i],f[a[i]]++;
    int cnt1=0,cnt2=0;
    for(auto p:f)if(p.second==1)cnt1++;else cnt2++;
    int ans=cnt2;
    if(cnt1)cnt1--,ans++;
    ans+=cnt1/2;
    cout<<ans<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)solve();


    return 0;
}