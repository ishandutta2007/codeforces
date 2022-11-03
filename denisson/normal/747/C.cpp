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

int n, q;
pair<int, pair<int, int> > a[100007];
bool was[107];
set<pair<int, int> > se;

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
	scanf("%d %d", &n, &q);
	for (int i = 0; i < q; i++) {
		int t, k, d;
		scanf("%d %d %d", &t, &k, &d);
		while (se.size() > 0 && (*se.begin()).XX <= t) {
			pair<int, int> now = *se.begin();
			was[now.YY] = 0;
			se.erase(se.begin());
		}
		if (n - (int)se.size() < k) {
			printf("-1\n");
			continue;
		}
		int ans = 0, kkk = 0;
		for (int i = 0; i < n; i++) {
			if (!was[i]) {
				was[i] = 1;
				ans += i + 1;
				kkk++;
				se.insert(mp(t + d, i));
				if (kkk == k)
					break;
			}
		}
		printf("%d\n", ans);
	}
}