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

typedef pair<int, int> pii;
typedef vector<int> vi;

#define MX 1005
int n, p;
char s[MX];

bool calc() {
    int i, k;
    
    for (i = n - 1; i >= 0; i--) {
        for (k = s[i] + 1; k < 'a' + p; k++) {
            if (i && k == s[i - 1]) continue;
            if (i > 1 && k == s[i - 2]) continue;
            break;
        }
        if (k < 'a' + p) break;
    }
    if (i < 0) return 0;
    
    s[i] = k;
    for (i++; i < n; i++) {
        for (k = 'a'; k < 'a' + p; k++) {
            if (i && k == s[i - 1]) continue;
            if (i > 1 && k == s[i - 2]) continue;
            break;
        }
        s[i] = k;
    }
    puts(s);
    return 1;
}

main() {
    scanf("%d%d", &n, &p);
    scanf("%s", s);
    if (p == 1) puts("NO");
    else if (p == 2) {
        if (n == 1) {
            if (s[0] == 'a') puts("b");
            else puts("NO");
        }
        else {
            if (s[0] == 'a') puts("ba");
            else puts("NO");
        }
    }
    else if (!calc()) puts("NO");
}