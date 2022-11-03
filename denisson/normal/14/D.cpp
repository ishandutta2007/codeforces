#include <bits/stdc++.h>
    
using namespace std;
    
typedef long long ll;
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double
#define sz(a) (int)a.size()
    
int n, m;
vector<int> g[100007];
int dp[100007];
int dp2[100007];

void dfs(int v, int pred){
	for (int i = 0; i < g[v].size(); i++) if (g[v][i] == pred){
		swap(g[v][i], g[v].back());
		g[v].pop_back();
		break;
	}
	vector<int> t;
	t.pb(0);
	t.pb(0);
	for (int to : g[v]) if (to != pred){
		dfs(to, v);
		dp2[v] = max(dp2[v], dp2[to]);
		t.pb(dp[to] + 1);
	}
	sort(all(t));
	reverse(all(t));
	dp[v] = t[0];
	dp2[v] = max(dp2[v], t[0] + t[1]);
	//cout << v << ' ' << dp[v] << ' ' << dp2[v] << endl;
}

ll ans = 0;

void calc(int v, int len, int len2){
	//cout << v << ' ' << len << ' ' << len2 << endl;
	ans = max(ans, dp2[v] * (ll)len2);
	vector<pair<int, int> > t, t2;
	t.pb(mp(len, -1));
	t.pb(mp(0, -1));
	t2.pb(mp(len2, -1));
	for (int to : g[v]){
		t.pb(mp(dp[to] + 1, to));
		t2.pb(mp(dp2[to], to));
	}
	sort(all(t));
	reverse(all(t));
	sort(all(t2));
	reverse(all(t2));
	for (int to : g[v]){
		len2 = t2[0].x;
		if (t2[0].y == to) len2 = t2[1].x;
		int tmp = t[0].x + t[1].x;
		if (t[0].y == to) tmp += t[2].x - t[0].x;
		if (t[1].y == to) tmp += t[2].x - t[1].x;
		len = t[0].x;
		if (t[0].y == to) len = t[1].x;
		calc(to, len + 1, max(len2, tmp));
	}
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++){
    	int a, b;
    	cin >> a >> b;
    	a--; b--;
    	g[a].pb(b);
    	g[b].pb(a);
    }

    dfs(0, -1);
    calc(0, 0, 0);

    cout << ans;
}