#define _CRT_SECURE_NO_DEPRECATE
#define _SECURE_SCL 0
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <sstream>
#include <string>
#include <vector>

using namespace std;


typedef long long int64;

const int INF = (int) 1E9;
const int64 INF64 = (int64) 1E18;
const double EPS = 1E-9;
const double PI = acos((double)0) * 2;

#define forn(i,n)  for (int i=0; i<int(n); ++i)
#define fore(i,l,n)  for (int i=int(l); i<int(n); ++i)
#define ford(i,n)  for (int i=int(n)-1; i>=0; --i)
#define all(a)  a.begin(), a.end()
#define fs  first
#define sc  second
#define mp  make_pair
#define pb  push_back


const int MAXN = 170;
const int CNT = 150*5;


int n, m, len;
char a[MAXN][MAXN];

unsigned field[CNT], mask[CNT], need[CNT], tmp[CNT];


bool read() {
	if (! (cin >> n >> m >> len))
		return false;
	forn(i,n)
		forn(j,m)
			scanf (" %c", &a[i][j]);
	return true;
}


inline void set_bit (unsigned a[], int idx, int bit) {
	a[idx] |= 1u << bit;
}

inline char rev (char op) {
	return
		op=='L' ? 'R' :
		op=='R' ? 'L' :
		op=='U' ? 'D' :
		op=='D' ? 'U' :
		throw;
}

void dump (unsigned a[]) {
	forn(i,n) {
		forn(j,m)
			if (a[i*5 + j/32] & (1u << (j % 32)))
				cerr << '1';
			else
				cerr << '0';
		cerr << endl;
	}
}


void perform (unsigned field[], char op) {
	if (op == 'U') {
		fore(i,5,CNT)
			field[i-5] = field[i];
		forn(i,5)
			field[CNT-5+i] = 0;
	}
	if (op == 'D') {
		ford(i,CNT-5)
			field[i+5] = field[i];
		forn(i,5)
			field[i] = 0;
	}
	if (op == 'L') {
		int j = 0;
		forn(i,CNT) {
			unsigned bit = field[i] & 1;
			field[i] >>= 1;
			if (j != 0)
				field[i-1] |= bit << 31;
			if (++j == 5)  j = 0;
		}
	}
	if (op == 'R') {
		int j = 4;
		ford(i,CNT) {
			unsigned bit = (field[i] >> 31) & 1u;
			field[i] <<= 1;
			if (j != 4)
				field[i+1] |= bit;
			if (--j < 0)  j = 4;
		}
	}
}

void process_op (char op) {
	perform (field, op);
	forn(i,CNT) {
		tmp[i] = field[i] & ~mask[i];
		field[i] &= mask[i];
	}
	perform (tmp, rev (op));
	forn(i,CNT)
		field[i] |= tmp[i];
}

bool check() {
	return memcmp (field, need, sizeof need) == 0;
}

void solve() {
	memset (mask, 0, sizeof mask);
	memset (need, 0, sizeof need);
	forn(i,n)
		forn(j,m) {
			if (a[i][j] != '#')
				set_bit (mask, i*5 + j/32, j%32);
			if (a[i][j] =='E')
				set_bit (need, i*5 + j/32, j%32);
		}
	memcpy (field, mask, sizeof mask);

	/*
	cerr << "mask\n";
	dump (mask);
	cerr << "field\n";
	dump (field);
	cerr << "need\n";
	dump (need);
	*/

	if (check()) {
		puts ("0");
		return;
	}
	forn(i,len) {
		char op;
		scanf (" %c", &op);
		process_op (op);
		//cerr << "after\n";
		//dump (field);
		if (check()) {
			printf ("%d\n", i+1);
			
			fore(j,i+1,len)
				scanf (" %c", &op);

			return;
		}
	}
	puts("-1");
}


int main() {
#ifndef ONLINE_JUDGE
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
#endif

	while (read())
		solve();

}