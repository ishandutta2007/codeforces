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
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++)
    {
        cin >> a[i];
        if(a[i] == 0)
        {
            cout << -1 << "\n";
            return 0;
        }
    }
    p[0] = 0;
    ll mn = 1e18;

    for(int i = 0; i < n - 1; i++)
    {
        p[i + 1] = p[i] + a[i];
    }
    for(int i = 0; i <= n - 1; i ++)
        mn = min(mn , p[i]);
    mn = 1 - mn;
    set<int> x;
    for(int i = 0; i < n; i++)
    {
        x.insert(p[i]);
    }
    if(x.size() != n)
    {
        cout << -1;
        return 0;
    }
    for(int i = 0; i < n; i++)
    {
         p[i] += mn;
         if(p[i] > n)
         {
             cout << -1;
             return 0;
         }
    }
    for(int i = 0; i < n; i++)
    {
        cout << p[i] << " ";
    }
    // 3 1 2 4
    return 0;
    //3 1 2
}