#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define fio ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;

const ll M = 1e9+7;
map<ll,int> m;

ll id(ll a) {
	ll b = 1;
	for(ll i = 2; i*i <= a; ++i) {
		int e = 0;
		while(a%i == 0) {
			++e, a/=i;
		}
		if(e&1) b*=i;
	}
	if(a != 1)
		b *= a;
	return b;
}

const int N = 305;
ll DP[N][N];
int C[N]={},spaces[N];

ll Comb[N][N];

ll fct(int a) {
	if(a == 0) return 1;
	return a * fct(a-1) % M;
}

int main() {	
	fio;
	Comb[0][0] = 1;
	for(int i = 1;i < N; ++i) {
		Comb[i][0] = Comb[i][i] = 1;
		for(int j = 1; j < i; ++j) {
			Comb[i][j] = (Comb[i-1][j-1] + Comb[i-1][j]) % M;
		}
	}
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		ll a;
		cin >> a;
		++m[id(a)];
	}
	int sz = 0;
	C[0] = 1;
	for(auto &p : m) {
		C[++sz] = p.second;
	}
	for(int i = 0; i <= sz; ++i) {
		spaces[i] = 0;
		if(i != 0) spaces[i] += spaces[i-1];
		spaces[i] += C[i];
	}
	DP[0][0] = 1;
	for(int i = 1; i < N; ++i) DP[0][i] = 0;

	for(int x = 1; x <= sz; ++x) {
		for(int ij = 0; ij <= C[x]; ij++)   //ij = i+j as described
		    for(int y = 0; y <= spaces[x-1]; y++)
		        if(DP[x-1][y] > 0)
		            for(int j = 0; j <= min(ij, y); j++) {
		                int i = ij-j;
		                int z = spaces[x-1] - y;
		                DP[x][(y-j) + (C[x]-ij)] += DP[x-1][y] * Comb[y][j] % M * Comb[z][i] % M * Comb[C[x]-1][ij-1] % M;
		                DP[x][(y-j) + (C[x]-ij)] %= M;

		            }
	}
	ll ans = DP[sz][0];
	for(int i = 1; i <= sz; ++i)
		ans = ans * fct(C[i]) % M;
	cout << ans << endl;
	

}