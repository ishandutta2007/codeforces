#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool T[33];
ll n, m;

int main()
{
	ll t, i, a, s, e, mid;
	
	scanf("%lld%lld", &m, &n);
	
	if(m == 1){
		printf("%lld\n", m);
		return 0;
	}
	
	printf("1\n");
	fflush(stdout);
	scanf("%lld", &t);
	if(t == 0) return 0;
	if(t == 1) T[0] = 1;
	else T[0] = 0;
	
	for(i=1; i<n; i++){
		printf("1\n");
		fflush(stdout);
		scanf("%lld", &a);
		if(a == 0) return 0;
		
		if(a == t) T[i] = T[0];
		else T[i] = !T[0];
	}
	
	s = 1, e = m;
	
	for(i=0; i<30; i++){
		mid = s + e >> 1;
		printf("%lld\n", mid);
		fflush(stdout);
		scanf("%lld", &a);
		if(a == 0) return 0;
		
		else if((a == 1 && T[i % n]) || (a == -1 && !T[i % n])) s = mid + 1;
		else e = mid - 1;
	}
	
	return 0;
}