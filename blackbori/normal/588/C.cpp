#include <bits/stdc++.h>

using namespace std;

int n,a;
int D[1<<20],i,ans;

int main()
{
	scanf("%d",&n);
	
	for(i=0;i<n;i++) scanf("%d",&a), D[a]++;
	
	for(i=0;i<1000000;i++){
		D[i+1]+=(D[i]/2);
		ans+=(D[i]%=2);
	}
	if(D[1000000]){
		while(D[1000000]){
			ans+=D[1000000]%2;
			D[1000000]/=2;
		}
	}
	
	printf("%d\n",ans);
	
	return 0;
}