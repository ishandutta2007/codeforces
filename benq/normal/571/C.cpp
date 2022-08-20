#include <bits/stdc++.h>

using namespace std;
//using namespace __gnu_pbds;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define FOR(i, a, b) for (int i=a; i<b; i++)
#define F0R(i, a) for (int i=0; i<a; i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
 
#define mp make_pair
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound

const int MOD = 1000000007;
double PI = 4*atan(1);

bool bad = 0;
int n,m, done[200001], ans[200001];
int nex = 0;
set<int> var[200001];
vector<pii> appear[200001];
queue<int> todo;

void input() {
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m;
	FOR(i,1,m+1) ans[i] = -1;
	F0R(i,n) {
		int k; cin >> k;
		F0R(j,k) {
			int v; cin >> v;
			var[i].insert(v);
			appear[abs(v)].pb({i,v});
		}
		if (k == 1) todo.push(i);
	}
}

void propogate(int x) {
	for (pii a: appear[x]) if (!done[a.f]) {
		if ((a.s < 0 && ans[x] == 0) || (a.s > 0 && ans[x] == 1)) done[a.f] = 1;
		else {
			var[a.f].erase(a.s);
			if (var[a.f].size() == 0) bad = 1;
			else if (var[a.f].size() == 1) todo.push(a.f);
		}
	}
}

void change(int x) {
	int x1 = *var[x].begin(); var[x].erase(x1);
	if (x1 < 0) ans[abs(x1)] = 0;
	else ans[x1] = 1;
	done[x] = 1;
	propogate(abs(x1));
}

int main() {
	input();
	while (1) {
		if (bad) {
			cout << "NO";
			return 0;
		}
		if (todo.size()) {
			int x = todo.front(); todo.pop();
			change(x);
		} else {
			while (nex < n && done[nex]) nex++;
			if (nex == n) break;
			change(nex);
		}
	}
	cout << "YES\n";
	FOR(i,1,m+1) {
		if (ans[i] == -1) ans[i] = 0;
		cout << ans[i];
	}
}