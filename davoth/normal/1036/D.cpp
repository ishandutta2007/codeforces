#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
#define F first
#define S second
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
const int N = 2e5 + 10;
map<ll,bool> M;
int main() {
    fast_io;
    ll n;
    cin >> n;
    ll a[n];
    for(int i=0; i<n; i++) cin >> a[i];
    ll m;
    cin >> m;
    ll b[m];
    for(int i=0; i<m; i++) cin >> b[i];
    ll Sa[n],Sb[m];
    Sa[0]=a[0];
    Sb[0]=b[0];
    ll ans=0;
    for(int i=1; i<n; i++) Sa[i]=Sa[i-1]+a[i];
    for(int i=1; i<m; i++) Sb[i]=Sb[i-1]+b[i];
    for(int i=0; i<n; i++) M[Sa[i]]=true;
    for(int i=0; i<m; i++) if(M[Sb[i]]) ans++;
    if(Sa[n-1]==Sb[m-1]) cout << ans;
    else cout << -1;
    return 0;
}