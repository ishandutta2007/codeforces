#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,i,j,k,a,f[205],t,m;
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
	 	memset(f,0,sizeof(f));
	 	for(i=1;i<=n;++i)
	 		for(j=1;j<=m;++j)
	 		{
			 	scanf("%d",&a);
	 			f[i+j]^=a;
	 		}
	 	for(i=1;i<=n+m;++i)
	 		if(f[i])
	 			break;
	 	if(i>n+m)
	 		puts("Jeel");
	 	else
	 		puts("Ashish");
	}
}