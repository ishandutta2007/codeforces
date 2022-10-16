#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define Max(a,b) (a>b?a:b)
#define Min(a,b) (a<b?a:b)
#define next Cry_For_theMoon
#define il inline
#define pb(x) push_back(x)
#define is(x) insert(x)
#define sit set<int>::iterator
#define mapit map<int,int>::iterator
#define pi pair<int,int>
#define ppi pair<int,pi>
#define pp pair<pi,pi>
#define fr first
#define se second
#define vit vector<int>::iterator
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef double db;
using namespace std;
const int MAXN=1e5+10;
int T,n;
ll a[MAXN];
void solve(){
    cin>>n;
    rep(i,1,n)cin>>a[i];
    ll ans=0;
    int flag=1;rep(i,2,n-1)if(a[i]!=1)flag=0;
    if(flag){cout<<-1<<endl;return;}
    int cnt=0;rep(i,2,n-1)if(odd(a[i]))cnt++;
    if(cnt==1 && n==3){cout<<-1<<endl;return;}
    rep(i,2,n-1)ans+=a[i];
    ans-=cnt;ans/=2;
    ans+=cnt;
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>T;
    while(T--)solve();

    return 0;
}