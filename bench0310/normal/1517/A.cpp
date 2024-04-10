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
        if((n%2050)==0)
        {
            n/=2050;
            int res=0;
            while(n)
            {
                res+=(n%10);
                n/=10;
            }
            cout << res << "\n";
        }
        else cout << "-1\n";
    }
    return 0;
}