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
    int n , m;
    cin >> n >> m;
    int a = 0 , b = 0;
    int c = 0 , d = 0;
    while (m % 2 == 0)
    {
        m /= 2;
        a++;
    }
    while (m % 3 == 0)
    {
        m /= 3;
        b++;
    }
    while (n % 2 == 0) {
        n /= 2;
        c++;
    }
    while (n % 3 == 0) {
        n /= 3;
        d++;
    }
    if(c > a || d > b || n != m) cout << -1;
    else
        cout << (a - c) + (b - d) << "\n";
    return 0;
}