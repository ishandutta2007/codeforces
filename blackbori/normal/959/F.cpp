#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;

const int mod = 1e9+7;

vector <pii> V[101010];
int A[101010];
int P[1101010], Ans[101010];
int n,m,ans = 1;

int find(int p) { return p == P[p]? p : P[p] = find(P[p]); }
int group(int a,int b) { P[find(a)] = find(b); }

int main()
{
	int i,j,a,b;
	
	scanf("%d%d",&n,&m);
	
	for(i=1;i<=n;i++) scanf("%d",A+i);
	
	for(i=1;i<=m;i++){
		scanf("%d%d",&a,&b);
		V[a].push_back(pii(b,i));
	}
	
	for(i=0;i<(1<<20);i++) P[i] = i;
	
	for(i=1;i<=n;i++){
		if(find(A[i]) != find(0)){
			for(j=0;j<(1<<20);j++) group(j, A[i]^j);
		}
		else ans = ans * 2 % mod;
		
		for(pii p: V[i]){
			if(find(p.first) == find(0)) Ans[p.second] = ans;
			else Ans[p.second] = 0;
		}
	}
	
	for(i=1;i<=m;i++) printf("%d\n",Ans[i]);
	
	return 0;
}