#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

deque <ll> D;
ll A[1010101], S[1010101];
ll n, w, k;

void f()
{
	ll i, x, y;
	
	scanf("%lld", &k);
	
	// i : i ~ w - k + i
	
	A[0] = 0;
	
	for(i=1; i<=k; i++){
		scanf("%lld", A + i);
	}
	
	A[i] = 0;
	
	D.clear(); D.push_back(0);
	
	for(i=1; i<=k+1; i++){
		x = A[D.front()];
		for(; !D.empty() && A[D.back()] <= A[i]; D.pop_back());
		D.push_back(i);
		for(; !D.empty() && w - k + D.front() < i; D.pop_front());
		y = A[D.front()];
		S[i] += y - x;
	}
	
	for(; D.size() > 1; ){
		x = A[D.front()];
		i = w - k + D.front() + 1;
		D.pop_front();
		y = A[D.front()];
		S[i] += y - x;
	}
}

int main()
{
	ll i;
	
	scanf("%lld%lld", &n, &w);
	
	for(i=1; i<=n; i++){
		f();
	}
	
	for(i=1; i<=w; i++){
		S[i] += S[i - 1];
		printf("%lld ", S[i]);
	}
	
	printf("\n");
	
	return 0;
}