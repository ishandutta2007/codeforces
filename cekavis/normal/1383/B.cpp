#include<bits/stdc++.h>

using namespace std;
#define ll long long

const int N = 100005;
int T, n, a[N];
int main() {
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		int s=0;
		for(int i=1; i<=n; ++i) scanf("%d", a+i), s^=a[i];
		if(!s){
			puts("DRAW");
			continue;
		}
		int p=30, cnt=0;
		while(!(s>>p&1)) --p;
		for(int i=1; i<=n; ++i) cnt+=a[i]>>p&1;
		if((cnt&2) && !((n-cnt)&1)) puts("LOSE");
		else puts("WIN");
	}
	return 0;
}