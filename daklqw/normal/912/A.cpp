#include<cstdio>
using namespace std;
long long y,b,ny,ng,nb,ans=0;
long long max(long long a,long long b){return a>b?a:b;}
int main(){
	scanf("%I64d%I64d",&y,&b);
	scanf("%I64d%I64d%I64d",&ny,&ng,&nb);
	ans=max(0,2*ny+ng-y)+max(0,ng+3*nb-b);
	printf("%I64d\n",ans);
	return 0;
}