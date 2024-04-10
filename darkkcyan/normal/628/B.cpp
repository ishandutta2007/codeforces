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

bool isDevideBy4(char num[2]) {
    int cnum = (num[0] - '0') * 10 + num[1] - '0';
    return cnum % 4 == 0;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    int i, f, g;  // count variable

    char num[2];
    num[0] = '0';
    int n = 0;
    long long int result = 0;
    while (cin >> num[1]) {
        ++n;
        if ((num[1] - '0') % 4 == 0) {
            ++result;
        }
        if (isDevideBy4(num)) {
            result += n - 1;
        }
        num[0] = num[1];
    }

    cout << result << '\n';

    return 0;
}