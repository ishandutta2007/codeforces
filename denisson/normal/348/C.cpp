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

int n, m, q;
ll a[100007];
vector<int> s[100007];
vector<int> uk;
int pr[301][100007];
ll sum[100007];
ll add[100007];
ll add2[100007];
bool was[100007];
int ge[100007];

int const kek = 350;

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
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 0; i < n; i++)
		scanf("%I64d", &a[i]);
	for (int i = 0; i < m; i++) {
		int sz;
		scanf("%d", &sz);
		s[i].resize(sz);
		for (int j = 0; j < sz; j++)
			scanf("%d", &s[i][j]), s[i][j]--;
		if (sz >= kek)
			uk.pub(i), ge[i] = (int)uk.size() - 1;
	}
	int ww = 0;
	for (int i = 0; i < m; i++) {
		if (s[i].size() >= kek) {
			memset(was, 0, sizeof(was));
			for (int j = 0; j < s[i].size(); j++)
				was[s[i][j]] = 1;
			for (int j = 0; j < m; j++) {
				for (int x = 0; x < s[j].size(); x++)
					if (was[s[j][x]])
						pr[ww][j]++;
			}
			ww++;
		}
	}

	for (int i = 0; i < m; i++) {
		for (int x = 0; x < s[i].size(); x++)
			sum[i] += a[s[i][x]];
	}
	for (int i = 0; i < q; i++) {
		char type;
		int k;
		scanf(" %c %d", &type, &k);
		k--;
		if (type == '?') {
			if (s[k].size() < kek) {
				ll ans = 0;
				for (int x : s[k])
					ans += a[x];
				for (int x : uk)
					ans += (ll)pr[ge[x]][k] * add2[x];
				printf("%I64d\n", ans);
			} else {
				printf("%I64d\n", sum[k] + add[k]);
			}
		} else {
			int xx;
			scanf("%d", &xx);
			if (s[k].size() < kek) {
				for (int x : s[k])
					a[x] += (ll)xx;
			} else {
				add2[k] += xx;
				add[k] += (ll)xx * (ll)s[k].size();
			}
			for (int x : uk) {
				if (x != k)
					add[x] += (ll)pr[ge[x]][k] * xx;
			}
		}
	}
}