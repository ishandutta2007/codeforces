#include<bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<vi> vvi;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vvi G(n);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		if ((b-a+n)%n > (a-b+n)%n) swap(a,b);
		int k1 = (b-a+n)%n;
		int k2 = (a-b+n)%n;
		G[k1].push_back(a);
		if (k1 == k2) G[k2].push_back(b);
	}
	vi sol(n,-1);
	int laa = -1;
	for (int j = 0; j < n; ++j) {
		if (!G[j].size()) continue;
		if (G[j].size() == 1) {
			cout << "No" << endl;
			return 0;
		}
		auto& V = G[j];
		sort(V.begin(), V.end());
		vi p,s;
		for (int i = 1; i < (int)V.size(); ++i) {
			p.push_back(V[i] - V[i-1]);
			if (i > 1) s.push_back(V[i]-V[i-1]);
		}
		s.push_back((V[0]-V.back()+n)%n);
		for (int i = 0; i < (int)p.size()-1; ++i) s.push_back(p[i]);
		vi acum(s.size());
		acum[0] = V[1] - V[0];
		for (int i = 1; i < (int)acum.size(); ++i) {
			acum[i] = acum[i-1];
			acum[i] = (acum[i] + s[i-1])%n;
		}
		vector<int> pi(p.size() + 1, 0);
		int k = 0;
		for (int i = 2; i <= p.size(); ++i) {
			while (k > 0 and p[i - 1] != p[k]) k = pi[k];
			if (p[i - 1] == p[k]) ++k;
			pi[i] = k;
		}
		k = 0;
		for (int i = 0; i < s.size(); ++i) {
			while (k > 0 and s[i] != p[k]) k = pi[k];
			if (p[k] == s[i]) ++k;
			if (k == p.size()) {
				k = pi[k];
				int ss = acum[i-(int)p.size()+1];
				if (sol[ss] == laa) sol[ss] = j;
			}
		}
		laa = j;
	}
	for (int i = 0; i < n; ++i) {
		if (sol[i] == laa) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
}