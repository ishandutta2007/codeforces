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
        ll x;
        cin >> n >> x;
        multiset<ll> s;
        for(int i=1;i<=n;i++)
        {
            ll a;
            cin >> a;
            s.insert(a);
        }
        int res=0;
        while(!s.empty())
        {
            ll a=(*s.begin());
            s.erase(s.begin());
            if(s.contains(a*x)) s.erase(s.find(a*x));
            else res++;
        }
        cout << res << "\n";
    }
    return 0;
}