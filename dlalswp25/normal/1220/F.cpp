#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N;
int A[202020];
int B[202020];
int L[202020];
int R[202020];
int P[202020];
int D[202020];

stack<pii> st;
vector<int> v[202020];

struct NODE {
	int v, lz;
}T[4 * 202020];

void propa(int idx, int s, int e) {
	T[idx].v += T[idx].lz;
	if(s != e) {
		T[idx << 1].lz += T[idx].lz;
		T[idx << 1 | 1].lz += T[idx].lz;
	}
	T[idx].lz = 0;
}

void upd(int idx, int s, int e, int p, int q, int x) {
	propa(idx, s, e);
	if(e < s || q < p || q < s || e < p) return;
	if(p <= s && e <= q) {
		T[idx].lz += x;
		propa(idx, s, e);
		return;
	}
	int m = s + e >> 1;
	upd(idx << 1, s, m, p, q, x);
	upd(idx << 1 | 1, m + 1, e, p, q, x);
	T[idx].v = max(T[idx << 1].v, T[idx << 1 | 1].v);
}

int get(int idx, int s, int e, int p, int q) {
	propa(idx, s, e);
	if(e < s || q < p || q < s || e < p) return 0;
	if(p <= s && e <= q) return T[idx].v;
	int m = s + e >> 1;
	return max(get(idx << 1, s, m, p, q), get(idx << 1 | 1, m + 1, e, p, q));
}

void init(int now) {
	if(D[now]) return;
	if(A[now] == 1) { D[now] = 1; return; }
	if(A[L[now]] < A[R[now]]) {
		init(R[now]);
		D[now] = D[R[now]] + 1;
		P[now] = R[now];
	}
	else {
		init(L[now]);
		D[now] = D[L[now]] + 1;
		P[now] = L[now];
	}
}

int main() {
	scanf("%d", &N);
	int sft;
	for(int i = 1; i <= N; i++) {
		scanf("%d", &B[i]);
		if(B[i] == 1) sft = i;
	}

	for(int i = 1; i <= N; i++) {
		A[i] = B[(i + sft - 1) % N + 1];
	}

	for(int i = 1; i <= N; i++) {
		while(st.size() && st.top().first > A[i]) {
			R[st.top().second] = i;
			st.pop();
		}
		st.push({A[i], i});
	}
	while(st.size()) st.pop();

	for(int i = N - 1; i >= 0; i--) {
		while(st.size() && st.top().first > A[i]) {
			L[st.top().second] = i;
			st.pop();
		}
		st.push({A[i], i});
	}

	for(int i = 1; i <= N; i++) if(!D[i]) init(i);
	//for(int i = 1; i <= N; i++) printf("%d ", R[i]); puts("");

	int mn = 0, mni = 0;
	for(int i = 1; i <= N; i++) {
		upd(1, 1, N, i, i, D[i]);
		mn = max(mn, D[i]);
	}

	for(int i = 1; i < N; i++) {
		upd(1, 1, N, i + 1, R[i] - 1, -1);
		upd(1, 1, N, L[i] + 1, i - 1, 1);
		int t;
		if(!L[i]) t = 1;
		else t = get(1, 1, N, L[i], L[i]);
		int ti = get(1, 1, N, i, i);
		//printf("%d %d\n", t, ti);
		upd(1, 1, N, i, i, t + 1 - ti);
		t = T[1].v;
		//printf("%d\n", t);
		if(t < mn) { mn = t; mni = i; }
	}
	printf("%d %d\n", mn, (sft + mni) % N); 

	return 0;
}