#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int A[5050][5050], S[5050][5050];
int n,q;

int main()
{
	int i,j,l,r;
	
	scanf("%d",&n);
	
	for(i=1;i<=n;i++){
		scanf("%d",A[1]+i);
		S[1][i] = A[1][i];
	}
	
	for(i=2;i<=n;i++){
		for(j=1;j<=n-i+1;j++){
			A[i][j] = A[i-1][j] ^ A[i-1][j+1];
			S[i][j] = max(max(S[i-1][j], S[i-1][j+1]), A[i][j]);
		}
	}
	
	scanf("%d",&q);
	
	for(;q--;){
		scanf("%d%d",&l,&r);
		printf("%d\n",S[r-l+1][l]);
	}
	
	return 0;
}