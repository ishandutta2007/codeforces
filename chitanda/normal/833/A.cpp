#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
#define ll long long
#define M 1000000007
#define all(a) a.begin(), a.end()

int n, a, b;

int main(){
	scanf("%d", &n);
	while(n--){
		scanf("%d%d", &a, &b);
		int g = __gcd(a, b);
		ll l = (ll)a * b / g;
		ll d = l / g;
		ll s = (ll)a * b;
		ll q = pow(s, 1. / 3) + 10;
		while(q * q * q > s) --q;
		if(q * q * q == s){
			if(g % d == 0) printf("Yes\n");
			else printf("No\n");
		}else printf("No\n");
	}
	
#ifndef ONLINE_JUDGE
	system("pause");
#endif
	return 0;
}