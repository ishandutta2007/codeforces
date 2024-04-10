#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    double a,b,c,d;
    cin >> a >> b >> c >> d;
    cout << fixed << setprecision(12) << a/(b*(1-(1-a/b)*(1-c/d))) << "\n";
    return 0;
}