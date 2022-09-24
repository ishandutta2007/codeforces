#include <bits/stdc++.h>

using namespace std;

int P[303030], Q[303030], A[303030];
int n, pi, qi;

struct segtree{
	int T[1101010], M[1101010];
	void add(int p, int s, int e, int l, int r, int v)
	{
		if(l <= s && e <= r) T[p] += v, M[p] += v;
		else if(l <= e && s <= r){
			add(p << 1, s, s + e >> 1, l, r, v);
			add(p << 1 | 1, s + e + 2 >> 1, e, l, r, v);
			M[p] = min(M[p << 1], M[p << 1 | 1]) + T[p];
		}
	}
	void add(int p, int v) {
		add(1, 1, n, 1, p, v); }
	
	bool yeah() { return M[1] < 0; }
};

segtree T;

void dnc(int s, int e, int l, int r)
{
	if(s > e) return;
	int m, t; m = s + e >> 1;
	for(; qi > m; ) if(-- qi > 0) T.add(Q[qi], -1);
	for(; qi < m; ) if(qi ++ > 0) T.add(Q[qi - 1], 1);
	if(pi <= l){
		for(; pi < l; ) T.add(P[pi ++], 1);
		for(; pi <= r; ){
			T.add(P[pi ++], 1);
			if(!T.yeah()){
				T.add(P[-- pi], -1);
				t = pi; break;
			}
		}
	}
	else{
		for(; pi > r; ) T.add(P[-- pi], -1);
		for(; pi >= l; ){
			if(T.yeah()){ t = pi; break; }
			T.add(P[-- pi], -1);
		}
	}
	A[m] = t;
	dnc(s, m - 1, t, r);
	dnc(m + 1, e, l, t);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int i, t;

	cin >> n; pi = n + 1	;

	for(i = 1; i <= n; i ++){
		cin >> t; P[t] = i;
	}
	
	for(i = 1; i <= n; i ++){
		cin >> Q[i];
	}
	
	dnc(1, n, 1, n);

	for(i = 1; i <= n; i ++){
		cout << A[i] << " ";
	}
	cout << "\n";

	return 0;
}