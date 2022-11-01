#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,p;
    cin >> n >> p;
    vector<array<ll,2>> v(n);
    for(int i=0;i<n;i++) cin >> v[i][0] >> v[i][1];
    auto ok=[&](ll a,ll b)->ll{return (b/p)-((a-1)/p);};
    auto bad=[&](ll a,ll b)->ll{return (b-a+1-ok(a,b));};
    double res=0;
    for(int i=0;i<n;i++)
    {
        auto [a,b]=v[i];
        auto [c,d]=v[(i+1)%n];
        res+=(2000*((double)ok(a,b)*ok(c,d)+ok(a,b)*bad(c,d)+bad(a,b)*ok(c,d))/((b-a+1)*(d-c+1)));
    }
    cout << fixed << setprecision(15) << res << "\n";
    return 0;
}