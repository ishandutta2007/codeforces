#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, a[100005], used[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int x = n;

    for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            used[a[i]]++;

            while(used[x])
            {
                cout << x << ' ';
                x--;
            }

            cout << "\n";
        }
}