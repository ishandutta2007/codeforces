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

int n, m, k1, k2;
set<int> g[100007];
vector<pair<int, int> > reb;

const bool is_testing = 0;
int main() {
	srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N' + time(NULL));
	//mt19937 rnd(time(NULL));
	ios_base::sync_with_stdio(0); cin.tie(0);
	if (is_testing) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	} else {
		//freopen("ufo.in", "r", stdin);
		//freopen("ufo.out", "w", stdout);
	}
	cin >> n >> m >> k1 >> k2;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		g[a].insert(b);
		g[b].insert(a);
		reb.pub(mp(a, b));
		reb.pub(mp(b, a));
	}
	for (pair<int, int> c : reb) {
		int x = c.first, y = c.second;
		int obs = 0;
		int f = 0;
		for (int v : g[x]) {
			if (f > 205)
				break;
			if (v == y)
				continue;
			if (g[y].find(v) != g[y].end())
				obs++;
			f++;
		}
		int s1 = (int)g[x].size() - obs - 1, s2 = (int)g[y].size() - obs - 1;
		int need = max(0, k1 - s1) + max(0, k2 - s2);
		if (need <= obs) {
			cout << "YES\n" << x << ' ' << y << "\n";
			set<int> t1, t2;
			f = 0;
			for (int v : g[x]) {
				if (f > 205 || t1.size() == k1)
					break;
				if (v == y)
					continue;
				if (g[y].find(v) == g[y].end())
					t1.insert(v);
				f++;
			}
			for (int v : g[x]) {
				if (t1.size() == k1)
					break;
				if (v == y)
					continue;
				if (t1.find(v) == t1.end())
					t1.insert(v);
				f++;
			}
			for (int v : g[y]) {
				if (t2.size() == k2)
					break;
				if (v == x)
					continue;
				if (t1.find(v) == t1.end())
					t2.insert(v);
			}
			for (int v : t1)
				cout << v << ' ';
			cout << "\n";
			for (int v : t2)
				cout << v << ' ';
			exit(0);
		}
	}
	cout << "NO";
}