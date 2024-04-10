#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <climits>
#include <ctime>
#include <cassert>
#include <cctype>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <vector>
#include <bitset>

#define X first
#define Y second
#define pb push_back
#define bit(x) (1 << (x))
#define bnum(x) (__builtin_popcount(x))
#define all(x) (x).begin(), (x).end()
#define mset0(x) memset((x), 0, sizeof((x)))
#define mset1(x) memset((x), -1, sizeof((x)))
#define LET(x,a) __typeof(a) x(a)
#define REP(it,v) for (LET(it,v.begin()); it != v.end(); it++)
#define sz(x) ((int)(x.size()))
#define PQ priority_queue
#define sqr(x) ((x) * (x))

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

template <class T> inline void chkmin(T &a, T b) {
    if (b < a) a = b;
}
template <class T> inline void chkmax(T &a, T b) {
    if (a < b) a = b;
}

const int MX = 200005;
char s[MX], t[MX];
int n;

void calc(int k) {
    if (k & 1) return;
    calc(k / 2);
    
    for (int i = 0; i < n; i += k) {
        int j = i + k / 2;
        if (strncmp(s + i, s + j, k / 2) > 0) {
            for (int h = 0; h < k / 2; h++) swap(s[i + h], s[j + h]);
        }
        if (strncmp(t + i, t + j, k / 2) > 0) {
            for (int h = 0; h < k / 2; h++) swap(t[i + h], t[j + h]);
        }
    }
}

int main() {
    
    scanf("%s%s", s, t);
    n = strlen(s);
    
    int m = n;
    calc(n);
    
    if (!strcmp(s, t)) puts("YES");
    else puts("NO");
    
    return 0;
}