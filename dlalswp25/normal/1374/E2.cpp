#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, int> pii;

const ll INF = 1LL << 60;

ll T[202020];
int X[202020];
int Y[202020];

int an, bn, cn, dn;
int pa, pb, pd;
ll s;
pii A[202020];
pii B[202020];
pii C[202020];
pii D[202020];

int N, M, K;

int apa, apb, apc, apd;

 bool go(int pc) {
	ll va = (pa > an ? INF : A[pa].first);
	ll vb = (pb > bn ? INF : B[pb].first);
	ll vd = (pd > dn ? INF : D[pd].first);

	ll mn = min(va, min(vb, vd));
	if(mn == INF) return false;

	int c = 0;
	if(pc + pa <= K) {
		if(va == INF) return false;
		c++; s += va; pa++;
	}
	if(pc + pb <= K) {
		if(vb == INF) return false;
		c++; s += vb; pb++;
	}

	if(c == 1) return true;
	if(c == 2) {
		if(pd == 1) return false;
		s -= D[pd - 1].first;
		pd--;
		return true;
	}

	if(mn == va) { s += va; pa++; }
	else if(mn == vb) { s += vb; pb++; }
	else { s += vd; pd++; }

	return true;
}

int main() {
	scanf("%d%d%d", &N, &M, &K);
	for(int i = 1; i <= N; i++) {
		scanf("%d%d%d", &T[i], &X[i], &Y[i]);
		if(X[i] && Y[i]) C[++cn] = {T[i], i};
		else if(X[i]) A[++an] = {T[i], i};
		else if(Y[i]) B[++bn] = {T[i], i};
		else D[++dn] = {T[i], i};
	}

	if(an + cn < K || bn + cn < K) {
		puts("-1");
		return 0;
	}

	sort(A + 1, A + an + 1);
	sort(B + 1, B + bn + 1);
	sort(C + 1, C + cn + 1);
	sort(D + 1, D + dn + 1);

	// puts("************");
	// for(int i = 1; i <= an; i++) printf("%d ", A[i]); puts("");
	// for(int i = 1; i <= bn; i++) printf("%d ", B[i]); puts("");
	// for(int i = 1; i <= cn; i++) printf("%d ", C[i]); puts("");
	// for(int i = 1; i <= dn; i++) printf("%d ", D[i]); puts("");

	ll ans = INF;
	ll sc = 0;

	cn = min(cn, M);

	for(int i = 1; i <= cn; i++) sc += C[i].first;
	pa = pb = pd = 1;
	
	int cnt = 0;
	while(pa + cn <= K) {
		s += A[pa].first; cnt++; pa++;
	}
	while(pb + cn <= K) {
		s += B[pb].first; cnt++; pb++;
	}

	if(cn + cnt > M) { puts("-1"); return 0; }

	// printf("ps %d %d %d\n", pa, pb, pd);

	for(int i = 0; i < M - cn - cnt; i++) {
		go(cn);
	}

	// printf("ps %d %d %d\n", pa, pb, pd);

	for(int i = cn; i >= 0; i--) {
		if(ans > sc + s) {
			apa = pa; apb = pb; apc = i + 1; apd = pd;
			ans = sc + s;
		}
		// printf("%d %lld\n", i, ans);
		sc -= C[i].first;
		if(i == 0 || !go(i - 1)) break;
	}
	if(ans == INF) { puts("-1"); return 0; }
	printf("%lld\n", ans);
	for(int i = 1; i < apa; i++) printf("%d ", A[i].second);
	for(int i = 1; i < apb; i++) printf("%d ", B[i].second);
	for(int i = 1; i < apc; i++) printf("%d ", C[i].second);
	for(int i = 1; i < apd; i++) printf("%d ", D[i].second);
	puts("");
	return 0;
}

/*
4 2 2
1 1 0
2 1 1
3 1 0
4 1 1
*/