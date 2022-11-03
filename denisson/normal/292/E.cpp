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
const int INF = (int)2e9 + 7;
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

const int MAGIC = (int)sqrt(100007) + 7;
int n, m;
int a[100007], b[100007];
int q[337];

void up(int s) {
	if (q[s] != -1) {
		int l = s * MAGIC;
		for (int i = 0; i < MAGIC; i++)
			b[l + i] = a[q[s] + i];
	}
	q[s] = -1;
}

void cop(int x, int y, int len) {
	for (int i = 0; i < len;) {
		if ((y + i) % MAGIC == 0) {
			if (y + i + MAGIC <= y + len - 1) {
				q[(y + i) / MAGIC] = x + i;
				i += MAGIC;
				continue;
			}
		}
		up((y + i) / MAGIC);
		b[y + i] = a[x + i];
		i++;
	}
}

const bool is_testing = 0;
int main() {
	srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N');
	//ios_base::sync_with_stdio(0); cin.tie(0);
	if (is_testing) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	} else {
		//freopen("input.txt", "r", stdin);
		//freopen("output.txt", "w", stdout);
	}
	forn(i, 333)
		q[i] = -1;
	scanf("%d%d", &n, &m);
	forn(i, n)
		scanf("%d", &a[i]);
	forn(i, n)
		scanf("%d", &b[i]);
	forn(dsfgdsfgdfg, m) {
		int type;
		scanf("%d", &type);
		if (type == 1) {
			int x, y, len;
			scanf("%d%d%d", &x, &y, &len);
			x--; y--;
			cop(x, y, len);
		} else {
			int x;
			scanf("%d", &x);
			x--;
			up(x / MAGIC);
			printf("%d\n", b[x]);
		}
	}
}