#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef long double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf = 0x3f3f3f3f;

#define PB(x) push_back(x)
#define rep(i,l,r) for (ll i = l,_ = r;i< _;i++)
#define leave(x) do {cout<<#x<<endl;fflush(stdout);return 0;}while (0);
#define untie do{ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);}while (0)

/************* header ******************/

const int maxn=2000+14;
ll n,m,a[maxn],b[maxn],mx[maxn*maxn],x;
ll ans = 0;
void input(){
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<=n;i++)
        a[i]+=a[i-1];
    for(int i=1;i<=m;++i)
        cin>>b[i];
    for (int i=1;i<=m;i++)
        b[i]+=b[i-1];
    cin>>x;
}
void solve(){
    for(int i=1;i<=n;++i){
        for(int j=i;j<=n;++j){
            mx[a[j]-a[i-1]]=max(mx[a[j]-a[i-1]],1LL*(j-i+1));
        }
    }
    
    for(int i=1;i<=a[n];++i){
        mx[i]=max(mx[i-1],mx[i]);
    }

    for(int i=1;i<=m;++i)
        for(int j=i;j<=m;++j) {
            ll tp = x/(b[j] - b[i-1]);
            int tmp=min(tp,a[n]);
            ans=max(ans,1ll*(j-i+1)*mx[tmp]);
        }
    cout << ans<<endl;
}
int main() {
    untie;
    input();
    solve();
    return 0;
}