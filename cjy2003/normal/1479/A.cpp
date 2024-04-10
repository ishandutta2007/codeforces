#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int main()
{
	scanf("%d",&n);
	int l=0,r=n,mid,w1,w2;
	while(l+1<r)
	{
		mid=(l+r)>>1;
		printf("? %d\n",mid);fflush(stdout);
		scanf("%d",&w1);
		printf("? %d\n",mid+1);fflush(stdout);
		scanf("%d",&w2);
		if(w1<w2)r=mid;
		else l=mid;
	}
	printf("! %d",l+1);fflush(stdout);
	return 0;
}