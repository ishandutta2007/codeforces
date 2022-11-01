#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,q;
    ll k;
    cin >> n >> q >> k;
    vector<ll> a(n+1,0);
    for(int i=1;i<=n;i++) cin >> a[i];
    while(q--)
    {
        int l,r;
        cin >> l >> r;
        cout << 2*(k-(r-l+1))-(a[l]-1+(k-a[r])) << "\n";
    }
    return 0;
}