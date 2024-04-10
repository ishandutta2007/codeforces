#include <bits/stdc++.h>

using namespace std;

vector <int> P;
int D[101010];
int n, ans;

void factorize(int k, vector <int> &P)
{
	int i;
	
	for(i=2; i*i<=k; i++){
		if(k % i == 0){
			P.push_back(i);
			for(; k%i == 0; k/=i);
		}
	}
	
	if(k != 1) P.push_back(k);
}

int main()
{
	int i, a, k;
	
	scanf("%d", &n);
	
	for(i=1; i<=n; i++){
		scanf("%d", &a);
		
		k = 0; P.clear();
		factorize(a, P);
		
		for(int &t: P){
			k = max(D[t], k);
		}
		
		for(int &t: P){
			D[t] = k + 1;
		}
		
		ans = max(ans, k + 1);
	}
	
	printf("%d\n", ans);
	
	return 0;
}