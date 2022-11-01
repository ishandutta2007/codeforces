#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,R,r;
    cin >> n >> R >> r;
    auto out=[&](bool ok)
    {
        if(ok) cout << "YES\n";
        else cout << "NO\n";
        exit(0);
    };
    if(r>R) out(0);
    if(2*r>R) out(n==1);
    auto sq=[&](double a)->double{return (a*a);};
    double a=acos((2*sq(R-r)-sq(2*r))/(2*sq(R-r)));
    double pi=acos(-1);
    const double eps=1e-9;
    out(n*a-eps<=2*pi);
    return 0;
}