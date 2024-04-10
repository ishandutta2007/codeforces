#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int k, n, w;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> k >> n >> w;

    int s = 0;

    for(int i = 1; i <= w; i++)
        s += i * k;

    cout << max(0ll, s - n);
}