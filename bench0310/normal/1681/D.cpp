#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    ll x;
    cin >> n >> x;
    map<ll,int> d;
    queue<ll> q;
    auto add=[&](ll y,int nd)
    {
        if(!d.contains(y))
        {
            d[y]=nd;
            q.push(y);
        }
    };
    add(x,0);
    while(!q.empty())
    {
        ll a=q.front();
        q.pop();
        string s=to_string(a);
        int t=d[a];
        if((int)s.size()>=n)
        {
            cout << t << "\n";
            exit(0);
        }
        for(char c:s) add(a*(c-'0'),t+1);
    }
    cout << "-1\n";
    return 0;
}