#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define ss(x) (int) x.size()
#define pb push_back
#define ll long long
#define cat(x) cerr << #x << " = " << x << endl
#define FOR(i, n) for(int i = 0; i < n; ++i)

using namespace std;	

int n;
char s[200111];
int pref[200111];
int one[200111];
int pie = 0;

unordered_map <int,int> mapa;

ll ans;
			
int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	pie = 350;
	for(int i = 1; i <= n; ++i)
		pref[i] = pref[i - 1] + (s[i] == '1');
	for(int i = 1; i <= pie; ++i) {
		mapa.clear();
		for(int j = 0; j <= n; ++j) {
			int val = i * pref[j] - j;
			ans += mapa[val];
			mapa[val]++;
		}
	}
		
	
	int last = n + 1;
	for(int i = n; 0 <= i; --i) {
		one[i] = last;
		if(s[i] == '1')
			last = i;
	}
	for(int i = 0; i <= n; ++i) {
		int j = one[i];
		int steps = (n + 1) / pie;
		int sum = 0;
		int par;
		int L, LL;
		int R, RR;
		while(steps > 0 && j <= n) {
			sum++;
			par = i % sum;
			L = j;
			R = one[j] - 1;
			L = max(j, pie * sum + i + 1);
			LL = (L % sum <= par ? L + (par - L % sum) : L + (sum - L % sum) + par);
			RR = (par <= R % sum ? R - (R % sum - par) : R - (R % sum - par) - sum);
			if(LL <= RR)
				ans += 1 + (RR - LL) / sum;
			j = one[j];
			steps--;
		}
	}
	printf("%lld", ans);
			
			
	
	
	
	return 0;
}