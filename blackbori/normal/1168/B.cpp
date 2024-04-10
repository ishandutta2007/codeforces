#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

char str[303030];
ll D[101010];
ll n, ans;

ll check(ll t, ll k)
{
	ll i, x, ret = 99;
	ll f1, f2, f3;
	
	for(i=0; i<k; i++){
		for(x=1; i+x+x<k; x++){
			if(t & (1 << i)) f1 = 1;
			else f1 = 0;
			if(t & (1 << i + x)) f2 = 1;
			else f2 = 0;
			if(t & (1 << i + x + x)) f3 = 1;
			else f3 = 0;
			
			if(f1 == f2 && f2 == f3) ret = min(ret, i + x + x);
		}
	}
	
	return ret;
}

int main()
{
	ll i, j, s;
	
	scanf("%s", str);
	
	n = strlen(str);
	
	for(i=0; i<(1<<9); i++){
		D[i] = check(i, 9);
	}
	
	for(i=0; i<n-9; i++){
		s = 0;
		for(j=0; j<9; j++){
			s += (str[i + j] == '1') << j;
		}
		ans += n - (i + D[s]);
	}
	
	for(; i<n; i++){
		s = 0;
		for(j=i; j<n; j++){
			s += (str[j] == '1') << (j - i);
		}
		ans += max(0ll, n - (i + check(s, n - i)));
	}
	
	printf("%lld\n", ans);
	
	return 0;
}