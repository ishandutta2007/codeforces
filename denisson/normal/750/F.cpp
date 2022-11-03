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

int was = 0;
bool st = 0;
int hh;
vector<int> g[1000];

void gen() {
	hh = 7;
	for (int i = 0; i < 1000; i++)
		g[i].clear();
	vector<int> d;
	for (int i = 2; i <= 127; i++)
		d.pub(i);
	random_shuffle(all(d));
	d.pub(1);
	vector<pair<int, int> > st;
	int uk = 0, s = 1;
	st.pub(mp(d[0], -1));
	while (uk < st.size()) {
		pair<int, int> now = st[uk++];
		if (s < d.size())
			st.pub(mp(d[s], now.XX)), g[now.XX].pub(d[s++]);
		if (s < d.size())
			st.pub(mp(d[s], now.XX)), g[now.XX].pub(d[s++]);
		if (now.YY != -1)
			g[now.XX].pub(now.YY);
	}
}

void stop(int v) {
	cout << "! " << v << endl;
	cout.flush();
	st = 1;
}

bool aha[10000];
vector<int> f[10000];

vector<int> ask(int v) {
	if (aha[v])
		return f[v];
	cout << "? " << v << endl;
	cout.flush();
	int k;
	cin >> k;
	vector<int> ans;
	ans.resize(k);
	for (int i = 0; i < k; i++)
		cin >> ans[i];
	//vector<int> ans = g[v];
	was++;
	if (ans.size() == 2) stop(v);
	f[v] = ans;
	aha[v] = 1;
	return ans;
}

bool check(int v, int h, int pred) {
	vector<int> now = ask(v);
	if (st) return 1;
	if (h == hh)
		return (now.size() == 1);
	for (int to : now)
		if (to != pred)
			return check(to, h + 1, v);
}

void go(int v, int h, int last) {
	//cout << v << ' ' << h << ' ' << was << endl;
	if (st) return;
	auto now = ask(v);
	if (st) return;
	if (h == 3) {
		int kk = 0;
		for (int to : now) {
			if (to != last) {
				auto here = ask(to);
				if (st) return;
				kk++;
				for (int ha : here) {
					if (ha == v) continue;
					if (kk == 5)
						stop(ha);
					else {
						ask(ha);
						kk++;
					}
					if (st) return;
				}
			}
		}
		return;
	}
	int to1, to2;
	if (now[0] == last) to1 = now[1], to2 = now[2];
	if (now[1] == last) to1 = now[0], to2 = now[2];
	if (now[2] == last) to1 = now[0], to2 = now[1];
	bool f = !check(to1, h + 1, v);
	if (st) return;
	if (f)
		go(to1, h - 1, v);
	else
		go(to2, h - 1, v);
}

int get(int v, int pred, int was) {
	vector<int> now = ask(v);
	if (st) return INF;
	if (now.size() == 1)
		return hh;
	if (was == 5)
		return -INF;
	for (int to : now)
		if (to != pred)
			return get(to, v, was + 1) - 1;
}

const bool is_testing = 0;
int main() {
	srand('D' + 'E' + 'N' + 'I' + 'S' + 'S' + 'O' + 'N' + time(NULL));
	//mt19937 rnd(time(NULL));
	//ios_base::sync_with_stdio(0); cin.tie(0);
	if (is_testing) {
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	} else {
		//freopen("ufo.in", "r", stdin);
		//freopen("ufo.out", "w", stdout);
	}
	int tt = 1000000;
	cin >> tt;

	while (tt--) {
		//gen();
		for (int i = 0; i < 10000; i++)
			aha[i] = 0;
		was = 0;
		st = 0;
		cin >> hh;
		auto now = ask(1);
		if (st) continue;
		if (now.size() != 1) {
			int t1 = get(now[0], 1, 1);
			if (st) continue;
			int t2 = get(now[1], 1, 1);
			if (st) continue;
			if (t1 == t2) {
				go(now[2], t1 - 2, 1);
			}
			if (t1 < t2) {
				go(now[0], t2 - 2, 1);
			} 
			if (t1 > t2) {
				go(now[1], t1 - 2, 1);
			}
		} else {
			go(now.back(), hh - 1, 1);
		}
	}
}