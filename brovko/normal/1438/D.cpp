#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define y1 jgpjewgjepg

using namespace std;

int n, a[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    int x = 0;

    for(int i = 0; i < n; i++)
        x ^= a[i];

    if(n % 2 == 0 && x != 0)
    {
        cout << "NO";
        return 0;
    }

    cout << "YES\n";

    cout << (n - 1) / 2 * 2 << "\n";

    for(int i = 0; i < n - 2; i += 2)
        cout << i + 1 << ' ' << i + 2 << ' ' << i + 3 << "\n";

    for(int i = (n - 3) / 2 * 2; i >= 0; i -= 2)
        cout << i + 1 << ' ' << i + 2 << ' ' << i + 3 << "\n";
}