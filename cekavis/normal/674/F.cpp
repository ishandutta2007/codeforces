#include<bits/stdc++.h>
unsigned i, j, x, y, n, p, q, a, f[133];
int main() {
	scanf("%u%u%u", &n, &p, &q), f[0]=1;
	for(x=30; x--;){
		for(i=p; i; --i) for(j=0; j<i; ++j) f[i]+=f[j]*f[i-j];
		if(n>>x&1) for(i=p; i; --i) f[i]+=f[i-1];
	}
	for(i=1; i<=q; a^=i++*x) for(j=0, x=0, y=1; j<=p && j<n; x+=y*f[j++], y*=i);
	return printf("%u\n", a), 0;
}