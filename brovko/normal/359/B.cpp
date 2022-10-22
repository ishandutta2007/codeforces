#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, k;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;

    for(int i = 2; i <= 2 * k; i += 2)
        cout << i << ' ' << i - 1 << ' ';

    for(int i = 2 * k + 1; i <= 2 * n; i += 2)
        cout << i << ' ' << i + 1 << ' ';
}