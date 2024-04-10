#include<cstdio>
#include<algorithm>
using namespace std;
int s,n,m,a[100],b[100],p1,p2;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",a+i);
	scanf("%d",&m);
	for(int i=0;i<m;i++)scanf("%d",b+i);
	sort(a,a+n);sort(b,b+m);
	while(p1<n&&p2<m){
	  if(a[p1]-b[p2]>1)p2++;
	  else if(b[p2]-a[p1]>1)p1++;
	  else p1++,p2++,s++;
	}
	printf("%d",s);
	return 0;
}