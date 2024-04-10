#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, l, r, t1, t2;
vector <pair <int, int> > v;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> l >> r;
        v.push_back({l, r});
    }

    sort(v.begin(), v.end());

    for(auto to:v)
    {
        if(t1 <= to.first)
        {
            t1 = to.second + 1;
        }
        else if(t2 <= to.first)
        {
            t2 = to.second + 1;
        }
        else
        {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
}