#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll T[1010101];
ll n;

void Add(ll p)
{
	for(;p<=n;p+=p&-p) T[p] ++;
}

ll Sum(ll p)
{
	ll ret = 0;
	for(;p;p-=p&-p) ret += T[p];
	return ret;
}

int main()
{
	ll i,a,sum = 0, sum_i;
	
	scanf("%lld",&n);
	
	sum_i = n * (n-1) / 2;
	
	for(i=1;i<=n;i++){
		scanf("%lld",&a);
		sum += Sum(a);
		Add(a);
	}
	
	if(n % 2 == 0){
		if(sum_i % 2 == sum % 2) printf("Petr\n");
		else printf("Um_nik\n");
	}
	else{
		if(sum_i % 2 == sum % 2) printf("Um_nik\n");
		else printf("Petr\n");
	}
	
	return 0;
}