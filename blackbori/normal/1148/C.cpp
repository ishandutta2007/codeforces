#include <bits/stdc++.h>

using namespace std;

typedef pair <int, int> pii;

vector <pii> V;
int P[303030], Q[303030];
int n;

void f(int x, int y)
{
	swap(Q[P[x]], Q[P[y]]);
	swap(P[x], P[y]);
	V.emplace_back(x, y);
}

int main()
{
	int i, x, y;
	
	scanf("%d", &n);
	
	for(i=1; i<=n; i++){
		scanf("%d", P + i);
		Q[P[i]] = i;
	}
	
	for(i=n/2; i>1; i--){
		if(Q[i] <= n / 2){
			f(Q[i], n);
			f(i, n);
		}
		else{
			f(Q[i], 1);
			f(1, n);
			f(i, n);
		}
		
		if(Q[n - i + 1] <= n / 2){
			f(Q[n - i + 1], n);
			f(1, n);
			f(1, n - i + 1);
		}
		else{
			f(Q[n - i + 1], 1);
			f(1, n - i + 1);
		}
	}
	
	if(P[1] != 1) f(1, n);
	
	printf("%d\n", V.size());
	
	for(pii &t: V) printf("%d %d\n", t.first, t.second);
	
	return 0;
}