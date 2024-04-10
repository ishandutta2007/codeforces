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
#define XX first
#define YY second
#define all(a) a.begin(), a.end()
#define y1 dsfgsdfgsdfgsdfgsdfgsdfg
#define y0 asdfasdf3rcdt234d5c23xd234dx43
const int INF = (int)1e9 + 7;
const ll LINF = (ll)9e18 + 7;
const double pi = acos(-1.0);
 
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
int color[100007];
int kol[100007];
vector<int> ha[200007];
map<string, int> ma;
int ok = 1;

void add(int v, int col) {
	kol[col]++;
	kol[color[v]]--;
	ha[col].pub(v);
	color[v] = col;
}

int getobr(int col) {
	if (col & 1 == 1) return col - 1;
	return col + 1;
}

void merge(int a, int b) {
	if (a == b) return;
	if (kol[a] + kol[getobr(a)] > kol[b] + kol[getobr(b)])
		swap(a, b);
	for (int x : ha[a]) add(x, b);
	for (int x : ha[getobr(a)]) add(x, getobr(b));
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
        //freopen("lamps.in", "r", stdin);
        //freopen("lamps.out", "w", stdout);
    }
	cin >> n >> m >> q;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		ma[s] = i;
	}
	memset(color, 0, sizeof(color));
	for (int i = 0; i < m; i++) {
		int type;
		string s1, s2;
		cin >> type >> s1 >> s2;
		int v = ma[s1], u = ma[s2];
		if (color[v] == 0 && color[u] == 0) {
			cout << "YES" << "\n";
			add(v, 2 * ok);
			add(u, 2 * ok + type - 1);
			ok++;
			continue;
		}
		if (color[v] == 0) {
			cout << "YES" << "\n";
			if (type == 2) add(v, getobr(color[u]));
			else add(v, color[u]);
			continue;
		}
		if (color[u] == 0) {
			cout << "YES" << "\n";
			if (type == 2) add(u, getobr(color[v]));
			else add(u, color[v]);
			continue;
		}
		if (type == 1 && color[v] == getobr(color[u])) {
			cout << "NO" << "\n";
			continue;
		}
		if (type == 2 && color[v] == color[u]) {
			cout << "NO" << "\n";
			continue;
		}
		cout << "YES" << "\n";
		if (type == 1) merge(color[v], color[u]);
		else merge(color[v], getobr(color[u]));

	}
	for (int i = 0; i < q; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		int a = ma[s1], b = ma[s2];
		if (color[a] == color[b] && color[a] > 0 && color[b] > 0) {
			cout << 1 << "\n";
			continue;
		}
		if (color[a] == getobr(color[b]) && color[a] > 0 && color[b] > 0) { 
			cout << 2 << "\n"; 
			continue;
		}
		cout << 3 << "\n";
	}
}