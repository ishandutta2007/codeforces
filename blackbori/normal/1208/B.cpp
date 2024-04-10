#include <bits/stdc++.h>

using namespace std;

vector <int> X;
int A[2020], S[2020];
int n, ans;

int main()
{
	int i, j, f;
	
	scanf("%d", &n);
	
	for(i=0; i<n; i++){
		scanf("%d", A + i);
		X.push_back(A[i]);
	}
	
	sort(X.begin(), X.end());
	X.erase(unique(X.begin(), X.end()), X.end());
	
	for(i=0; i<n; i++){
		A[i] = lower_bound(X.begin(), X.end(), A[i]) - X.begin();
	}
	
	ans = 1e9;
	
	for(i=0; i<n; i++){
		f = 0;
		
		for(j=0; j<n; j++){
			S[A[j]] = 0;
		}
		
		for(j=0; j<i; j++){
			S[A[j]] ++;
			if(S[A[j]] > 1) f = 1;
		}
		
		if(f == 1) continue;
		
		for(j=n-1; j>=i; j--){
			S[A[j]] ++;
			if(S[A[j]] > 1) f = 1;
			if(f == 1) break;
		}
		
		ans = min(ans, j - i + 1);
	}
	
	printf("%d\n", ans);
	
	return 0;
}