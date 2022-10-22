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

    sort(a, a + n);

    cout << (n - 1) / 2 << "\n";

    int l = 0, r = n - 1;

    for(int i = 0; i < n; i++)
    {
        if(i % 2 == 0)
        {
            cout << a[r] << ' ';
            r--;
        }
        else
        {
            cout << a[l] << ' ';
            l++;
        }
    }
}