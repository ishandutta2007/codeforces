#include <algorithm>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iostream>
#include <iterator>
#include <numeric>
#include <utility>

#include <bitset>
#include <complex>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

template<class T>
inline void chkmax(T& x, T y) {
    if (x < y) x = y;
}

template<class T>
inline void chkmin(T& x, T y) {
    if (y < x) x = y;
}

typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define sz(x) int((x).size())
#define bit(x) (1 << (x))

#define MX 
void print(int st, int en) {
    int i, s;
    
    for (i = st; i <= en; i += 4) {
        s = i * 2 + 3;
        printf("%d + %d = %d\n", i, i + 3, s);
        printf("%d + %d = %d\n", i + 1, i + 2, s);
        printf("%d - %d = 0\n", s, s);
        puts("24 + 0 = 24");
    }
}

main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
    
    int n, r;
    
    scanf("%d", &n);
    if (n < 4) {
        puts("NO");
        return 0;
    }
    r = n % 4;
    puts("YES");
    if (r == 0) {
        puts("1 * 2 = 2");
        puts("2 * 3 = 6");
        puts("6 * 4 = 24");
        print(5, n);
    }
    else if (r == 1) {
        puts("2 - 1 = 1");
        puts("1 + 3 = 4");
        puts("4 * 5 = 20");
        puts("20 + 4 = 24");
        print(6, n);
    }
    else if (r == 2) {
        puts("2 * 3 = 6");
        puts("6 * 4 = 24");
        puts("1 + 5 = 6");
        puts("6 - 6 = 0");
        puts("24 + 0 = 24");
        print(7, n);
    }
    else {
        puts("4 * 6 = 24");
        puts("2 + 7 = 9");
        puts("1 + 3 = 4");
        puts("4 + 5 = 9");
        puts("9 - 9 = 0");
        puts("24 + 0 = 24");
        print(8, n);
    }
}