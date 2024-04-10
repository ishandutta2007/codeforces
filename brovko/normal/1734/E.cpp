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

    int n;
    cin >> n;

    vector <int> b(n);

    for(int i = 0; i < n; i++)
        cin >> b[i];

    for(int i = 0; i < n; i++, cout << "\n")
    {
        for(int j = 0; j < n; j++)
            cout << (b[i] + i * (i - j + n)) % n << ' ';
    }
}