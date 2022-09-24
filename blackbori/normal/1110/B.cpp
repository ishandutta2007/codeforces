#include <bits/stdc++.h>

using namespace std;

vector <int> V;
int B[101010];
int n, m, k, ans;

int main()
{
	int i;
	
	scanf("%d%d%d", &n, &m, &k);
	
	for(i=1; i<=n; i++){
		scanf("%d", B + i);
		if(i > 1) V.push_back(B[i] - B[i - 1] - 1);
	}
	
	sort(V.begin(), V.end());
	
	for(i=0; i<n-k; i++){
		ans += V[i];
	}
	
	printf("%d\n", n + ans);
	
	return 0;
}