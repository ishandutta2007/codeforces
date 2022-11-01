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
        ll x;
        cin >> x;
        int res=0;
        for(ll i=1;(i*(i+1)/2)<=x;i=2*i+1)
        {
            x-=(i*(i+1)/2);
            res++;
        }
        cout << res << "\n";
    }
    return 0;
}