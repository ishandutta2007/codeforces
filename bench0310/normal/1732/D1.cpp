#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    set<ll> s={0};
    map<ll,int> m;
    while(q--)
    {
        char c;
        ll k;
        cin >> c >> k;
        if(c=='+') s.insert(k);
        else
        {
            while(s.contains(m[k]*k)) m[k]++;
            cout << m[k]*k << "\n";
        }
    }
    return 0;
}