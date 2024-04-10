// @betaveros :: vim:set fdm=marker syntax=cppc:
#define NDEBUG
// #includes, using namespace std {{{
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>
// #include <cinttypes> // C++11?
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <functional>
#include <new>
#include <algorithm>
#include <iostream>
using namespace std;
// }}}
// #defines, typedefs, constants {{{
#define fori(i,s,e) for(int i = s; i < ((int)e); i++)
#define fori0(i,e) for(int i = 0; i < ((int)e); i++)
#define fori1(i,e) for(int i = 1; i <= ((int)e); i++)
#define forui(i,s,e) for(unsigned int i = s; i < ((unsigned int)e); i++)
#define foruin(i,c) for(unsigned int i = 0; i < ((unsigned int)(c).size()); i++)
#define _conc(x,y) x ## y
#define _conc2(x,y) _conc(x,y)
#define repeat(n) fori(_conc2(_,__LINE__),0,n)
#define allof(s) (s).begin(), (s).end()
#define scan_d(x) scanf("%d",&(x))
#define scan_dd(x,y) scanf("%d%d",&(x),&(y))
#define scan_ddd(x,y,z) scanf("%d%d%d",&(x),&(y),&(z))
#define scan_dddd(x,y,z,w) scanf("%d%d%d%d",&(x),&(y),&(z),&(w))
#define pushb push_back
#define popb push_back

#ifdef NDEBUG
#define debug(code)
#define debugf(...) ((void)0)
#else
#define debug(code) code
#define debugf(...) fprintf(stderr, __VA_ARGS__)
#endif
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef vector<int> Vint;
typedef vector<int>::iterator Vit;

// const int OO  = 1000 << 20;
// const int OO2 = 2000 << 20;
// const int       M7  = 1000000007;
// const int       M9  = 1000000009;
// const long long M7L = 1000000007L;
// }}}
// dump, min/maxify {{{
template <class T> void dumpBetween(const T & a, const T & b) {
	for (T it = a; it != b; it++) cout << *it << " ";
	cout << endl;
}
template <class T> void dumpAll(const T & a) { dumpBetween(allof(a)); }
template <class T> void minify(T & a, const T & b) { if (a > b) a = b; }
template <class T> void maxify(T & a, const T & b) { if (a < b) a = b; }
// }}}

const int N = 100008;
char s[N];
int z[N], zz[N];
int n;
void readInput() {
	fgets(s, N, stdin);
	n = (int) strlen(s);
	while (!isalpha(s[n-1])) n--;
}
void makeZ() {
	debugf("making Z (n = %d)\n", n);
	z[0] = 0;
	int bst = 0;
	for (int i = 1; i < n; i++) {
		if (i >= bst + z[bst]) z[i] = 0;
		else z[i] = min(z[i - bst], bst + z[bst] - i);
		while (s[i + z[i]] == s[z[i]]) z[i]++;
		if (i + z[i] > bst + z[bst]) bst = i;
		debugf("Z[%d] = %d\n", i, z[i]);
	}
}

typedef pair<int,int> II;
vector<II> answers;

void tc() {
	readInput();
	makeZ();
	copy(z, z + n, zz);
	sort(zz, zz + n);
	for (int i = 1; i <= n; i++) {
		if (z[n - i] == i || i == n) {
			int c = (int) (lower_bound(zz, zz + n, i) - zz);
			answers.push_back(make_pair(i, n - c + 1));
		}
	}
	printf("%lu\n", answers.size());
	for (II p : answers) {
		printf("%d %d\n", p.first, p.second);
	}
}

int main() { tc(); }