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

int n, w, k;
int a[2 * 100007];
int t[2 * 100007];
int sum[2 * 100007];
int sum1 = 0, sum2 = 0;
multiset<int> se1, se2;

int get(int l, int r) {
	return sum[r] - sum[l - 1];
}

bool can(int x) {
	if (se2.size() == 0) {
		return ((x + 1) / 2 <= k);
	}
	int st = *se2.begin();
	int now = 0;
	if (se2.size() == w) {
		if (x <= st) {
			now = x;
		} else {
			now = (x + 1) / 2 - (st + 1) / 2 + st;
		}
	} else
		now = (x + 1) / 2;
	return (sum1 + sum2 + now <= k);
}

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
	scanf("%d %d %d", &n, &w, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
		scanf("%d", &t[i]);
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + a[i];
	int uk = 0;
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		uk = max(i - 1, uk);
		if ((t[i] + 1) / 2 > k) {
			se1.clear();
			se2.clear();
			continue;
		}
		while (uk + 1 <= n && can(t[uk + 1])) {
			uk++;
			if (se2.size() < w) {
				se2.insert(t[uk]);
				sum2 += (t[uk] + 1) / 2;
			} else {
				int x = *se2.begin();
				if (t[uk] <= x) {
					se1.insert(t[uk]);
					sum1 += t[uk];
				} else {
					se2.insert(t[uk]);
					sum2 += (t[uk] + 1) / 2;
					sum2 -= (x + 1) / 2;
					sum1 += x;
					se2.erase(se2.begin());
					se1.insert(x);
				}
			}
		}

		ans = max(ans, get(i, uk));
		if (se1.find(t[i]) == se1.end()) {
			se2.erase(se2.find(t[i]));
			sum2 -= (t[i] + 1) / 2;
			if (se1.size() > 0) {
				int x = *(--se1.end());
				se2.insert(x);
				sum2 += (x + 1) / 2;
				sum1 -= x;
				se1.erase(se1.find(x));
			}
		} else {
			se1.erase(se1.find(t[i]));
			sum1 -= t[i];
		}
	}
	printf("%d", ans);
}