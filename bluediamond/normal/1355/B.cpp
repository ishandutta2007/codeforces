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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int i = 0, sol = 0;
        while (i < n)
        {
            int j = i;
            while (j < n && j - i + 1 < a[j])
            {
                j++;
            }
            if (j < n)
            {
                sol++;
            }
            i = j + 1;
        }
        cout << sol << "\n";
    }

}