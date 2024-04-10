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
        ll n;
        cin >> n;
        ll l=1;
        ll res=0;
        for(int i=1;i<=41;i++)
        {
            res+=(i*(n/l-n/lcm(l,i)));
            l=lcm(l,i);
        }
        const ll mod=1000000007;
        cout << res%mod << "\n";
    }
    return 0;
}