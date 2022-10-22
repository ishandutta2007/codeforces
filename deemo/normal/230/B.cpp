#include<cstdio>

using namespace std;

typedef long long ll;

bool pr(ll x){
	for (int i = 2 ; i * i <= x; i++)
		if (x % i == 0)	return	false;
	return	true; 
}

bool ok(ll x){
	ll b = 2, e = 1e6, mid, ret = 1;
	while(b <= e){
		mid = (b+e)/2;
		if (mid * mid <= x){
			ret = mid;
			b = mid + 1;
		}
		else	e = mid - 1;
	}
	if (ret == 1)	return	0;
	if (ret * ret != x)	return	0;
	return	pr(ret);
}

int main(){
	int n;	scanf("%d", &n);
	while(n--){
		ll temp;	scanf("%I64d", &temp);
		if (ok(temp))	printf("YES\n");
		else	printf("NO\n");
	}
	return	0;
}