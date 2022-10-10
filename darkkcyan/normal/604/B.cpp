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
    int i, f, g;  // count variable

    int n, k;
    cin >> n >> k;

    int arr[n + 1];
    repeat (i, n) {
        cin >> arr[i];
    }
    int max = arr[n - 1];

    if (k >= n) {
        cout << max << '\n';
        return 0;
    }

    while (k * 2 != n) {
        --k;
        --n;
    }

    debug(n << ' ' << k << ' ' << max);

    repeat(i, (n - 1) / 2) {
        if (max < arr[i] + arr[n - 1 - i]) {
            max = arr[i] + arr[n - 1 - i];
        }
        debug(i << ' ' << (n - 1 - i) << ' ' << max << ' ' << arr[i] << ' ' << arr[n - 1 - i])
    }

    cout << max;

    return 0;
}