#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <bitset>
#include <map>

#define ll long long
#define int ll
#define all(X) X.begin(), X.end()
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#pragma GCC optimize("unroll-loops" , "Ofast")
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <bitset>
#include <map>
#include <set>
#define ll long long
#define int ll
#define all(X) X.begin(), X.end()
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#pragma GCC optimize("unroll-loops" , "Ofast")
using namespace std;
int a[200005];
ll p[200005];
map<ll , vector<pair<int, int>>> m;
bool cmp(pair<int, int> a , pair<int, int> b)
{
    return a.second < b.second;
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        p[i + 1] = p[i] + a[i];
    }
    for(int i = 0; i <= n; i++)
    {
        for(int j = i + 1; j <= n; j++)
        {
            m[p[j] - p[i]].pb(mp(i + 1 , j));
        }
    }
    int res = 0;
    vector<pair<int, int>> xr;
    for(auto &x : m)
    {
        sort(x.second.begin(), x.second.end(), cmp);
        auto p = x.second;
        ll mx = -1e18;
//        cout << x.first << " ";
//        for(auto i : p) cout << "[" << i.first << " " << i.second << "] ";
//        cout << "\n";
        int ans = 0;
        vector<pair<int, int>> cur;
        for(int i = 0; i < p.size(); i++)
        {
            if(p[i].first > mx)
            {
                ans++;
                mx = max(mx , p[i].second);
                cur.pb(p[i]);
            }
        }
        if(ans >= res)
        {
            res = ans;
            xr = cur;
        }
        
    }
    
    cout << res << "\n";
    for(auto i : xr)
    {
        cout << i.first  << " " << i.second << "\n";
    }
}