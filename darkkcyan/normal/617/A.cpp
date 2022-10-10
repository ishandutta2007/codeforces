#include <bits/stdc++.h>

using namespace std;

#define debug(msg)
//#define debug(msg) cerr << __FILE__ << ':' << __LINE__ << " => " << msg << endl

#define to(i, a, b, s) (i = a; i < b; i += s)
#define downto(i, a, b, s) (i = b - 1; i >= a; i -= s)
#define all(v) v.begin(), v.end()

#define MP make_pair
#define PB push_back
#define endl '\n'

typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int uint64;

const double PI = 3.141592653589793238463;

int main (void) {
    ios_base::sync_with_stdio(0);
    int32 i, f, g;  // count variable

    cin >> i;
    cout << (i / 5 + (i % 5 != 0)) << endl;

    return 0;
}