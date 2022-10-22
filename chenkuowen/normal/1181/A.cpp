#include<bits/stdc++.h>
using namespace std;
int main(){
	long long x,y,z; scanf("%lld%lld%lld",&x,&y,&z);
	printf("%lld ",(x+y)/z);
	if(x/z+y/z==(x+y)/z) puts("0");
	else printf("%lld\n",min((z-x%z)%z,(z-y%z)%z));
	return 0;
}