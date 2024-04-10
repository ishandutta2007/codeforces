
//be naame khodaa
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
#define F first
#define S second
#define pb push_back

inline int in(){ int x, y; y = scanf("%d", &x); return x; }

const int MAXN = 1e5 + 10;

int n, m, x[MAXN], sec[MAXN], sz;
pii a[MAXN], b[MAXN], seg[MAXN];
ll fen[MAXN];
int comp[MAXN], gec[MAXN];

void add(int v, int val){for (v++; v<MAXN; v+=v&-v) fen[v] += val;}
ll get(int v){
	ll ret = 0;
	for (; v; v-=v&-v) ret += fen[v];
	return ret;
}

bool cmp(int u, int v){return a[u].S < a[v].S;}

set<int> st;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> x[i];
	for (int i = 0; i < m; i++) cin >> a[i].F;
	for (int i = 0; i < m; i++) cin >> a[i].S;
	sort(a, a + m);
	for (int i = 0; i < n; i++)
		b[i] = {upper_bound(a, a + m, make_pair(x[i]+1, -1)) - a, x[i]};
	int mx = -1;
	for (int i = n-1; ~i; i--)
		if (b[i].F > mx) {
			sec[sz++] = i;
			mx = b[i].F;
		}
	int tl = 0;
	memset(comp, -1, sizeof(comp));
	for (int i = 0; i < sz; i++){
		seg[i].F = tl;
		seg[i].S = b[sec[i]].F;
		tl = seg[i].S;
		for (int j = seg[i].F; j < seg[i].S; j++)
			comp[j] = sec[i];
	}
	for (int i = 0; i < n; i++) add(i, b[i].S);
	iota(gec, gec + m, 0);
	sort(gec, gec + m, cmp);
	int ans = 0;
	for (int i = 0; i < n; i++) st.insert(i);
	for (int i = 0; i < m; i++){
		int id = gec[i];
		int cm = comp[id];
		if (cm == -1) continue;
		if (get(cm+1) >= a[id].S) {
			ans++;
			int rem = a[id].S;
			while (rem){
				auto it = st.upper_bound(cm);
				it--;
				int g = min(rem, b[*it].S);
				add(*it, -b[*it].S);
				rem -= g;
				b[*it].S -= g;
				add(*it, b[*it].S);
				if (b[*it].S == 0)
					st.erase(*it);
			}
		}
	}
	cout << ans << endl;
	return 0;
}