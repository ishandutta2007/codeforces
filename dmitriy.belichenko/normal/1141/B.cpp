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


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(3 * n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i + n] = a[i];
        a[i + n + n] = a[i];
    }
    int ans = 0;
    for(int i = 0; i < n * 3; i++)
    {
        int j = i;
        while (a[j] == 1 && j < n * 3)
        {
            j++;
        }
        ans = max(ans , j - i);
         i = j;
    }
    cout << ans << "\n";
    return 0;
}