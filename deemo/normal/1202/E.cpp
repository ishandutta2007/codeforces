#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

#define F first
#define S second

const int MOD = 1e9 + 7;//XXX
const int C = 26;//XXX

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

const int MAXN = 2e5 + 10;

int n, pos[MAXN], nxt[MAXN][C], sz, f[MAXN];
string t[MAXN];
vector<int> adj[MAXN];

int insert(string &s){
    int cur = 0;
    for (char c:s){
        int x = int(c - 'a');
        if (!nxt[cur][x])
            nxt[cur][x] = ++sz;
        cur = nxt[cur][x];
    }
    return cur;
}

int q[MAXN];
void buildAho(){
    int h = 0, t = 0;
    for (int w = 0; w < C; w++)
        if (nxt[0][w])
            q[t++] = nxt[0][w];

    while (t^h){
        int v = q[h++];
		if (v)
			adj[f[v]].push_back(v);
        for (int w = 0; w < C; w++)
            if (nxt[v][w]){
                f[nxt[v][w]] = nxt[f[v]][w];
                q[t++] = nxt[v][w];
            }
            else
                nxt[v][w] = nxt[f[v]][w];
    }
}

#define tm saldkfj

int cv[MAXN];
int cntUp[MAXN];
int st[MAXN], ft[MAXN], tm;

const int SQ = 110;

int cntLen[MAXN];
ll ans = 0;
int actLen[MAXN];
vector<int> vec[MAXN];

void dfs(int v, int cnt = 0){
	st[v] = tm++;
	cnt += cv[v];
	cntUp[v] = cnt;
	for (int u: adj[v])
		dfs(u, cnt);
	ft[v] = tm;
}


void dfsAdd(int v, int ln, int zz){
	for (int x: vec[v])
		ans += 1ll*zz*cntLen[max(x-ln, 0)];
	for (int u: adj[v])
		dfsAdd(u, ln, zz);
}

ll pt[MAXN][SQ];
void dfsAns(int v){
	if (cv[v]){
		if (actLen[v] >= SQ){
			dfsAdd(v, actLen[v], cv[v]);
		}
		else{
			ans += 1ll * cv[v] * (pt[ft[v]][actLen[v]] - pt[st[v]][actLen[v]]);
		}
	}
	for (int u: adj[v])
		dfsAns(u);
}

void dfs2(int v){
	for (int i = 0; i < SQ; i++)
		pt[st[v]+1][i] = pt[st[v]][i];
	for (auto x: vec[v])
		for (int i = 0; i < SQ; i++)
			pt[st[v]+1][i] += cntLen[max(0, x - i)];
	for (int u: adj[v])
		dfs2(u);
}

void solve() {
	string s;
	cin >> s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t[i];
		pos[i] = insert(t[i]);
		cv[pos[i]]++;
		actLen[pos[i]] = t[i].size();
	}
	buildAho();
	dfs(0);

	int cur = 0;
	for (int i = 0; i < (int)s.size(); i++) {
		cur = nxt[cur][s[i] - 'a'];
		cntLen[i+1] = cntUp[cur];
		vec[cur].push_back(i + 1);
	}
	dfs2(0);
	dfsAns(0);
	cout << ans << "\n";
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