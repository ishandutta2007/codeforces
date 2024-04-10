#include <stdio.h>
int main()
{
	int n,t,to,k=n,p=1,j=-1,f;
	scanf("%d %d",&n,&to);
	k=n;f=to;
	for(int i=1;i<n;i++){
		scanf("%d",&t);
		if(to>t){
			if(p){
			p=0;
			k=i;}
			else goto out;
		}
		to=t;
	}
	if(p==0&&(f<t))goto out;
	j=n-k;
	out:
	printf("%d",j);
}