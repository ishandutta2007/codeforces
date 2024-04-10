#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back
#define vi vector <int>

using namespace std;

int n, a[100005], b[1000005], L[1000005], R[1000005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    int k = 0;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        b[a[i]]++;
        k = max(k, b[a[i]]);

        if(L[a[i]] == 0)
            L[a[i]] = i + 1;

        R[a[i]] = i + 1;
    }

    int l = 0, r = 1e9;

    for(int i = 0; i < n; i++)
    {
        if(b[a[i]] == k && R[a[i]] - L[a[i]] < r - l)
        {
            l = L[a[i]];
            r = R[a[i]];
        }
    }

    cout << l << ' ' << r;
}