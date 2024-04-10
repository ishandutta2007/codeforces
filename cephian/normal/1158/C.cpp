#include <bits/stdc++.h>
#define print(x) cerr << #x << " = " << x << endl;
using namespace std;
typedef long long ll;

const int N = 5e5+5;
int nxt[N];

//point SET update, range MIN query
template <class T>
struct segt {
	int N;
	vector<T> t,m;
	segt(int N):N(N),t(2*N){}

	constexpr static T NONE = numeric_limits<T>::min(); //min()
	static inline T combine(T a, T b) {return max(a,b);}

	//update point i
	void update(int i, T val) {
		for(t[i+=N] = val;i>1;i>>=1)
			t[i>>1] = combine(t[i],t[i^1]);
	}

	//query range [l,r]
	T query(int l, int r) const {
		T ans = NONE;
		for(l+=N,r+=N+1;l<r;l>>=1,r>>=1) {
			if(l&1) ans = combine(ans,t[l++]);
			if(r&1) ans = combine(ans,t[--r]);
		}
		return ans;
	}
};

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> prev(n+2);
	for(int i = 1; i <= n; ++i) {
		cin >> nxt[i];
		if(nxt[i] != -1)
			prev[nxt[i]].push_back(i);
	}
	vector<int> ans(n+2, 0);
	segt<int> seg(n+2);
	int ctr = n;
	ans[n+1] = n+1;
	for(int i = n+1; i >= 1; --i) {
		if(prev[i].size() && ans[i] == 0)
			ans[i] = ctr--;
		for(int x : prev[i])
			ans[x] = ctr--;
	}
	for(int i = 1; i <= n; ++i)
		if(ans[i] == 0)
			ans[i] = ctr--;
	for(int i = 1; i <= n; ++i)
		seg.update(i, ans[i]);

	// check segments
	for(int i = 1; i <= n; ++i) {
		if(nxt[i] != -1 && seg.query(i+1, nxt[i]-1) > ans[i]) {
			cout << "-1\n";
			return;
		}
	}
	for(int i = 1; i <= n; ++i)
		cout << ans[i] << ' ';
	cout << '\n';

}

int main() {	
	ios::sync_with_stdio(0), cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		solve();
	}
}