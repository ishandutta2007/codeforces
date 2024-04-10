#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int X[1010];
int Y[1010];
int N;
map<pii, int> mp;
map<pii, bool> chk;
map<pii, bool> tmp[1010];
ll s[1010101];

pii cnv(int x, int y) {
	if(y < 0) return cnv(-x, -y);
	if(y == 0 && x < 0) return cnv(-x, -y);
	return { x / gcd(abs(x), y), y / gcd(abs(x), y) };
}

vector<int> v;

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		scanf("%d%d", &X[i], &Y[i]);
	}

	for(int i = 1; i <= N; i++) {
		for(int j = 1; j < i; j++) {
			int dx = X[j] - X[i], dy = Y[j] - Y[i];
			pii g = cnv(dx, dy);
			if(tmp[i][g] || tmp[j][g]) {
				tmp[i][g] = tmp[j][g] = true;
				continue;
			}
			tmp[i][g] = tmp[j][g] = true;
			mp[g]++;
		}
	}

	for(int i = 1; i <= N; i++) {
		for(int j = 1; j < i; j++) {
			int dx = X[j] - X[i], dy = Y[j] - Y[i];
			pii g = cnv(dx, dy);
			if(chk[g]) continue;
			//printf("%d %d\n", g.first, g.second);
			chk[g] = true;
			v.push_back(mp[g]);
		}
	}

	//for(int i : v) printf("%d ", i); puts("");

	s[0] = v[0];
	for(int i = 1; i < v.size(); i++) {
		s[i] = s[i - 1] + v[i];
	}

	ll ans = 0;

	for(int i = (int)v.size() - 1; i >= 1; i--) {
		ans += s[i - 1] * v[i];
	}
	printf("%lld\n", ans);

	return 0;
}