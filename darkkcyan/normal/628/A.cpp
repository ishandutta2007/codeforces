#include <iostream>
#include <fstream>
#include <istream>
#include <ostream>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <utility>
#include <string>

using namespace std;

#ifdef DEBUG_MODE
#define debug(msg) cerr << __FILE__ << ':' << __LINE__ << " => " << msg << '\n';
#else
#define debug(msg)
#endif

#define fi first
#define se second
#define pb push_back
#define mp make_pair

#define loop(i, a, b, c) for (i = a; i <= b; i += c)
#define rloop(i, a, b, c) for (i = a; i >= b; i -= c)
#define loop1(i, a, b) loop(i, a, b, 1)
#define rloop1(i, a, b) rloop(i, a, b, 1)
#define repeat(i, n) loop1(i, 0, n)
#define rrepeat(i, n) rloop1(i, n, 0)

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector< vector< int > > vii;

int main(void) {
    ios_base::sync_with_stdio(false);
    long long unsigned int i, f, g;  // count variable

    long long unsigned int n, b, p;
    cin >> n >> b >> p;

    long long unsigned int pp = p * n;
    long long unsigned int bb = 0;

    long long unsigned int t = 1;

    while (n > 1) {
        while (t < n) {t <<= 1;}
        while (t > n) {t >>= 1;}
        debug(t << ' ' << n);
        bb += t / 2 * (2 * b + 1);
        n -= t / 2;
    }

    cout << bb << ' ' << pp << '\n';

    return 0;
}