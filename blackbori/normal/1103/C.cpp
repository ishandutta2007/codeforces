#include <bits/stdc++.h>

using namespace std;

vector <int> V[303030];
vector <int> K;
int P[303030], D[303030];
bool chk[303030];
int n, m, k, l;

void PATH(int p)
{
	printf("PATH\n");
	
	vector <int> X;
	
	for(; p; p=P[p]) X.push_back(p);
	
	printf("%d\n", (int)X.size());
	
	for(int &t: X) printf("%d ", t);
	
	printf("\n");
	
	exit(0);
}

void CYCLES(vector <int> &K)
{
	if(K.size() < k) for(; ; );
	
	printf("CYCLES\n");
	
	int i, p, x, y;
	
	for(i=0; i<k; i++){
		p = K[i];
		if(V[p][0] == P[p]) x = V[p][1], y = V[p][2];
		else if(V[p][1] == P[p]) x = V[p][0], y = V[p][2];
		else x = V[p][0], y = V[p][1];
		
		if((D[p] - D[x] + 1) % 3 != 0){
			printf("%d\n", D[p] - D[x] + 1);
			for(; p!=x; p=P[p]) printf("%d ", p);
			printf("%d\n", x);
		}
		else if((D[p] - D[y] + 1) % 3 != 0){
			printf("%d\n", D[p] - D[y] + 1);
			for(; p!=y; p=P[p]) printf("%d ", p);
			printf("%d\n", y);
		}
		else{
			if(D[x] < D[y]) swap(x, y);
			printf("%d\n", D[x] - D[y] + 2);
			for(; x!=y; x=P[x]) printf("%d ", x);
			printf("%d %d\n", y, p);
		} 
	}
	
	exit(0);
}

void dfs(int p, int r, int d)
{
	P[p] = r; D[p] = d;
	chk[p] = 1;
	
	if(d >= l) PATH(p);
	
	int cnt = 0;
	
	for(int &t: V[p]){
		if(!chk[t]){
			dfs(t, p, d + 1);
			cnt ++;
		}
	}
	
	if(cnt == 0) K.push_back(p); 
}

int main()
{
	int i, u, v;
	
	scanf("%d%d%d", &n, &m, &k);
	
	l = (n - 1) / k + 1;
	
	for(i=0; i<m; i++){
		scanf("%d%d", &u, &v);
		V[u].push_back(v);
		V[v].push_back(u);
	}
	
	dfs(1, 0, 1);
	
	CYCLES(K);	
	
	return 0;
}