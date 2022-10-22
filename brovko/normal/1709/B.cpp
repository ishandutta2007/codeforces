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
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector <int> a(n);

    for(int i = 0; i < n; i++)
        cin >> a[i];

    vector <li> R(n), L(n);

    for(int i = 1; i < n; i++)
        R[i] = R[i - 1] + max(0, a[i - 1] - a[i]);

    for(int i = n - 2; i >= 0; i--)
        L[i] = L[i + 1] + max(0, a[i + 1] - a[i]);

    while(m--)
    {
        int l, r;
        cin >> l >> r;

        l--;
        r--;

        if(l < r)
            cout << abs(R[r] - R[l]) << "\n";
        else cout << abs(L[l] - L[r]) << "\n";
    }
}