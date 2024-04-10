#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, j, n) for(int i = j; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl;
#define ios cin.tie(0); ios_base::sync_with_stdio(0)	
	
		
using namespace std;

const int nax = 100111;
const int N = 2601;

char s[nax];
int n;
int ile[26];
int L[nax][26];
int R[nax][26];
int last[26];
int dp[N][N];
pair<int, int> opt[N][N];
int lit[N][N];
vector <int> Fi, Se;

int main() {	
	scanf("%s", s);
	n = strlen(s);
	FOR(i, 0, n - 1) {
		ile[s[i] - 'a'] += 1;
	}
	FOR(i, 0, 25) {
		if(ile[i] >= 100) {
			FOR(g, 1, 100) {
				printf("%c", (char) ('a' + i));
			}
			return 0;
		}
	}
	FOR(i, 0, 25)
		last[i] = -1;
	FOR(i, 0, n - 1) {
		FOR(j, 0, 25)
			L[i][j] = last[j];
		last[s[i] - 'a'] = i;
	}
	FOR(i, 0, 25)
		last[i] = n;
	for(int i = n - 1; 0 <= i; --i) {
		FOR(j, 0, 25)
			R[i][j] = last[j];
		last[s[i] - 'a'] = i;
	}
	
	FOR(i, 0, n - 1) {
		dp[i][i] = 1;
		lit[i][i] = s[i] - 'a';
		if(L[i][s[i] - 'a'] >= 0) {
			dp[L[i][s[i] - 'a']][i] = 2;
			lit[L[i][s[i] - 'a']][i] = s[i] - 'a';
		}
	}
	FOR(len, 1, n) {
		FOR(pocz, 0, n - len) {
			int kon = pocz + len - 1;
			FOR(j, 0, 25) {
				int Left = L[pocz][j];
				int Right = R[kon][j];
				if(0 <= Left && Right < n && dp[Left][Right] < dp[pocz][kon] + 2) {
					dp[Left][Right] = dp[pocz][kon] + 2;
					lit[Left][Right] = j;
					opt[Left][Right] = mp(pocz, kon);
				}
			}
		}
	}
	
	int naj = -1;
	int LL = -1, RR = -1;
	FOR(i, 0, n - 1)
		FOR(j, i, n - 1) {
			if(dp[i][j] > naj) {
				naj = dp[i][j];
				LL = i;
				RR = j;
			}
		}
	int best = naj;
	while(naj) {
		//cout << LL << " " << RR << " " << lit[LL][RR] << " " << dp[LL][RR] << endl;
		if(dp[LL][RR] == 1) {
			Se.pb(lit[LL][RR]);
			naj -= 1;
		}
		else {
			Fi.pb(lit[LL][RR]);
			int nL = opt[LL][RR].fi;
			int nR = opt[LL][RR].se;
			LL = nL;
			RR = nR;
			naj -= 2;
		}
	}
	
	if(best >= 100 && best % 2 == 1) {
		best -= 1;
		Se.clear();
	}
	while(best > 100) {
		Fi.pop_back();
		best -= 2;
	}
	for(auto it : Fi)
		printf("%c", (char) ('a' + it));
	for(auto it : Se)
		printf("%c", (char) ('a' + it));
	reverse(Fi.begin(), Fi.end());
	for(auto it : Fi)
		printf("%c", (char) ('a' + it));	
	
	
	
	
	
	
	
		
			
	return 0;
}