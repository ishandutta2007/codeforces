#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 2005, w[]={0b1110111, 0b0010010, 0b1011101, 0b1011011, 0b0111010, 0b1101011, 0b1101111, 0b1010010, 0b1111111, 0b1111011};
int n, k, a[N];
char s[8];
bitset<N> f[N];
int main() {
	scanf("%d%d", &n, &k);
	for(int i=1; i<=n; ++i){
		scanf("%s", s);
		for(int j=0; j<7; ++j) a[i]=a[i]<<1|(s[j]-'0');
	}
	f[n+1][0]=1;
	for(int i=n; i; --i) for(int x=0; x<10; ++x) if((w[x]&a[i])==a[i]){
		int y=__builtin_popcount(w[x]^a[i]);
		f[i]|=f[i+1]<<y;
	}
	if(!f[1][k]) return puts("-1"), 0;
	for(int i=1; i<=n; ++i) for(int x=10; x--;) if((w[x]&a[i])==a[i]){
		int y=__builtin_popcount(w[x]^a[i]);
		if(y<=k && f[i+1][k-y]){ k-=y, putchar('0'+x); break;}
	}
	return 0;
}