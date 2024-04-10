#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int t, n, a[100005];
vector <int> v;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    while(t--)
    {
        v.erase(v.begin(), v.end());

        cin >> n;
        for(int i = 0; i < n; i++)
            cin >> a[i];

        a[n] = a[n - 1];

        v.push_back(a[0]);

        for(int i = 1; i < n; i++)
            {
                if(a[i - 1] < a[i] && a[i] >= a[i + 1])
                    v.push_back(a[i]);
                else if(a[i - 1] > a[i] && a[i] <= a[i + 1])
                    v.push_back(a[i]);
            }

        cout << v.size() << "\n";
        for(auto to:v)
            cout << to << ' ';

        cout << "\n";
    }
}