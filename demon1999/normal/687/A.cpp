//this code was written by demon
#include <bits/stdc++.h>
//include "grader.h"

#define forn(i, n) for (int i = 0; i < n; i++)
#define re return
#define se second
#define fi first
#define gi get_int()
#define mp(a, b) make_pair(a, b)
#define sz(a) (int)a.size()
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int get_int() {
    int k;
    scanf("%d", &k);
    re k;
}

void my_assert(bool cc) {
    if (!cc) while(true);
}

int n, m, col[1000 * 1000];
vector<int> edge[1000 * 1000], aa, bb;

void dfs(int nu) {
	if (col[nu]) aa.push_back(nu + 1);
	else bb.push_back(nu + 1);
	//cout << nu << endl;
	for (int v : edge[nu]) {
		if (col[v] != -1) {
			if (col[v] == col[nu]) {
				printf("-1\n");
				exit(0);
			}
		}
		else {
			col[v] = 1 - col[nu];
			dfs(v);
		}
	}
}

int main() {
	//iostream::sync_with_stdio(0), cin.tie(0);
	//freopen("kk.in", "r", stdin);
	//freopen(".out", "w", stdout);
	n = gi; m = gi;
	forn (i, n) col[i] = -1;
	forn (i, m) {
		int a = gi, b = gi;
		a--;
		b--;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	forn (i, n) {
		if (col[i] == -1) {
			col[i] = 0;
			dfs(i);
		}
	}
	sort(aa.begin(), aa.end());
	sort(bb.begin(), bb.end());
	printf("%d\n", sz(aa));
	forn (i, sz(aa))
		printf("%d ", aa[i]);
	printf("\n%d\n", sz(bb));
	forn (i, sz(bb))
		printf("%d ", bb[i]);
    re 0;
}