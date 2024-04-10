#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define F first
#define S second

const int MOD = 1e9 + 7;//XXX
const int C = 26;//XXX
const ll INF = (ll)1e18 + 100;

void add(int &x, int y){
	x += y;
	while (x >= MOD) x -= MOD;
	while (x < 0) x += MOD;
}

int fix(int x){
	while (x >= MOD) x -= MOD;
	while (x < 0) x += MOD;
	return x;
}

int pw(int a, int b){
	int ret = 1;
	while (b){
		if (b & 1)
			ret = 1ll*ret*a%MOD;
		b >>= 1;
		a = 1ll*a*a%MOD;
	}
	return ret;
}

const int MAXN = 1e3 + 5;

int tr[MAXN*MAXN][C], sz;
int n, m;
ll k;
string s;

void insert(int i) {
	int cur = 0;
	for (; i < n; i++) {
		int z = s[i] - 'a';
		if (!tr[cur][z])
			tr[cur][z] = ++sz;
		cur = tr[cur][z];
	}
}

int sec[MAXN*MAXN], tt;
int par[MAXN*MAXN], ch[MAXN*MAXN];
void dfs(int v, int p = -1, int c = -1) {
	if (v)
		sec[tt++] = v;
	ch[v] = c;
	par[v] = p;
	for (int w = 0; w < C; w++)
		if (tr[v][w])
			dfs(tr[v][w], v, w);
}

string getS(int id) {
	string t;
	while (id) {
		t += char(ch[id] + 'a');
		id = par[id];
	}
	reverse(t.begin(), t.end());
	return t;
}

ll dp[MAXN][MAXN], pt[MAXN][MAXN];
ll count(int v) {
	string t = getS(v);
	int ln = t.size();

	memset(dp, 0, sizeof(dp));
	dp[n][0] = 1;
	pt[n][0] = 1;
	for (int i = n-1; ~i; i--) {
		int j = i;
		bool failed = true;
		while (j < n && j-i < ln) {
			if (t[j-i] < s[j]) {
				j++;
				failed = false;
				break;
			} else if (t[j-i] == s[j]) {
				j++;
				if (j-i == ln)
					failed = false;
			} else {
				break;
			}
		}

		if (!failed) {
			for (int w = 1; w <= m; w++)
				dp[i][w] = pt[j][w-1];
		}

		for (int j = 0; j <= m; j++)
			pt[i][j] = min(INF, pt[i+1][j] + dp[i][j]);
	}
	return dp[0][m];
}

void solve() {
	cin >> n >> m >> k;
	cin >> s;
	for (int i = 0; i < n; i++)
		insert(i);
	dfs(0);
	
	reverse(sec, sec + tt);
	//for (int i = 0; i < tt; i++)
	//	cout << sec[i] << " " << getS(sec[i]) << "    ";
	//cout << endl;
	//cout << sec[4] << "  " << getS(4) << " " << count(sec[4]) << endl;
	int lo = 0, hi = tt;
	while (hi - lo > 1){
		int mid = hi+lo>>1;
		if (count(sec[mid-1]) < k)
			lo = mid;
		else
			hi = mid;
	}
	//cout << lo << endl;
	cout << getS(sec[lo]) << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//cout << fixed << setprecision(6);
	
	int te = 1;	
	//cin >> te;
	for (int w = 1; w <= te; w++){
		//cout << "Case #" << w << ": ";
		solve();
	}
	return 0;
}