#include <bits/stdc++.h>

using namespace std;

set <int> S;
int D[101010], C[101010];
int n, ans;

int main()
{
	int i, a, k, l;
	
	scanf("%d", &n);
	
	for(i=1; i<=n; i++){
		scanf("%d", &a);
		D[C[a]] --;
		if(D[C[a]] == 0) S.erase(C[a]);
		C[a] ++;
		D[C[a]] ++;
		if(D[C[a]] == 1) S.insert(C[a]);
		
		if(S.size() > 2) continue;
		else if(S.size() == 1){
			if(D[1] == i) ans = i;
			else if(*S.begin() == i) ans = i;
		}
		else{
			if(D[1] == 1) ans = i;
			k = *S.begin(), l = *next(S.begin());
			if(D[l] == 1 && k + 1 == l) ans = i;
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
}