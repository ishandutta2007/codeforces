#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <bitset>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<ll, ll> pll;
typedef long double ldouble;
typedef pair<double, double> pdd;

int Trie[5000050][5], tz;
int N, M;
int leaf[5000050];
int cnt[5000050];
char B[55];
int lc;
int chk[5000010];
int v[100010], vz;
int ans;

void dfs(int x, int y) {
	if(B[x] == 0) {
		if(chk[y] == 0){ chk[y] = 1; v[vz++] = y; ans += cnt[y]; }
		return;
	}
	if(B[x] != '?') {
		int c = B[x] - 'a';
		if(Trie[y][c] > 0) dfs(x+1, Trie[y][c]);
	}
	else {
		dfs(x+1, y);
		rep(i, 5) if(Trie[y][i] > 0) dfs(x+1, Trie[y][i]);
	}
}

void solve(){
	scanf("%d%d", &N, &M);
	rep(i, N) {
		char ch[55]; scanf("%s", ch);
		int L = (int)strlen(ch);
		int now = 0;
		for(int a=0;a<L;a++) {
			int c = ch[a] - 'a';
			if(Trie[now][c] == 0) Trie[now][c] = ++tz;
			now = Trie[now][c];
		}
		cnt[now]++;
	}
	rep(i, M) {
		scanf("%s", B);
		ans = 0;
		dfs(0, 0);
		printf("%d\n", ans);
		rep(a, vz) chk[v[a]] = 0; vz = 0;
	}
}

int main(){
	int Tc = 1; //scanf("%d", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		//printf("Case #%d\n", tc);
		solve();
	}
	return 0;
};