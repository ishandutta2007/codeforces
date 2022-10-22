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

    int a, b;
    cin >> a >> b;

    int k = 0;

    while(a <= b)
    {
        a *= 3;
        b *= 2;
        k++;
    }

    cout << k;
}