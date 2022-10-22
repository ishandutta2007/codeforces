#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector <int> a = {1200, 1400, 1600, 1900, 2100, 2300, 2400, 2600, 3000};

    int x;
    cin >> x;

    int i = 0;

    while(a[i] <= x)
        i++;

    cout << a[i];
}