#include <bits/stdc++.h>

using namespace std;

int A[303030];
int n, m;

bool check(int k)
{
	int i, x = 0;
	
	for(i=0; i<n; i++){
		if(A[i] + k >= m){
			if((A[i] + k) % m < x && x < A[i]) x = A[i];
		}
		else{
			if(A[i] + k < x) return 0;
			else x = max(x, A[i]);
		}
	}
	
	return 1;
}

int main()
{
	int i, s, e, mid;
	
	scanf("%d%d", &n, &m);
	
	for(i=0; i<n; i++){
		scanf("%d", A + i);
	}
	
	for(s=0, e=m-1; s<=e; ){
		mid = s + e >> 1;
		if(check(mid)) e = mid - 1;
		else s = mid + 1;
	}
	
	printf("%d\n", e + 1);
	
	return 0;
}