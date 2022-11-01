#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;

int n, m, t;
int d;

long long a[maxn];

vector <long long> A, B;
vector <long long> sum;

bool cmp(long long x, long long y){
	return x > y;
}

int main(){
	int i, j;
	long long s = 0;
	
	scanf("%d%d%d", &n, &d, &m);
	
	for(i=1;i<=n;i++){
		scanf("%lld", &a[i]);
		s += a[i];
		if(a[i] > m) A.push_back(a[i]);
		else B.push_back(a[i]);
	}
	
	sort(A.begin(), A.end(), cmp);
	sort(B.begin(), B.end());
	
	if(A.size() <= 1){
		printf("%lld\n", s);
		return 0;
	}
	
	sum.resize(B.size() + 1);
	for(i=0;i<B.size();i++){
		sum[i + 1] = sum[i] + B[i];
	}
	
	long long ans = 0;
	
	s = A[0];
	
	ans = s + sum[B.size()];
	
	for(i=1;i<A.size();i++){
		if(n < i * d + i + 1) break;
		s += A[i];
		ans = max(ans, s + sum[B.size()] - sum[max(0, i * d - ((int)A.size() - i - 1))]);
	}
	
	printf("%lld\n", ans);
	
	return 0;
}