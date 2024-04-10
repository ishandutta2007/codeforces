#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector <int> X[404040];
int P[404040], C[404040];
int n, m, k, ans, h, w;

int find(int p) { return p == P[p]? p : P[p] = find(P[p]); }
void group(int a, int b)
{
	a = find(a); b = find(b);
	if(a != b){
		C[a] += C[b];
		P[b] = a;
	}
}

int main()
{
	int i, j, x, y;
	
	scanf("%d%d%d", &n, &m, &k);
	
	for(i=1; i<=n+m; i++) P[i] = i;
	
	for(i=0; i<k; i++){
		scanf("%d%d", &x, &y);
		C[x] ++; C[n + y] ++;
		X[x].push_back(n + y);
		X[n + y].push_back(x);
	}
	
	for(i=1; i<=n+m; i++){
		for(j=1; j<X[i].size(); j++){
			group(X[i][j], X[i][j-1]);
		}
	}
	
	for(i=1; i<=n+m; i++){
		if(P[i] == i){
			if(C[i]) ans ++;
			
			if(i <= n) h ++;
			else w ++;
		}
	}
	
	printf("%d\n", h + w - 1 - ans / 2);
	
	return 0;
}