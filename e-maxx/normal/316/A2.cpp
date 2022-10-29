#define _CRT_SECURE_NO_DEPRECATE
#define _SECURE_SCL 0
#pragma comment (linker, "/STACK:200000000")
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

typedef long long int64;
//typedef double old_double;
//#define double long double
const int INF = (int) 1E9;
const int64 INF64 = (int64) 1E18;
const double EPS = 1E-9;
const double PI = acos((double)0) * 2;

#define forn(i,n)  for (int i=0; i<int(n); ++i)
#define ford(i,n)  for (int i=int(n)-1; i>=0; --i)
#define fore(i,l,n)  for (int i=int(l); i<int(n); ++i)
#define all(a)  a.begin(), a.end()
#define fs  first
#define sc  second
#define pb  push_back
#define mp  make_pair


string s;


bool read() {
    return !!(cin >> s);
}


int fact(int n) {
    int r = 1;
    for (int i = 1; i <= n; ++i)
        r *= i;
    return r;
}

int get_c(int n, int k) {
    return fact(n) / fact(k) / fact(n - k);
}


void solve() {
    set<char> u;
    forn(i, s.length())
        if (isalpha(s[i]))
            u.insert(s[i]);
    int groups = (int)u.size();

    int quests = (int)count(all(s), '?');

    int ans = get_c(10, groups) * fact(groups);
    if (isalpha(s[0]))
        ans -= get_c(9, groups - 1) * fact(groups - 1);
    if (s[0] == '?') {
        --quests;
        ans *= 9;
    }

    if (ans == 0) {
        puts("0");
        return;
    }
    if (ans < 0)
        throw;
    cout << ans << string(quests, '0') << endl;
}


int main(int argc, char* argv[]) {
#ifdef SU2_PROJ
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
    while (read())
        solve();
#else
    if (!read())
        throw;
    solve();
#endif
}