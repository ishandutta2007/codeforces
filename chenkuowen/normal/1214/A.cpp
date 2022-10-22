#include<bits/stdc++.h>
using namespace std;
int main(){
	int n; scanf("%d",&n);
	int d,e,ans=1e9; scanf("%d%d",&d,&e); e*=5;
	for(int i=0;i*d<=n;++i)
		ans=min(ans,(n-i*d)%e);
	printf("%d\n",ans);
}