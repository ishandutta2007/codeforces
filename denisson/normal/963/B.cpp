#include <bits/stdc++.h>
  
using namespace std;
  
typedef long long ll;
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

int n;
vector<int> g[200007];
int dp[200007][2];

void dfs(int v, int pred){
	for (int i = 0; i < g[v].size(); i++) if (g[v][i] == pred){
		swap(g[v][i], g[v].back());
		g[v].pop_back();
		break;
	}
	int cnt1 = 0, cnt2 = 0, cnt3 = 0;
	for (int to : g[v]){
		dfs(to, v);
		if (dp[to][0] == 0 && dp[to][1] == 0) cout << "NO", exit(0);
		if (dp[to][0] == 1 && dp[to][1] == 0) cnt1++;
		if (dp[to][0] == 0 && dp[to][1] == 1) cnt2++;
		if (dp[to][0] == 1 && dp[to][1] == 1) cnt3++;
	}
	dp[v][0] = dp[v][1] = 0;
	if (cnt1 % 2 == 0 || cnt1 % 2 == 1 && cnt3 > 0){
		dp[v][0] = 1;
	}
	if (cnt1 % 2 == 1 || cnt1 % 2 == 0 && cnt3 > 0){
		dp[v][1] = 1;
	}
	//cout << v << ' ' << dp[v][0] << ' ' << dp[v][1] << endl;
}

vector<int> ans;

void calc(int v, int type){
	//cout << v << ' ' << type << endl;
	vector<int> t1, t2, t3;
	for (int to : g[v]){
		if (dp[to][0] == 1 && dp[to][1] == 0) t1.pb(to);
		if (dp[to][0] == 0 && dp[to][1] == 1) t2.pb(to);
		if (dp[to][0] == 1 && dp[to][1] == 1) t3.pb(to);
	}
	if (type == 0){
		if (t1.size() % 2 == 0){
			for (int x : t2) calc(x, 1);
			for (int x : t3) calc(x, 1);
			ans.pb(v);
			for (int x : t1) calc(x, 0);
		} else {
			for (int x : t2) calc(x, 1);
			if (t3.size() == 0) assert(0);
			int save = t3.back();
			t3.pop_back();
			for (int x : t3) calc(x, 1);
			ans.pb(v);
			calc(save, 0);
			for (int x : t1) calc(x, 0);
		}
	} else {
		if (t1.size() % 2 == 1){
			for (int x : t2) calc(x, 1);
			for (int x : t3) calc(x, 1);
			ans.pb(v);
			for (int x : t1) calc(x, 0);
		} else {
			for (int x : t2) calc(x, 1);
			if (t3.size() == 0) assert(0);
			int save = t3.back();
			t3.pop_back();
			for (int x : t3) calc(x, 1);
			ans.pb(v);
			calc(save, 0);
			for (int x : t1) calc(x, 0);
		}
	}
}

int main(){
   // freopen("input.txt", "r", stdin);
    //freopen("output1.txt", "w", stdout);
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    int root = -1;
    for (int i = 0; i < n; i++){
    	int x;
    	cin >> x;
    	if (x == 0) root = i;
    	else {
    		x--;
    		g[x].pb(i);
    		g[i].pb(x);
    	}
    }
    if (root == -1) assert(0);
    dfs(root, -1);
    if (dp[root][0] == 0) cout << "NO", exit(0);
    cout << "YES\n";
    calc(root, 0);
    for (int x : ans) cout << x + 1 << ' ';
}