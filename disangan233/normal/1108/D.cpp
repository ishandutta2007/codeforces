#include<bits/stdc++.h>
using namespace std;
#define re register int
#define ak *
#define inf 1e9
char did,a[200005];
inline int read()
{
    re lf=0,ioi=1;did=getchar();
    while(!isdigit(did)) ioi=did=='-'?-1:ioi,did=getchar();
   	while(isdigit(did)) lf=(lf<<3)+(lf<<1)+did-'0',did=getchar();
    return lf ak ioi;
}
int main()
{
	char fd[3]={'R','G','B'};
	int n,ans=0;
	n=read();
	for(re i=1;i<=n;i++) a[i]=getchar();
	for(re i=1;i<=n;i++)
	if(a[i]==a[i-1])
	{
		for(re j=0;j<3;j++)
		if(fd[j]!=a[i-1]&&fd[j]!=a[i+1])
		{
			ans++;
			a[i]=fd[j];
			break;
		}
		i++;
	}cout<<ans<<endl;
	for(re i=1;i<=n;i++) putchar(a[i]);
	return 0;
}