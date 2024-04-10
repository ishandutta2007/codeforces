#include <bits/stdc++.h>
#define get jlklkl
#define int long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

struct Piece{
	vector<pair<int, int> > up, down;
};

Piece get(int l, int r) {
	Piece ans;

	for (int i=0; i < 62; ++i){
		int need = (1LL<<i);
		int ba = (1LL<<i)&l;
		if (need <= r-l+1 && ba != 0) {
			ans.up.push_back({l, need});
			//cout << "===== " << l << " " << need << endl;
			l += need;
		}
	}

	for (int i=61; i >= 0; i--) {
		int need = (1LL<<i);
		if (need <= r-l+1) {
			ans.down.push_back({l, need});
			//cout << "== " << l << " " << need << endl;
			l += need;
		}
	}

	reverse(ans.down.begin(), ans.down.end());

	//cout << "=====================\n";

	return ans;

}

vector<int> events;

void add(pair<int, int> a, pair<int, int> b){
	//cout << "=== " << a.first << " " << a.second << " " << b.first << " " << b.second << endl;
	int step = max(a.second, b.second);

	int A = (a.first)&(step-1), B = (b.first)&(step-1);
	a.first ^= A, b.first ^= B;
	events.push_back((a.first^b.first) * 2);
	events.push_back(((a.first^b.first) + step) * 2 + 1);
}

const int mod = 998244353;

int sum(int x) {
	int Q = x%mod;

	Q = (Q * (Q+1)) % mod;
	Q = (Q * ((mod+1)/2)) % mod;

	return Q;

}

main(){
#ifdef LOCAL
	freopen("M_input.txt", "r", stdin);
	//freopen("M_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<Piece> a, b;
	int n;
	cin >> n;
	for (int i=0;i<n;++i) {
		int l, r;
		cin >> l >> r;
		a.push_back(get(l, r));
	}

	cin >> n;
	for (int i=0;i<n;++i) {
		int l, r;
		cin >> l >> r;
		b.push_back(get(l, r));
	}

	for (int i=0; i < a.size(); ++i){
		for (int j=0; j < b.size(); ++j){
			int u1=0, u2 = 0, u3 = 0, u4 = 0;
			for (int val=0; val < 62; ++val) {
				int Q = (1LL<<val);

				vector<pair<int, int> > aindex, bindex;

				if (a[i].up.size() > 0) aindex.push_back(a[i].up[0]);
				if (a[i].down.size() > 0) aindex.push_back(a[i].down[0]);
				if (u1 < a[i].up.size() && a[i].up[u1].second == Q) aindex.push_back(a[i].up[u1++]);
				if (u2 < a[i].down.size() && a[i].down[u2].second == Q) aindex.push_back(a[i].down[u2++]);

				if (b[j].up.size() > 0) bindex.push_back(b[j].up[0]);
				if (b[j].down.size() > 0) bindex.push_back(b[j].down[0]);
				if (u3 < b[j].up.size() && b[j].up[u3].second == Q) bindex.push_back(b[j].up[u3++]);
				if (u4 < b[j].down.size() && b[j].down[u4].second == Q) bindex.push_back(b[j].down[u4++]);

				for (int e=0; e < aindex.size(); ++e) for (int f=0; f < bindex.size(); ++f){
					add(aindex[e], bindex[f]);
				}

			}
		}
	}

	int cur = 0;
	int ans=0;

	sort(events.begin(), events.end());

	for (int i=0; i < events.size(); ++i){
		if (cur > 0) {
			int L = events[i-1]/2, R = events[i]/2;
			//cout << "==== " << L << " " << R-1 << endl;
			ans += sum(R-1);
			ans = (ans - sum(L-1) + mod) % mod;
		}
		//cout << "=== " << (events[i]&1) << endl;
		if ((events[i]&1) == 0) cur++;
		else cur--;
	}

	cout << ans;

}