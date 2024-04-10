#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <bitset>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

using namespace std;

typedef long long ll;
#define forn(i, n) for (int i = 0; i < n; i++)
#define form(i, n, m) for (int i = n; i <= m; i++)
#define mp make_pair
#define pub push_back
#define XX first
#define YY second
#define db long double
#define all(a) a.begin(), a.end()
#define y1 dsfgsdfgsdfgsdfgsdfgsdfg
#define y0 asdfasdf3rcdt234d5c23xd234dx43
const string LN = "\n";
const double eps = 1e-9;
const double pi = acos(-1.0);
const int INF = (int)1e9 + 7;
const ll LINF = (ll)9e18 + 7;

const ll P = 353251;
const ll P1 = 353251;
const ll P2 = 239017;
const ll MOD = 1e9 + 7;
const ll MOD1 = 1e9 + 7;
const ll MOD2 = 1e9 + 9;

//
/*
const int MAX_MEM = 1e8;
int mpos = 0;
char mem[MAX_MEM];
void * operator new ( size_t n ) {
    char *res = mem + mpos;
    mpos += n;
    return (void *)res;
}
void operator delete ( void * ) { }
*/
//

struct st {
	int x, y, z;
	st() {}
	st(int x1, int y1, int z1) {
		x = x1;
		y = y1;
		z = z1;
	}
};

int n;
st a[100007];
pair<int, int> uk;
int ans = 0;
map<pair<int, int>, int> ma;

const bool is_testing = 0;
int main() {
    srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N');
    //ios_base::sync_with_stdio(0); cin.tie(0);
    if (is_testing) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    } else {
        //freopen("key.in", "r", stdin);
        //freopen("key.out", "w", stdout);
    }
	scanf("%d", &n);
	forn(i, n)
		scanf("%d%d%d", &a[i + 1].x, &a[i + 1].y, &a[i + 1].z);
	for (int i = 1; i <= n; i++) {
		forn(j, 3) {
			if (a[i].z < a[i].y)
				swap(a[i].z, a[i].y);
			if (a[i].y < a[i].x)
				swap(a[i].x, a[i].y);
		}
	}
	for (int i = 1; i <= n; i++) {
		if (ma[mp(a[i].x, a[i].y)] == 0)
			ma[mp(a[i].x, a[i].y)] = i;
		else
			if (a[ma[mp(a[i].x, a[i].y)]].z < a[i].z)
				ma[mp(a[i].x, a[i].y)] = i;
		//
		if (ma[mp(a[i].x, a[i].z)] == 0)
			ma[mp(a[i].x, a[i].z)] = i;
		else
			if (a[ma[mp(a[i].x, a[i].z)]].y < a[i].y)
				ma[mp(a[i].x, a[i].z)] = i;
		//
		if (ma[mp(a[i].y, a[i].z)] == 0)
			ma[mp(a[i].y, a[i].z)] = i;
		else
			if (a[ma[mp(a[i].y, a[i].z)]].x < a[i].x)
				ma[mp(a[i].y, a[i].z)] = i;
	}
	for (int i = 1; i <= n; i++) {
		int kk = ma[mp(a[i].y, a[i].z)];
		if (kk != 0) {
			int now;
			if (a[kk].x == a[i].y && a[kk].y == a[i].z)
				now = a[kk].z;
			if (a[kk].y == a[i].y && a[kk].z == a[i].z)
				now = a[kk].x;
			if (min(min(a[i].y, a[i].z), a[i].x + (kk == i ? 0 : now)) > ans)
				ans = min(min(a[i].y, a[i].z), a[i].x + (kk == i ? 0 : now)), now, uk = mp(i, kk);
		}
	}
    if (uk.XX == uk.YY){
        cout << 1 << LN << uk.XX;
        exit(0);
    }
	cout << 2 << LN << uk.XX << ' ' << uk.YY;
}