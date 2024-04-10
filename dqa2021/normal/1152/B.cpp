#include<cstdio>
#include<algorithm> 
using namespace std;

int n;
int rec[100];
int tot;
int main()
{
	scanf("%d",&n);
	while (((n+1)&(-n-1))!=n+1)
	{
		int pos;
		for (int i=19;~i;i--) if ((n>>i)%2==0){pos=i;break;}
		rec[++*rec]=pos+1; n^=(1<<pos+1)-1; tot++; //printf("n:%d\n",n);
		if (((n+1)&(-n-1))==n+1) break;
		n++; tot++; //printf("n:%d\n",n);
	}
	printf("%d\n",tot);
	for (int i=1;i<=(*rec);i++) printf("%d ",rec[i]); puts("");
	return 0;
}