#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	int a[4]; 
	for(int i=0;i<3;++i) scanf("%d",&a[i]);
	sort(a,a+3);
	if(a[2]>=a[0]+a[1]) printf("%d",a[2]-a[0]-a[1]+1);
	else printf("0");
	return 0;
}