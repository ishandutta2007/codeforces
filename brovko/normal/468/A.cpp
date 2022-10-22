#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    if(n <= 3)
    {
        cout << "NO";
        return 0;
    }

    cout << "YES\n";
    
    for(int i = n; i >= 6; i -= 2)
    {
        cout << i << " - " << i - 1 << " = 1\n";
        cout << "1 * 1 = 1\n";
    }

    if(n % 2 == 0)
        cout << "1 * 2 = 2\n2 * 3 = 6\n6 * 4 = 24";
    else cout << "5 * 3 = 15\n4 * 2 = 8\n15 + 8 = 23\n23 + 1 = 24";
}