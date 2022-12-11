#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef pair<ll, ll> pi;
typedef vector<pi> vpi;

void actu(int x, ll k, vi& F) {
	int ind = x+1;
	while (ind < F.size()) {
		F[ind] += k;
		ind += (-ind)&ind;
	}
}

ll que(int x, vi& F) {
	int ind = x+1;
	ll res = 0;
	while (ind) {
		res += F[ind];
		ind -= (-ind)&ind;
	}
	return res;
}

struct cosa {
	int t;
	ll cost;
	ll num;
};

bool comp(cosa a, cosa b) {
	return a.t < b.t;
}

const int N = 1e6 + 10;

int main(){
	cout.setf(ios::fixed);
	cout.precision(15);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k, m;
	cin >> n >> k >> m;
	vi F1(m + 10, 0);	
	vi F2(m + 10, 0);
	vector<cosa> V(2*m + 1);
	vi S;
	for (int i = 0; i < m; ++i) {
		cin >> V[2*i].t >> V[2*i+1].t;
		cin >> V[2*i].num >> V[2*i].cost;
		V[2*i+1].num = -V[2*i].num;
		V[2*i+1].cost = V[2*i].cost;
		++V[2*i+1].t;
		S.push_back(V[2*i].cost);
	}
	sort(S.begin(), S.end());
	map<int, int> M;
	for (int i = 0; i < m; ++i) {
		if (!M.count(S[i])) 
			M[S[i]]= i;
	}
	for (int i = 0; i < m; ++i) {
		V[2*i+1].cost = M[V[2*i].cost]++;
		V[2*i].cost = V[2*i+1].cost;
	}
	V.back().t = n + 1;
	sort(V.begin(), V.end(), comp);
	ll ant = -1;
	int i = 0;
	ll res = 0;
	while (i < 2*m) {
		ant = V[i].t;
		while (i < 2*m and V[i].t == ant) {
			actu(V[i].cost, V[i].num, F1);
			actu(V[i].cost, V[i].num*S[V[i].cost], F2);
			++i;
		}
		ll a = -1;
		ll b = m;
		while (a + 1 < b) {
			int c = (a+b)/2;
			ll suma = que(c, F1);
			if (suma >= k) b = c;
			else a = c;
		}
		ll num1 = que(a, F1);
		ll num = que(b, F1) - num1;
		ll rest = que(a, F2);
		if (b < m) rest += min(num, k - num1)*S[b];
		res += rest*(V[i].t - ant);
	}
	cout << res << '\n';
}