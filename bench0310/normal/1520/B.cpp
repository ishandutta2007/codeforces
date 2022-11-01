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
        int res=0;
        for(int i=1;i<=9;i++)
        {
            ll a=i;
            while(a<=n)
            {
                res++;
                a=(10*a+i);
            }
        }
        cout << res << "\n";
    }
    return 0;
}