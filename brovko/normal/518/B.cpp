#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

string s, t;
int k[128], k2[128];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s >> t;

    for(auto x:t)
        k[x]++;

    int a = 0, b = 0;

    for(auto x:s)
        k2[x]++;

    for(int i = 'a'; i <= 'z'; i++)
    {
        int x = min(k[i], k2[i]) + min(k[i - 32], k2[i - 32]);
        int y = min(k[i] + k[i - 32], k2[i] + k2[i - 32]);

        a += x;
        b += y - x;
    }

    cout << a << ' ' << b;
}