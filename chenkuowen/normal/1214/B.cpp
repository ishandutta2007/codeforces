#include<bits/stdc++.h>
using namespace std;
int main(){
	int b,g,n,ans=0; scanf("%d%d%d",&b,&g,&n);
	for(int i=0;i<=n;++i)
		if(i<=b&&n-i<=g) ++ans;
	printf("%d\n",ans);
	return 0;
}