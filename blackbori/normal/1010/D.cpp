#include <bits/stdc++.h>

using namespace std;

int L[1010101], R[1010101], T[1010101];
int V[1010101], C[1010101];
int n;

void dfs(int p)
{
	if(T[p] == 0) return;
	
	else if(T[p] == 1){
		dfs(L[p]); dfs(R[p]);
		V[p] = V[L[p]] & V[R[p]];
	}
	else if(T[p] == 2){
		dfs(L[p]); dfs(R[p]);
		V[p] = V[L[p]] | V[R[p]];
	}
	else if(T[p] == 3){
		dfs(L[p]); dfs(R[p]);
		V[p] = V[L[p]] ^ V[R[p]];
	}
	else{
		dfs(L[p]);
		V[p] = !V[L[p]];
	}
}

void dfs2(int p, int r)
{
	if(r != 0){
		int v;
		
		if(T[r] == 1){
			if(p == L[r]) v = (!V[p]) & V[R[r]];
			else v = V[L[r]] & (!V[p]);
			
			if(v != V[r]) C[p] = C[r];
			else C[p] = V[1];
		}
		else if(T[r] == 2){
			if(p == L[r]) v = (!V[p]) | V[R[r]];
			else v = V[L[r]] | (!V[p]);
			
			if(v != V[r]) C[p] = C[r];
			else C[p] = V[1];
		}
		else if(T[r] == 3){
			if(p == L[r]) v = (!V[p]) ^ V[R[r]];
			else v = V[L[r]] ^ (!V[p]);
			
			if(v != V[r]) C[p] = C[r];
			else C[p] = V[1];
		}
		else{
			C[p] = C[r];
		}
	}
	else C[p] = !V[p];
	
	if(1 <= T[p] && T[p] <= 3){
		dfs2(L[p], p); dfs2(R[p], p);
	}
	else if(T[p] == 4){
		dfs2(L[p], p);
	}
}

int main()
{
	int i, a, b;
	char str[11];
	
	scanf("%d", &n);
	
	for(i=1; i<=n; i++){
		scanf("%s", str);
		if(*str == 'I'){
			scanf("%d", &a);
			T[i] = 0; V[i] = a;
		}
		else if(*str == 'A'){
			scanf("%d%d", &a, &b);
			T[i] = 1; L[i] = a; R[i] = b;
		}
		else if(*str == 'O'){
			scanf("%d%d", &a, &b);
			T[i] = 2; L[i] = a; R[i] = b;
		}
		else if(*str == 'X'){
			scanf("%d%d", &a, &b);
			T[i] = 3; L[i] = a; R[i] = b;
		}
		else if(*str == 'N'){
			scanf("%d", &a);
			T[i] = 4; L[i] = a;
		}
	}
	
	dfs(1);
	dfs2(1, 0);
	
	for(i=1; i<=n; i++){
		if(T[i] == 0) printf("%d", C[i]);
	}
	
	printf("\n");
	
	return 0;
}