#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    cout << n / 2 << "\n";

    if(n % 2)
    {
        cout << "3 ";
        n -= 3;
    }

    while(n)
    {
        cout << "2 ";
        n -= 2;
    }
}