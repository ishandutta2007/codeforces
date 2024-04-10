#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>
using namespace std;
const int N=100005,M=1000000007;
int n,i,ans,t,l,a[100005],b[100005],p,q,s;
int main(){
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		l=1;
		while(l<n)
			l<<=1;
		l>>=1;
		ans=0;
		while(l>=1)
		{
			p=q=0;
			for(i=0;i<n;i++)
				if(i/l%2==1)
					a[++p]=i+1;
				else
					b[++q]=i+1;
			printf("%d %d ",p,q);
			for(i=1;i<=p;i++)
				printf("%d ",a[i]);
			for(i=1;i<=q;i++)
				printf("%d ",b[i]);
			printf("\n");
			fflush(stdout);
			scanf("%d",&s);
			ans=max(ans,s);
			l>>=1;
		}
		cout<<-1<<' '<<ans<<endl;
		fflush(stdout);
	}
}