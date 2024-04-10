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
        if(n&1)
        {
            cout << "-1\n";
            continue;
        }
        vector<int> v;
        int c=0;
        for(ll i=58;i>=1;i--)
        {
            ll a=(1ll<<(i+1))-2;
            while(n>=a)
            {
                v.push_back(i);
                c+=i;
                n-=a;
            }
        }
        cout << c << "\n";
        for(int sz:v)
        {
            cout << "1 ";
            for(int i=0;i<sz-1;i++) cout << "0 ";
        }
        cout << "\n";
    }
    return 0;
}