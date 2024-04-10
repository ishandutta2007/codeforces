#include<bits/stdc++.h>
using namespace std;
const double pi=acos(-1);
int T,n;double dat,tt,ans;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);ans=0;
		dat=pi/n;tt=(pi/2-dat*(n/2-1))/2;
		for(int i=0;i<n;i++)ans+=sin(tt),tt+=dat;
		printf("%.9lf\n",ans);
	}
	return 0;
}