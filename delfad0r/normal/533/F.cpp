#include <bits/stdc++.h>

using namespace std;

typedef pair< int, int > ii;
typedef long long ll;

char Ts[200100], Ps[200100];
int T[200100], P[200100];
int b[200100];
int N, M;

const int prime = 1000000007;

template< int p >
class fen_t {
	int ft[200100];
	public:
	int query(int w) {
		int sum = 0;
		for(; w; w -= w & (-w))
			sum = (sum + ft[w]) % p;
		return sum;
	}
	void update(int w, ll v_) {
		int v = ((v_ % p) + p) % p;
		for(; w <= N; w += w & (-w))
			ft[w] = (ft[w] + v) % p;
	}
};

fen_t< prime > ft;

int last_occ[300];
void s_to_i(char * S, int * I, int L) {
	memset(last_occ, -1, sizeof(last_occ));
	for(int i = 0; i < L; ++i) {
		if(last_occ[S[i]] != -1)
			I[i] = i - last_occ[S[i]];
		else I[i] = 0;
		last_occ[S[i]] = i;
	}
}

ll fast_pow(ll b, int p) {
	ll ans = 1;
	while(p) {
		if(p & 1) ans = (ans * b) % prime;
		b = (b * b) % prime;
		p >>= 1;
	}
	return ans;
}

int my_partner[26];
int main() {
	ios_base::sync_with_stdio(false);
	
	vector< int > ans;
	cin >> N >> M;
	cin >> Ts >> Ps;
	s_to_i(Ts, T, N);
	s_to_i(Ps, P, M);
	ll hashP = 0;
	for(int m = 0; m < M; ++m)
		hashP = (hashP + fast_pow(2, m) * P[m]) % prime;
	for(int n = 0; n < N; ++n)
		ft.update(n + 1, fast_pow(2, n) * T[n]);
	priority_queue< ii, vector< ii >, greater< ii > > Q;
	for(int m = 0; m < M - 1; ++m)
		if(T[m] != 0) Q.emplace(m - T[m], m);
	for(int n = 0; n + M <= N; ++n) {
		if(T[n + M - 1] != 0) Q.emplace(n + M - 1 - T[n + M - 1], n + M - 1);
		while(Q.size() && Q.top().first < n) {
			int x = Q.top().second;
			Q.pop();
			ft.update(x + 1, - fast_pow(2, x) * T[x]);
		}
		if(hashP != (ll(((ft.query(n + M) - ft.query(n)) + prime) % prime) * fast_pow(fast_pow(2, n), prime - 2)) % prime)
			continue;
		memset(my_partner, -1, sizeof(my_partner));
		bool ok = true;
		for(int c = 0; c < 26; ++c) {
			if(last_occ[c + 'a'] == -1) continue;
			if((my_partner[c] != -1 && my_partner[c] != Ts[n + last_occ[c + 'a']] - 'a')
				|| (my_partner[Ts[n + last_occ[c + 'a']] - 'a'] != -1 && my_partner[Ts[n + last_occ[c + 'a']] - 'a'] != c)) {
					ok = false;
					break;
			}
			if(my_partner[c] == -1) {
				my_partner[c] = Ts[n + last_occ[c + 'a']] - 'a';
				my_partner[my_partner[c]] = c;
			}
		}
		if(ok) ans.push_back(n);
	}
	cout << ans.size() << '\n';
	for(int x : ans)
		cout << x + 1 << ' ';
}