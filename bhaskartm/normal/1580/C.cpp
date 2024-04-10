#include<bits/stdc++.h>
using namespace std;
const int N=200005,M=505;
int n,m,x[N],y[N],b[M][M],r[N],c[N];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&x[i],&y[i]);
	for(int i=1,h=0,s=0;i<=m;i++)
	{
		int o,p;
		scanf("%d%d",&o,&p);
		if(o==1)
			s++;
		else
			s--;
		int w,ps;
		if(c[p])
			w=-1,ps=c[p],c[p]=0;
		else
			w=1,ps=i,c[p]=i;
		int l=x[p]+y[p];
		if(l>400)
		{
			for(int j=ps;j<=m;j+=l)
			{
				if(ps!=i&&i>j&&i<=j+x[p])
					h--;
				r[j]+=w,r[min(m+1,j+x[p])]-=w;
			}
		}
		else
		{
			for(int j=ps%l,z=0;z<x[p];z++,j=(j+1)%l)
				b[l][j]+=w;
		}
		h+=r[i];
		int a=h;
		for(int j=2;j<=400;j++)
			a+=b[j][i%j];
		printf("%d\n",s-a);
	}
	return 0;
}