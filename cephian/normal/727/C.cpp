#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
int a[N],n,b[N];

int main() {	
	scanf("%d",&n);
	if(n&1) {
		int s = 0;
		for(int i = 0; i < n; ++i) {
			printf("? %d %d\n",i+1, (i+1)%n+1),fflush(stdout);
			scanf("%d",a+i);
			if(i != n-1) {
				if(i&1) s -= a[i];
				else s += a[i];
			}
		}
		b[0] = (s + a[n-1])/2;
	} else {
		int s = 0,q;
		for(int i = 0; i < n-1; ++i) {
			printf("? %d %d\n",i+1, (i+1)%n+1),fflush(stdout);
			scanf("%d",a+i);
			if(i != n-1) {
				if(i&1) s -= a[i];
				else s += a[i];
			}
			if(i != n-1) {
				if(i&1) s -= a[i];
				else s += a[i];
			}
		}
		a[n-1] = s;
		printf("? 1 3\n"),fflush(stdout);
		scanf("%d",&q);
		b[0] = (a[0]-a[1]+q)/2;
	}
	for(int i = 1; i < n; ++i)
		b[i] = a[i-1]-b[i-1];
	printf("!");
	for(int i = 0; i < n; ++i)
		printf(" %d",b[i]);
	printf("\n"),fflush(stdout);
}