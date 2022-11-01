#include <bits/stdc++.h> 

using namespace std;

const int mod = 998244353;

int n, m;

int main(){
	int i, j;
	
	scanf("%d", &n);
	
	vector <long long> ans;
	
	ans.push_back(10);
	long long t = 10;
	long long sum = 10;
	long long s = 10;
	
	for(i=2;i<=n;i++){
		s = (s + sum) % mod;
		t = (t * 10) % mod;
		long long x = t * i % mod;
		ans.push_back((x - s + mod) % mod);
		s = (s + ans.back()) % mod;
		sum = (sum + ans.back()) % mod;
	}
	
	reverse(ans.begin(), ans.end());
	
	for(i=0;i<n;i++){
		printf("%d ", ans[i]);
	}
	printf("\n");
	
	return 0;
}