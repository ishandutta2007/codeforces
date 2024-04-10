#include<bits/stdc++.h>

using namespace std;
#define ll long long

int n, p;
int main() {
	scanf("%d%d", &n, &p);
	if(1+p>n) return puts("-1"), 0;
	for(int i=1; i<=1000000; ++i){
		int x=n-i*p;
		if(x<0) break;
		if(__builtin_popcount(x)<=i && x>=i) return printf("%d\n", i), 0;
	}
	puts("-1");
	return 0;
}