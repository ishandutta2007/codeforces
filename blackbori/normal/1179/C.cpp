#include <bits/stdc++.h>

using namespace std;

struct seg{
	int T[2202020], L[2202020];
	
	void update(int p, int s, int e, int l, int r, int v)
	{
		if(e < l || r < s) return;
		else if(l <= s && e <= r){
			T[p] += v; L[p] += v;
			return;
		}
		
		update(p << 1, s, s + e >> 1, l, r, v);
		update(p << 1 | 1, (s + e >> 1) + 1, e, l, r, v);
		
		T[p] = max(T[p << 1], T[p << 1 | 1]) + L[p];
	}
	
	int query(int p, int s, int e, int v)
	{
		if(T[p] + v < 1) return -1;
		else if(s == e) return s;
		
		if(T[p << 1 | 1] + v + L[p] >= 1) return query(p << 1 | 1, (s + e >> 1) + 1, e, v + L[p]);
		else return query(p << 1, s, s + e >> 1, v + L[p]);
	}
};

seg T;
int A[303030], B[303030];
int n, m;

int main()
{
	int q, t, i, v;
	
	scanf("%d%d", &n, &m);
	
	for(i=1; i<=n; i++){
		scanf("%d", A + i);
		T.update(1, 1, 1e6, 1, A[i], 1);
	}
	
	for(i=1; i<=m; i++){
		scanf("%d", B + i);
		T.update(1, 1, 1e6, 1, B[i], -1);
	}
	
	scanf("%d", &q);
	
	for(; q--; ){
		scanf("%d%d%d", &t, &i, &v);
		
		if(t == 1){
			T.update(1, 1, 1e6, 1, A[i], -1);
			A[i] = v;
			T.update(1, 1, 1e6, 1, A[i], 1);
		}
		else{
			T.update(1, 1, 1e6, 1, B[i], 1);
			B[i] = v;
			T.update(1, 1, 1e6, 1, B[i], -1);
		}
		
		printf("%d\n", T.query(1, 1, 1e6, 0));
	}
	
	return 0;
}