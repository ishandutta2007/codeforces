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
        ll p,f;
        ll ca,cb;
        ll a,b;
        cin >> p >> f >> ca >> cb >> a >> b;
        if(a>b)
        {
            swap(ca,cb);
            swap(a,b);
        }
        ll x=(p/a)+(f/a);
        if(x<=ca)
        {
            cout << x << "\n";
            continue;
        }
        ll res=0;
        for(int i=0;i<=ca;i++) if(p-i*a>=0&&f-(ca-i)*a>=0) res=max(res,(p-i*a)/b+(f-(ca-i)*a)/b);
        res=min(res,cb);
        cout << ca+res << "\n";
    }
    return 0;
}