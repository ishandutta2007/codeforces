#include<bits/stdc++.h>
using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())

const int INF = int(1e9);

int n, c;
vector<int> a;

inline bool read() {
	if(!(cin >> n >> c))
		return false;
	a.assign(n, 0);
	fore(i, 0, n)
		assert(scanf("%d", &a[i]) == 1);
	return true;
}

vector<int> cntC;

int getCnt(int l, int r) {
	return cntC[r] - cntC[l];
}

vector< vector<int> > segs;
vector<int> lst;

int maxSegment(const vector<int> &s) {
	int mx = -INF;
	
	int bal = 0;
	fore(i, 0, sz(s)) {
		bal = max(0, bal + s[i]);
		mx = max(mx, bal);
	}
	return mx;
}

inline void solve() {
	cntC.assign(n + 1, 0);
	fore(i, 0, n)
		cntC[i + 1] = cntC[i] + (a[i] == c);
	
	int cntDif = *max_element(a.begin(), a.end()) + 1;
	segs.assign(cntDif, vector<int>());
	lst.assign(cntDif, -1);
	
	fore(i, 0, n) {
		segs[a[i]].push_back(-getCnt(lst[a[i]] + 1, i));
		lst[a[i]] = i;
		segs[a[i]].push_back(1);
	}
	fore(v, 0, cntDif)
		segs[v].push_back(-getCnt(lst[v] + 1, n));
		
	int ans = 0;
	fore(v, 0, cntDif) {
		if(v == c) continue;
		ans = max(ans, maxSegment(segs[v]));
	}
	
	cout << getCnt(0, n) + ans << endl;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	int tt = clock();
#endif
	cout << fixed << setprecision(15);
	
	if(read()) {
		solve();
		
#ifdef _DEBUG
		cerr << "TIME = " << clock() - tt << endl;
		tt = clock();
#endif
	}
	return 0;
}