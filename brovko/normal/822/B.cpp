#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, m;
string s, t;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> s >> t;

    int Min = 1e9;
    vector <int> v, ans;

    for(int i = n - 1; i < m; i++)
    {
        int k = 0;
        v.erase(v.begin(), v.end());

        for(int j = 0; j < n; j++)
        {
            if(s[j] != t[j + i - n + 1])
            {
                k++;
                v.push_back(j + 1);
            }
        }

        if(k < Min)
        {
            Min = k;
            swap(ans, v);
        }
    }

    cout << Min << "\n";

    for(auto to:ans)
        cout << to << ' ';
}