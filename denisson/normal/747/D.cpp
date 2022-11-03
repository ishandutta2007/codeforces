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
#include <random>
#include <cassert>
  
using namespace std;
  
typedef long long ll;
#define mp make_pair
#define pub push_back
#define XX first
#define YY second
#define db long double
#define all(a) a.begin(), a.end()
#define y1 dsfgsdfgsdfgsdfgsdfgsdfg
#define y0 asdfasdf3rcdt234d5c23xd234dx43
const int INF = (int)1e9 + 7;
const ll LINF = (ll)9e18 + 7;
  
const ll P1 = 353251;
const ll P2 = 239017;
const ll MOD = 1e9 + 7;
const ll MOD1 = 1e9 + 7;
const ll MOD2 = 1e9 + 9;

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

int n, k;
int a[2 * 100007];
int s = 0;
vector<pair<int, int> > q;

const bool is_testing = 0;
int main() {
	srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N');
	//mt19937 rnd(time(NULL));
	//ios_base::sync_with_stdio(0); cin.tie(0);
	if (is_testing) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	} else {
		//freopen("just.in", "r", stdin);
		//freopen("just.out","w", stdout);
	}
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int st = -1;
	for (int i = 0; i < n; i++) {
		if (a[i] < 0) {
			if (st == -1) {
				st = i;
			}
		} else {
			if (st != -1) {
				q.pub(mp(st, i - 1));
				st = -1;
			}
		}
	}
	if (st != -1)
		q.pub(mp(st, n - 1));

	if (q.size() == 0 && st == -1)
		cout << 0, exit(0);

	for (int i = 0; i < q.size(); i++)
		k -= (q[i].YY - q[i].XX + 1);

	if (k < 0)
		cout << -1, exit(0);

	int ans = (int)q.size() * 2;

	if (q.back().YY == n - 1) {
		ans--;
	}

	int copk = k;
	int copans = ans;
	multiset<int> se;
	for (int i = 0; i < (int)q.size() - 1; i++) {
		se.insert(q[i + 1].XX - q[i].YY - 1);
	}

	while (se.size() > 0) {
		int now = *se.begin();
		se.erase(se.begin());
		if (k >= now)
			k -= now, ans -= 2;
		else break;
	}
	if (st == -1) {
		int r = n - 1 - q.back().YY;
		if (r <= copk) {
			copk -= r;
			copans--;
			
			multiset<int> se;
			for (int i = 0; i < (int)q.size() - 1; i++) {
				se.insert(q[i + 1].XX - q[i].YY - 1);
			}
			while (se.size() > 0) {
				int now = *se.begin();
				se.erase(se.begin());
				if (copk >= now)
					copk -= now, copans -= 2;
				else break;
			}

		}
	}
	cout << min(ans, copans);
}