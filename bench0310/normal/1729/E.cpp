#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll now=0;
    int x=2;
    auto out=[&](ll n)
    {
        cout << "! " << n << endl;
        exit(0);
    };
    for(int i=1;i<=25;i++)
    {
        cout << "? " << 1 << " " << x << endl;
        ll a;
        cin >> a;
        cout << "? " << x << " " << 1 << endl;
        ll b;
        cin >> b;
        if(a==-1) out(x-1);
        if(a!=b) out(a+b);
        now=2*a;
        x++;
    }
    out(now);
    return 0;
}