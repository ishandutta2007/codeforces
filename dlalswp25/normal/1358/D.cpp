#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll D[404040];
ll S[404040];
ll S2[404040];
ll ans;
int sm, sd, em, ed;

ll f(ll x) {
	return x * (x + 1) / 2;
}

void upd() {
	// printf("%d %d %d %d\n", sm, sd, em, ed);
	ans = max(ans, f(ed) + S2[em - 1] - S2[sm] + f(D[sm]) - f(sd - 1));
}

int main() {
	int N; ll X;
	scanf("%d%lld", &N, &X);
	for(int i = 1; i <= N; i++) scanf("%lld", &D[i]);
	for(int i = N + 1; i <= 2 * N; i++) D[i] = D[i - N];

	for(int i = 1; i <= 2 * N; i++) {
		S[i] = S[i - 1] + D[i];
		S2[i] = S2[i - 1] + f(D[i]);
	}

	sm = 1, sd = 1;
	ll d = 0;
	for(int i = 1; i <= N; i++) {
		d += D[i];
		if(d >= X) { ed = D[i] - (d - X); em = i; break; }
	}

	ans = 0;
	while(sm <= N) {
		upd();
		if(sd == D[sm]) {
			upd();
			sd = 1; sm++;
			if(ed == D[em]) {
				ed = 1; em++;
			}
			else ed++;
			continue;
		}
		else if(ed == D[em]) {
			upd();
			ed = 1; em++;
			sd++;
			continue;
		}

		if(D[em] - ed < D[sm] - sd) {
			sd += (D[em] - ed);
			ed = D[em];
			upd();
			sd++; ed = 1; em++;
		}
		else if(D[em] - ed == D[sm] - sd) {
			sd = D[sm];
			ed = D[em];
			upd();
			sd = 1; sm++;
			ed = 1; em++;
		}
		else {
			ed += (D[sm] - sd);
			sd = D[sm];
			upd();
			ed++;
			sd = 1; sm++;
		}
	}
	printf("%lld\n", ans);

	return 0;
}