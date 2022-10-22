#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int hh, mm, h, d, c, n;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> hh >> mm >> h >> d >> c >> n;
    int x=max(0ll, 1200-hh*60-mm)*d;
    cout << setprecision(20) << min((ld)c*((h+n-1)/n), (h+x+n-1)/n*(ld)0.8*c);
}