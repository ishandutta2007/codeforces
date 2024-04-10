#include<bits/stdc++.h>

using namespace std;
#define ll long long

int T, a, b, k, g;
int gcd(int x, int y){ return y?gcd(y, x%y):x;}
int main() {
	// freopen("color.in", "r", stdin);
	// freopen("color.out", "w", stdout);
	scanf("%d", &T);
	while(T--){
		scanf("%d%d%d", &a, &b, &k), g=gcd(a, b), a/=g, b/=g;
		if(a>b) swap(a, b);
		puts(k<=(b-2)/a+1?"REBEL":"OBEY");
	}
	return 0;
}