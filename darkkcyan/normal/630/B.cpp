#include <bits/stdc++.h>

using namespace std;

#ifdef DEBUG_MODE
#define debug(msg) cerr << __FILE__ << ':' << __LINE__ << " => " << msg << endl
#else
#define debug(msg)
#endif

#define repeat(count, time) for (count = 0; count < time; ++count)
#define r_repeat(count, time) for (count = time - 1; count >= 0; --count)
#define loop(i, a, b, s) for (i = a; i <= b; i += s)          // note the <=
#define r_loop(i, a, b, s) for (i = a; i >= b; i -= s)      // note the >=
#define all(v) (v).begin(), (v).end()

#define mp make_pair
#define pb push_back

#define fi first
#define se second

typedef unsigned int uint;
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;

const double PI = 3.141592653589793238463;

int main (void) {
    ios_base::sync_with_stdio(0);
    int i, f, g;  // count variable

    int n, t;

    cin >> n >> t;
    cout << ((double)n * pow(1.000000011, t));

    return 0;
}