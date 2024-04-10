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
#define bignum vector <int>
 
 
using namespace std;

const int nax = 6e5 + 111;

int n;
char s[nax], d[nax];
int pos = 1;
ll cost[nax];
int idd[nax];
bool bad[nax];
int len[nax];

int kmr[nax];
pair<int, int> ja[nax];
int sa[nax];
int f[nax];
int lcp[nax];
int L[nax], R[nax];

stack <pair<int, int>> stos;

void makekmr() {
	FOR(i, 1, pos)
		kmr[i] = s[i] - 'a';
	int pot = 0;
	int id = -1;
	while(id != pos) {
		FOR(i, 1, pos) {
			f[i] = i;
			if(i + (1 << pot) > pos)	
				ja[i] = mp(kmr[i], -1);
			else
				ja[i] = mp(kmr[i], kmr[i + (1 << pot)]);
		}
		sort(f + 1, f + pos + 1, [&](int a, int b) {
			return ja[a] < ja[b];
		});
		pair<int, int> last = mp(-2, -2);
		id = 0;
		FOR(i, 1, pos) {
			if(last != ja[f[i]])
				id += 1;
			kmr[f[i]] = id;
			last = ja[f[i]];
		}
		pot += 1;
	}
	
	FOR(i, 1, pos) 
		sa[kmr[i]] = i;
	int j = 0;
	FOR(i, 1, pos) {
		if(kmr[i] == pos) {
			j = 0;
			continue;
		}
		int g = sa[kmr[i] + 1];
		while(i + j <= pos && g + j <= pos && s[i + j] == s[g + j] && s[g + j] != '#')
			j += 1;
		lcp[kmr[i]] = j;
		j = max(0, j - 1);
	}
	
	FOR(i, 1, pos) {
		while(!stos.empty() && lcp[i] < stos.top().fi) {
			R[stos.top().se] = i;
			stos.pop();
		}
		stos.push(mp(lcp[i], i));
	}
	while(!stos.empty()) {
		R[stos.top().se] = pos;
		stos.pop();
	}
	for(int i = pos; 1 <= i; --i) {
		while(!stos.empty() && lcp[i] <	stos.top().fi) {
			L[stos.top().se] = i + 1;
			stos.pop();
		}
		stos.push(mp(lcp[i], i));
	}
	while(!stos.empty()) {
		L[stos.top().se] = 1;
		stos.pop();
	}
}
		
ll pref[nax];		
ll ans = 0;				
	

int main() {
	scanf("%d", &n);
	FOR(i, 1, n) {
		scanf("%s", d + 1);
		int le = strlen(d + 1);
		bad[pos] = 1;
		s[pos++] = '#';
		FOR(j, 1, le) {
			idd[pos] = i;
			len[pos] = le - j + 1;
			s[pos++] = d[j];
		}	
	}
	
	FOR(i, 1, n)
		scanf("%lld", &cost[i]);
	
	pos -= 1;
	
	makekmr();
	
	FOR(i, 1, pos) {
		pref[i] = pref[i - 1] + cost[idd[sa[i]]];
		//cout << lcp[i] << endl;
	}
	
	FOR(i, 1, pos) {
		if(bad[i])
			continue;
		if(len[sa[i]] > lcp[i] && len[sa[i]] > lcp[i - 1]) {
			ans = max(ans, (ll) cost[idd[sa[i]]] * len[sa[i]]);
		}
		ll sum = pref[R[i]] - pref[L[i] - 1];
		sum *= lcp[i];
		ans = max(ans, sum);
	}
	
	printf("%lld", ans);
	
	
	
	
	
	
	
	
		
		
	
	
	return 0;
}