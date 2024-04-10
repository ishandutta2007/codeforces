#include<cstdio>
#include<cmath>
using namespace std;
int n,d,r;
int main(){
	scanf("%d",&n);
	d=sqrt(n);
	r=n%d;
	for(int i=0;i<r;i++)
	  for(int j=d+1;j;j--)
		printf("%d ",j+(d+1)*i);
	for(int i=0;i<n/d-r;i++)
	  for(int j=d;j;j--)
		printf("%d ",j+i*d+(d+1)*r);
	//for(int )
	return 0;
}