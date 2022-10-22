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

const int MAXN = 1e5 + 10;

int n, m;
set<pii> st[2];
int nxt[2][MAXN], tl[2][MAXN], tr[2][MAXN], a[MAXN];
vector<pii> events[2][MAXN];

void trim_left(int w, pii range) {
    while (st[w].size()) {
        auto x = *st[w].begin();
        if (x.F >= range.F) return;

        st[w].erase(st[w].begin());
    }
}

void trim_right(int w, pii range) {
    while (st[w].size()) {
        auto x = *st[w].rbegin();
        if (x.F <= range.S) return;

        st[w].erase(x);
    }
}

int p[2][MAXN];
void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cin >> tl[0][i] >> tr[0][i];
        cin >> tl[1][i] >> tr[1][i];
    }
    nxt[0][n] = nxt[1][n] = n;
    for (int i = n-1; ~i; i--) {
        for (int w = 0; w < 2; w++)
            if (tl[w][i] <= a[i] && a[i] <= tr[w][i])
                nxt[w][i] = nxt[w][i+1];
            else
                nxt[w][i] = i;
    }
    
    st[0].insert({0, -2});
    events[0][nxt[1][0]].push_back({0, -2});
    st[1].insert({0, -2});
    events[1][nxt[0][0]].push_back({0, -2});
    memset(p, -1, sizeof(p));
    for (int i = 0; i < n; i++) {
        for (int w = 0; w < 2; w++) {
            trim_left(w, {tl[w][i], tr[w][i]});
            trim_right(w, {tl[w][i], tr[w][i]});
            for (auto ev: events[w][i])
                st[w].erase(ev);
        }
        bool mark[2] = {!st[0].empty(), !st[1].empty()};
        int t[2];
        if (st[0].size())
            t[0] = st[0].begin()->S;
        if (st[1].size())
            t[1] = st[1].begin()->S;
        for (int w = 0; w < 2; w++)
            if (mark[!w]) {
                p[w][i] = t[!w];
                st[w].insert({a[i], i});
                events[w][nxt[!w][i+1]].push_back({a[i], i});
            }

        if (p[0][i] == -1 && p[1][i] == -1) {
            cout << "No\n";
            return;
        }
    }
    cout << "Yes\n";
    vector<int> ans;
    int cur = n-1, hand = p[0][n-1]==-1? 1: 0;
    while (cur >= 0) {
        ans.push_back(cur);
        cur = p[hand][cur];
        hand ^= 1;
    }
    reverse(ans.begin(), ans.end());
    hand ^= 1;
    int lst = -1;
    for (auto x: ans) {
        for (int i = lst+1; i <= x; i++)
            cout << hand << " ";
        hand ^= 1;
        lst = x;
    }
    cout << "\n";
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