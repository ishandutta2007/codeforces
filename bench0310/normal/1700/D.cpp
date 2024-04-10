#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> s(n+1,0);
    ll lim=0;
    for(int i=1;i<=n;i++)
    {
        cin >> s[i];
        s[i]+=s[i-1];
        lim=max(lim,(s[i]+i-1)/i);
    }
    int q;
    cin >> q;
    while(q--)
    {
        ll t;
        cin >> t;
        if(t>=lim) cout << (s[n]+t-1)/t << "\n";
        else cout << "-1\n";
    }
    return 0;
}