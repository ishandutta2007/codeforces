#ifndef ONLINE_JUDGE
#include <iostream>
#include <iomanip>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#else
#include <bits/stdc++.h>
#endif
using namespace std;

#define ms(s, n) memset(s, n, sizeof(s))
#define FOR(i, a, b) for(int i = a; i < b; i++)
#define FORd(i, a, b) for(int i = a - 1; i >= b; i--)
#define sz(a) int((a).size())
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef vector<pi> vii;
typedef vector<pl> vll;
ll gcd(ll a, ll b) {ll r; while (b != 0) {r = a % b; a = b; b = r;} return a;}
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}

char s[20];

bool check(char *s) {
     int nlen = strlen(s);
     FOR(i, 0, nlen) if (s[i] != s[nlen - i - 1]) return false;
     return true;
}

void solve() {
     scanf("%s", s);
     int nlen = strlen(s);
     char t[20]; ms(t, 0);
     FOR(i, 0, nlen + 1) {
            FOR(j, 'a', 'z' + 1) {
                char temp[20]; ms(temp, 0); int cnt = 0;
                FOR(k, 0, i) temp[cnt++] = t[k];
                temp[cnt++] = j;
                FOR(k, i, nlen) temp[cnt++] = s[k];
                if (check(temp)) {printf("%s", temp); return;}
            }
            t[i] = s[i];
     }
     printf("NA");
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin); freopen("out.txt", "w", stdout);
#endif
	solve();
#ifndef ONLINE_JUDGE
	printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}