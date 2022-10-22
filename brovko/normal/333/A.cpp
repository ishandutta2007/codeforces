#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define f first
#define s second
#define pb push_back

using namespace std;
using li = long long;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    li n;
    cin >> n;

    while(n % 3 == 0)
        n /= 3;

    cout << n / 3 + 1;
}