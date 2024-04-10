#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<ll> c(32,0);
        for(int i=0;i<n;i++)
        {
            int a;
            cin >> a;
            c[__builtin_clz(a)]++;
        }
        ll res=0;
        for(int i=0;i<=31;i++) res+=(c[i]*(c[i]-1)/2);
        cout << res << "\n";
    }
    return 0;
}