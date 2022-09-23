#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MX = 5000;

int N;
int cnt[5050];
bool notprime[5050];

vector<int> primes;
int pcnt[5050][707];
int rsum[5050][707];
int pidx[5050];
int P;

vector<int> raw[5050];

void init() {
	for(int i = 2; i <= MX; i++) {
		if(notprime[i]) continue;
		for(int j = i * i; j <= MX; j += i) notprime[j] = true;
	}

	int c = 0;
	
	for(int i = 2; i <= MX; i++) if(!notprime[i]) {
		pidx[i] = c; c++;
		primes.push_back(i);
	}
	P = primes.size();

	for(int i = 2; i <= MX; i++) {
		for(int j = 0; j < P; j++) pcnt[i][j] = pcnt[i - 1][j];
		int x = i;

		int p = 0;
		for(int j = P - 1; j >= 0; ) {
			if(x % primes[j]) {
				while(p < raw[i - 1].size() && raw[i - 1][p] == j) {
					p++; raw[i].push_back(j);
				}
				j--; continue;
			}
			x /= primes[j]; pcnt[i][j]++;
			raw[i].push_back(j);
		}

		for(int j = P - 1; j >= 0; j--) {
			rsum[i][j] = rsum[i][j + 1] + pcnt[i][j];
		}
	}
}

int kth(int i, int k) {
	int l = 0, r = P - 1;
	while(l <= r) {
		int m = l + r >> 1;
		if(rsum[i][m] >= k) l = m + 1;
		else r = m - 1;
	}
	return r;
}

vector<int> cen;
vector<int> cand;
vector<int> ps[707];
int num[707];

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		int k; scanf("%d", &k);
		if(!k) k++;
		cnt[k]++;
	}

	init();

	for(int i = 1; i <= MX; i++) if(cnt[i]) cand.push_back(i);
	int last_p = 101010;

	for(int i = 1; ; i++) {
		for(int k : cand) {
			int t = kth(k, i);
			if(t != -1) {
				ps[t].push_back(k);
				num[t] += cnt[k];
			}
		}
		// printf("%d\n", i);

		int nxt = -1;
		for(int j = 0; j < P; j++) {
			if(num[j] * 2 >= N) {
				nxt = j; break;
			}
		}
		if(nxt == -1) break;
		cen.push_back(nxt);

		cand.clear();
		for(int j : ps[nxt]) cand.push_back(j);

		for(int j = 0; j < P; j++) {
			num[j] = 0; ps[j].clear();
		}
	}

	// for(int i : cen) printf("%d ", i);
	sort(cen.begin(), cen.end());
	reverse(cen.begin(), cen.end());

	// for(int i = 1; i <= 5; i++) {
	// 	for(int j : raw[i]) printf("%d ", j); puts("");
	// }

	ll ans = 0;
	for(int i = 1; i <= MX; i++) {
		int j = 0;
		while(1) {
			if(j == cen.size() || j == raw[i].size()) break;
			if(cen[j] != raw[i][j]) break;
			j++;
		}

		ans += (ll)cnt[i] * (cen.size() + raw[i].size() - 2 * j);
	}
	printf("%lld\n", ans);

	return 0;
}