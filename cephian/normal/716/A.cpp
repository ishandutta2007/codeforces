#include <bits/stdc++.h>
using namespace std;
int main() {
	int n,d;
	scanf("%d%d",&n,&d);
	int a=0,l=0;
	while(n--) {
		int x;
		scanf("%d",&x);
		if(x-l > d) a=0;
		++a;
		l=x;
	}
	printf("%d\n",a);
}