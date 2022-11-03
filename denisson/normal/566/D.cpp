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

int n, q;
int cnm[200007];
int rr[200007];
set<pair<int, int> > se;
int kk;
pair<int, int> t[200007];

int get(int v) {
	if (cnm[v] == v)
		return v;
	cnm[v] = get(cnm[v]);
	return cnm[v];
}

void merge(int v, int u) {
	v = get(v);
	u = get(u);
	if (v == u)
		return;
	if (rr[v] < rr[u])
		swap(v, u);
	cnm[u] = v;
	if (rr[v] == rr[u])
		rr[v]++;
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
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    }
	scanf("%d%d", &n, &q);
	forn(i, n)
		cnm[i] = i, rr[i] = 0, se.insert(mp(i, i));
	forn(i, q) {
		int type, x, y;
		scanf("%d%d%d", &type, &x, &y);
		x--; y--;
		if (type == 1) {
			pair<int, int> v = *se.lower_bound(mp(x, -1));
			pair<int, int> u = *se.lower_bound(mp(y, -1));
			merge(v.XX, u.XX);
		} else if (type == 2) {
			kk = 0;
			auto it = se.lower_bound(mp(x, -1));
			while (it != se.end() && (*it).YY <= y)
				t[kk++] = (*it), it++;
			for (int j = 1; j < kk; j++)
				merge(t[0].XX, t[j].XX);
			forn(j, kk)
				se.erase(t[j]);
			se.insert(mp(t[kk - 1].XX, t[0].YY));
		} else {
			pair<int, int> v = *se.lower_bound(mp(x, -1));
			pair<int, int> u = *se.lower_bound(mp(y, -1));
			if (get(v.XX) == get(u.XX))
				printf("YES\n");
			else
				printf("NO\n");
		}
	}
}