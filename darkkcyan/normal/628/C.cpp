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
#include <cmath>

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

char sign(int t) {
    return t > 0 ? 1 : t < 0 ? -1 : 0;
}

bool process(string& s, int ind, int& k) {
    char c = s[ind];
    int m = c - 'a';
    char t = 'a';
    if (m < 'z' - c) {
        m = 'z' - c;
        t = 'z';
    }

    debug(c << t << ' ' << m);

    if (k > m) {
        s[ind] = t;
        k -= m;
        debug(k);
        return false;
    }

    s[ind] = sign(t - c) * k + c;
    debug("over");
    debug(s[ind] << ' ' <<  sign(t - c) * k);
    return true;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    int i, f, g;  // count variable

    int n, k;
    string s;
    cin >> n >> k >> ws >> s;

    bool successFull;
    repeat (i, n - 1) {
        if (successFull = process(s, i, k)) break;
    }

    if (!successFull) {
        cout << -1;
    } else {
        cout << s;
    }

    return 0;
}