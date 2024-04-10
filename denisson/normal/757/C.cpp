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
#define x first
#define y second
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
 

const int MAX_MEM = 1e8;
int mpos = 0;
char mem[MAX_MEM];
void * operator new ( size_t n ) {
    char *res = mem + mpos;
    mpos += n;
    return (void *)res;
}
void operator delete ( void * ) { }

 
int n, m;
int type[1000007];
int col[1000007];
bool was[1000007];
int sz = 1;

const bool is_testing = 0;
int main() {
    srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N' + time(NULL));
    //mt19937 rnd(time(NULL));
    //ios_base::sync_with_stdio(0); cin.tie(0);
    if (is_testing) {
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    } else {
        //freopen("lines.in", "r", stdin);
        //freopen("lines.out", "w", stdout);
    }
	scanf("%d %d", &n, &m);
	for (int st = 0; st < n; st++) {
		int k;
		scanf("%d", &k);
		vector<int> t;
		for (int j = 0; j < k; j++) {
			int c;
			scanf("%d", &c);
			c--;
			col[c]++;
			t.pub(c);
		}
		vector<pair<int, int> > d;
		for (int x : t) if (!was[x]) {
			d.pub(mp(col[x], x));
			was[x] = 1;
		}
		sort(all(d));
		int i = 0;
		while (1) {
			int j = i;
			while (j + 1 < d.size() && d[j + 1].first == d[i].first) j++;

			vector<pair<int, int> > now;
			for (int k = i; k <= j; k++)
				now.pub(mp(type[d[k].second], d[k].second));
			sort(all(now));

			int i1 = 0;
			while (1) {
				int j1 = i1;
				while (j1 + 1 < now.size() && now[j1 + 1].first == now[i1].first) j1++;

				for (int k1 = i1; k1 <= j1; k1++)
					type[now[k1].second] = sz;
				sz++;

				i1 = j1 + 1;
				if (i1 >= now.size()) break;
			}

			i = j + 1;
			if (i >= d.size()) break;
		}
		for (int x : t) {
			was[x] = 0;
			col[x] = 0;
		}
	}
	ll ans = 1;
	vector<pair<int, int> > s;
	for (int i = 0; i < m; i++)
		s.pub(mp(type[i], i));
	sort(all(s));
	int i = 0;
	while (1) {
		int j = i;

		while (j + 1 < s.size() && s[j + 1].first == s[i].first) j++;

		for (int k = 1; k <= j - i + 1; k++)
			ans = (ans * k) % MOD;

		i = j + 1;
		if (i >= s.size()) break;
	}
	cout << ans;
}