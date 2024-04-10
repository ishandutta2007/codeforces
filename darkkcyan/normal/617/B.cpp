#include <bits/stdc++.h>

using namespace std;

#define debug(msg)
//#define debug(msg) cerr << __FILE__ << ':' << __LINE__ << " => " << msg << endl

#define to(i, a, b, s) (i = a; i < b; i += s)
#define downto(i, a, b, s) (i = b - 1; i >= a; i -= s)
#define all(v) v.begin(), v.end()

#define MP make_pair
#define PB push_back

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;

const double PI = 3.141592653589793238463;

int main (void) {
    ios_base::sync_with_stdio(0);
    int i, f, g;  // count variable

    int n;
    cin >> n;
    int64 result = 0;
    int count = 0;
    for to(i, 0, n, 1) {
        int a;
        cin >> a;
        if (a == 1) {
            if (result == 0) result = 1;
            else result *= count;
            count = 0;
        }
        ++count;
    }
    cout << result;

    return 0;
}