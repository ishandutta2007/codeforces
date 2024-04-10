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
        if(popcount(uint64_t(n))==1) cout << "-1\n";
        else
        {
            int c=0;
            ll x=n;
            ll p=2;
            while((x%2)==0)
            {
                c++;
                x/=2;
                p*=2;
            }
            cout << min(p,x) << "\n";
        }
    }
    return 0;
}