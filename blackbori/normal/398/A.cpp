#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, m;
ll ans, id, ans1, ans2, ans3;
string S1, S2, S3;

ll max_cost(ll x, ll y)
{
	return (x - y + 1) * (x - y + 1) + (y - 1);
}

void make_max_cost(vector <ll> &ret, ll x, ll y)
{
	ret.clear();
		
	ret.push_back(x - y + 1);
	for(; --x; ) ret.push_back(1);
}

ll min_cost(ll x, ll y)
{
	return (x / y) * (x / y) * (y - x % y) + (x / y + 1) * (x / y + 1) * (x % y);
}

void make_min_cost(vector <ll> &ret, ll x, ll y)
{
	ret.clear();
	ll i, t;
	
	for(i=0; i<x%y; i++) ret.push_back(x / y + 1);
	for(i=0; i<y-x%y; i++) ret.push_back(x / y);
}

int main()
{
	vector <ll> X, Y;
	ll i, j, t;
	
	ans1 = ans2 = ans3 = -1e18;
	
	scanf("%lld%lld", &n, &m);
	
	if(n == 0){
		printf("%lld\n", -m * m);
		for(i=0; i<m; i++) printf("x");
		printf("\n");
		
		return 0;
	}
	else if(m == 0){
		printf("%lld\n", n * n);
		for(i=0; i<n; i++) printf("o");
		printf("\n");
		
		return 0;
	}
	
	// o == x
	for(i=1; i<=n && i<=m; i++){
		t = max_cost(n, i) - min_cost(m, i);
		if(t > ans1) ans1 = t, id = i;
	}
	
	make_max_cost(X, n, id);
	make_min_cost(Y, m, id);
	
	for(i=0; i<id; i++){
		for(j=0; j<X[i]; j++) S1.push_back('o');
		for(j=0; j<Y[i]; j++) S1.push_back('x');
	}
	
	// o > x
	for(i=1; i+1<=n && i<=m; i++){
		t = max_cost(n, i + 1) - min_cost(m, i);
		if(t > ans2) ans2 = t, id = i;
	}
	
	make_max_cost(X, n, id + 1);
	make_min_cost(Y, m, id);
	
	for(i=0; i<id; i++){
		for(j=0; j<X[i]; j++) S2.push_back('o');
		for(j=0; j<Y[i]; j++) S2.push_back('x');
	}
	for(j=0; j<X[id]; j++) S2.push_back('o');
	
	// o < x
	for(i=1; i<=n && i+1<=m; i++){
		t = max_cost(n, i) - min_cost(m, i + 1);
		if(t > ans3) ans3 = t, id = i;
	}
	
	make_max_cost(X, n, id);
	make_min_cost(Y, m, id + 1);
	
	for(i=0; i<id; i++){
		for(j=0; j<Y[i]; j++) S3.push_back('x');
		for(j=0; j<X[i]; j++) S3.push_back('o');
	}	
	for(j=0; j<Y[id]; j++) S3.push_back('x');
	
	ans = max(ans1, max(ans2, ans3));
	
	if(ans == ans1) printf("%lld\n%s\n", ans1, S1.c_str());
	else if(ans == ans2) printf("%lld\n%s\n", ans2, S2.c_str());
	else if(ans == ans3) printf("%lld\n%s\n", ans3, S3.c_str());
	
	return 0;
}