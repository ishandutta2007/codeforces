#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> pii;

struct segtree{
	int T[606060];
	int sz = 1 << 18;
	
	void update(int p, int v)
	{
		p += sz; T[p] = v;
		
		for(p>>=1; p; p>>=1){
			T[p] = max(T[p << 1], T[p << 1 | 1]);
		}
	}
	
	int getmax(int l, int r)
	{
		int ret = 0;
		
		l += sz; r += sz;
		
		for(; l<=r; ){
			if(l & 1) ret = max(ret, T[l]);
			if(~r & 1) ret = max(ret, T[r]);
			l = l + 1 >> 1;
			r = r - 1 >> 1;
		}
		
		return ret;
	}
};

segtree T;
vector <pii> Q;
int A[202020], D[202020];
int n, q;

int main()
{
	int i, t, x, v;
	
	scanf("%d", &n);
	
	for(i=1; i<=n; i++){
		scanf("%d", A + i);
	}
	
	scanf("%d", &q);
	
	for(i=1; i<=q; i++){
		scanf("%d", &t);
		if(t == 1){
			scanf("%d%d", &x, &v);
			A[x] = v; D[x] = i;
		}
		else{
			scanf("%d", &v);
			Q.emplace_back(i, v);
		}
	}
	
	for(i=0; i<Q.size(); i++){
		T.update(i, Q[i].second);
	}
	
	for(i=1; i<=n; i++){
		t = lower_bound(Q.begin(), Q.end(), pii(D[i], 0)) - Q.begin();
		printf("%d ", max(A[i], T.getmax(t, Q.size() - 1)));
	}
	
	printf("\n");
	
	return 0;
}