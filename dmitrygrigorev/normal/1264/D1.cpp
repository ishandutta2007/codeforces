#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

const int mod = 998244353;

const int N = 3000;
int C[N][N], P[N][N];
int pwt[N];
int main(){
#ifdef LOCAL
	freopen("F_input.txt", "r", stdin);
	//freopen("F_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i=0; i < N; ++i){
		C[i][0] = 1, C[i][i] = 1;
		for (int j=1; j < i; ++j){
			C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
		}
	}

	for (int i=0; i < N; i++){
		P[i][i] = 1;
		for (int j=i-1; j >= 0; j--){
			P[i][j] = (P[i][j+1] + C[i][j]) % mod;
		}
	}

	string s;
	cin >> s;

	int ans = 0;

	int n = s.size();

	for (int i=0; i < n; ++i) {
		int cnt = 0, spec = 0;
		for (int j=0; j <= i; ++j){
			if (s[j] == '?') spec++;
			if (s[j] == '(') cnt++;
		}
		if (s[i] == ')') continue;
		if (s[i] == '?'){
			cnt++;
			spec--;
		}
		int kek = 0, tet = 0;
		for (int j=i+1; j < n; ++j){
			if (s[j] == '?') kek++;
			if (s[j] == ')') tet++;
		}

		for (int take=0; take <= spec; ++take) {
			int ways = C[spec][take];
			int need = max(0, cnt+take - tet);
			if (need > kek) continue;
			ways = ((ll) ways * P[kek][need]) % mod;
			ans = (ans+ways) % mod;
		}
	}

	reverse(s.begin(), s.end());

	for (int i=0;i<n;++i){
		if (s[i] == '(') s[i] = ')';
		else if (s[i] == ')') s[i] = '(';
	}

	for (int i=0; i < n; ++i) {
		int cnt = 0, spec = 0;
		for (int j=0; j <= i; ++j){
			if (s[j] == '?') spec++;
			if (s[j] == '(') cnt++;
		}
		if (s[i] == ')') continue;
		if (s[i] == '?'){
			cnt++;
			spec--;
		}
		int kek = 0, tet = 0;
		for (int j=i+1; j < n; ++j){
			if (s[j] == '?') kek++;
			if (s[j] == ')') tet++;
		}

		for (int take=0; take <= spec; ++take) {
			int ways = C[spec][take];
			int need = max(0, cnt+take - tet);
			if (need > kek) continue;
			ways = ((ll) ways * P[kek][need]) % mod;
			ans = (ans+ways) % mod;
		}
	}

	ans = ((ll) ans * ((mod+1)/2)) % mod;

	cout << ans;

}