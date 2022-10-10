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

    int n;
    cin >> n;
    int F[366 + 10] = {0};
    int M[366 + 10] = {0};

    repeat(i, n - 1) {
        char gender;
        int a, b;
        cin >> gender >> a >> b >> ws;
        (gender == 'M' ? M : F)[a - 1]++;
        (gender == 'M' ? M : F)[b]--;
    }

    int mCount = 0;
    int fCount = 0;
    int max = 0;
    repeat(i, 366) {
        mCount += M[i];
        fCount += F[i];
        debug(i << ' ' << M[i] << ' ' << F[i] << ' ' << mCount << ' ' << fCount);
        int t = min(mCount, fCount);
        if (max < 2 * t) {
            max = 2 * t;
            debug(i);
        }
    }

    cout << max << '\n';

    return 0;
}