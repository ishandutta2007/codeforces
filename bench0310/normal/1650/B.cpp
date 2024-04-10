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
        ll l,r,a;
        cin >> l >> r >> a;
        auto f=[&](ll x)->ll{return (x/a)+(x%a);};
        ll res=f(r);
        if(r-((r%a)+1)>=l) res=max(res,f(r-((r%a)+1)));
        cout << res << "\n";
    }
    return 0;
}