#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, x, used[1000005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> x;

    used[x] = 1;
    int y = 0;

    vector <int> v;

    for(int i = 1; i < (1ll << n); i++)
        if(used[i] == 0)
        {
            used[i ^ x] = 1;
            v.pb(y ^ i);
            y = i;
        }

    cout << v.size() << "\n";

    for(auto to:v)
        cout << to << ' ';
}