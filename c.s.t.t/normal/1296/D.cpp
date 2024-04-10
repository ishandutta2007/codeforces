#include<bits/stdc++.h>
using namespace std;
int n,a,b,k,h[200100],res;
int main(){
	scanf("%d%d%d%d",&n,&a,&b,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&h[i]),h[i]%=(a+b);
		if(!h[i])h[i]=a+b;
		if(!(h[i]%a))h[i]/=a,h[i]--;
		else h[i]/=a;
	}
	sort(h+1,h+n+1);
	for(int i=1;i<=n;i++)if(k>=h[i])res++,k-=h[i];
	printf("%d\n",res);
	return 0;
}