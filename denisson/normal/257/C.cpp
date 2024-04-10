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
const int MAX_MEM = 2e8;
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

struct point {
	int x, y;
	point () {}
	point(db x1, db y1) {
		x = x1;
		y = y1;
	}
};

struct vec {
	db x, y;
	vec() {}
	vec(point a, point b) {
		x = a.x - b.x;
		y = a.y - b.y;
	}
	db operator%(vec q) {
		return x * q.y - y * q.x;
	}
};

int n;
point a[100007];
db get1[100007];

db getAng(point a) {
	db ang = atan2(a.y, a.x);
	if (ang < 0)
		ang += pi * 2;
	return ang;
}

bool cmp(point a, point b) {
	return getAng(a) < getAng(b);
}

const bool is_testing = 0;
int main() {
    srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N');
    //ios_base::sync_with_stdio(0); cin.tie(0);
    if (is_testing) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    } else {
        //freopen("input.txt", "w", stdout);
        //freopen("just.in", "r", stdin);
        //freopen("just.out","w", stdout);
    }
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d %d", &a[i].x, &a[i].y), get1[i] = getAng(a[i]);
	sort(a, a + n, cmp);
	db ans = 0;
	for (int i = 0; i < n; i++) {
		db now = (db)getAng(a[(i + 1) % n]) - getAng(a[i]);
		if (now < 0)
			now += (db)2 * pi;
		ans = max(ans, now);
	}
	bool f = 0;
	for (int i = 0; i < n; i++) {
		if (vec(a[i], point(0, 0)) % vec(a[(i + 1) % n], point(0, 0)) != 0)
			f = 1;
	}
	if (!f)
		cout << 0, exit(0);
	cout.precision(8);
	cout << fixed << (db)360 - (db)180 * ans / pi;
}