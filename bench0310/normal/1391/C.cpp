#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    const ll mod=1000000007;
    int n;
    cin >> n;
    ll res=1;
    for(ll i=1;i<=n;i++) res=(res*i)%mod;
    ll p=1;
    for(int i=0;i<n-1;i++) p=(2*p)%mod;
    cout << ((res-p+mod)%mod) << "\n";
    return 0;
}