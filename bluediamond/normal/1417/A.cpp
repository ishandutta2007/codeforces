#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);


    int t;
    cin >> t;
    while (t--)
    {
        int n, k, sol = 0;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (i && a[i] < a[0])
            {
                swap(a[0], a[i]);
            }
        }
        for (int i = 1; i < n; i++)
        {
            sol += (k - a[i]) / a[0];
        }
        cout << sol << "\n";
    }
}