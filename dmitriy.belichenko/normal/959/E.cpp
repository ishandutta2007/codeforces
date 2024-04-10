#include <map>
#include <vector>
#include <deque>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <string>
#include <iostream>
#include <set>
#include <iomanip>
#include <bitset>
#include <random>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define fst first
#define snd second
#define ld long double
#define mt make_tuple
const double PI = acos(-1);
const int N = 200;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const int MAXN = 30;
int n , m;
int a[N][N] , c[N][N];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    long long n;
    cin >> n;
    ll ans = 0;
    ll cost = 1;
    while (n > 1)
    {
        ans += n /2 * cost;
        cost *= 2;
        n = (n + 1) / 2;
    }
    cout << ans << "\n";
}