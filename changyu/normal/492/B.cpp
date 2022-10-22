#include<cstdio>
#include<algorithm>
using namespace std;
int light[1005],n,l;
int main(){
	scanf("%d%d",&n,&l);
	for(int i=0;i<n;i++)scanf("%d",&light[i]);
	sort(light,light+n);
	double ans=max(light[0],l-light[n-1]);
	for(int i=0;i<n-1;i++)if((light[i+1]-light[i])/2.>ans)ans=(light[i+1]-light[i])/2.;
	printf("%.10lf",ans);
	return 0;
}