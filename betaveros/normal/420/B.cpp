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

// const int OO  = 1000 << 10;
// const int OO2 = 2000 << 10;
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

const int T5 = 100008;
int n, m;
int msgId[T5], msgD[T5];

void readInput() {
	scan_dd(n, m);
	char buf[5];
	fori (i, 0, m) {
		scanf("%s %d", buf, &msgId[i]);
		assert(buf[0] == '+' || buf[0] == '-');
		msgD[i] = buf[0] == '+' ? 1 : -1;
	}
}

bool start[T5], ending[T5], seen[T5], possible[T5], only[T5];
bool startExists, endExists;
int onlies = 0;
int firstStartId;
void tc() {
	readInput();
	startExists = false;
	fill(seen, seen + T5, false);
	fill(only, only + T5, false);
	fill(possible, possible + T5, true);
	firstStartId = (msgD[0] == 1 ? msgId[0] : -1);
	fori (i, 0, m) {
		if (msgD[i]) {
			int id = msgId[i];
			if (!seen[id]) {
				seen[id] = true;
				if (msgD[i] == -1) {
					start[id] = true;
					startExists = true;
				}
			}
		}
	}
	debugf("doesstartexists? %d\n", startExists);
	fill(seen, seen + T5, false);
	endExists = false;
	for (int i = m - 1; i >= 0; i--) {
		if (msgD[i]) {
			int id = msgId[i];
			if (!seen[id]) {
				seen[id] = true;
				if (msgD[i] == 1) {
					ending[id] = true;
					endExists = true;
				}
			}
		}
	}
	debugf("doesendexists? %d\n", endExists);
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (start[i]) cnt++;
	}
	for (int i = 0; i < m; i++) {
		int id = msgId[i];
		int d = msgD[i];
		if (d == 1) {
			if (cnt) possible[id] = false;
			else {
				if (!only[id]) {
					only[id] = true;
					onlies++;
				}
			}
		}
		cnt += d;
		debugf("  cnt = %d\n", cnt);
		if (d == -1) {
			if (cnt) possible[id] = false;
			else {
				if (!only[id]) {
					only[id] = true;
					onlies++;
				}
			}
		}
	}
	vector<int> answers;
	for (int i = 1; i <= n; i++) {
		if (startExists && seen[i] && !start[i]) continue;
		if (endExists && seen[i] && !ending[i]) continue;
		if (seen[i] && (onlies >= 2 || (onlies && !only[i]))) continue;
		if (!possible[i]) continue;
		answers.pushb(i);
	}
	printf("%d\n", (int)answers.size());
	if (answers.size()) {
		foruin (i, answers) {
			if (i) printf(" ");
			printf("%d", answers[i]);
		}
		printf("\n");
	}
}

int main() { tc(); }