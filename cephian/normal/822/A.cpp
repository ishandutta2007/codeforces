#include <bits/stdc++.h>
using namespace std;
int main() {
	int a,b;
	scanf("%d%d",&a,&b);
	if(b<a) swap(a,b);
	for(b=1;a>0;--a)
		b*=a;
	printf("%d\n",b);
}