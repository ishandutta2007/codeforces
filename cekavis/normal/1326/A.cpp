#include<bits/stdc++.h>

using namespace std;
#define ll long long

int T, n;
int main() {
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		if(n==1) puts("-1");
		else{
			if((n-1)%3){
				for(int i=1; i<n; ++i) putchar('2');
				putchar('3');
			}
			else{
				for(int i=1; i<n-1; ++i) putchar('2');
				putchar('3'), putchar('3');
			}
			puts("");
		}
	}
	return 0;
}