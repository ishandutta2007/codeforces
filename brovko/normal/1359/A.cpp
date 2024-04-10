#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 oidhfdoif

using namespace std;

int t, n, m, k;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> n >> m >> k;
        int c=min(m, n/k);
        m-=c;
        cout << min(c, c-((m+k-2)/(k-1))) << endl;
    }
}