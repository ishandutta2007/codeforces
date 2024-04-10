#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<iomanip>
#include<cstring>
#include<algorithm>
#include<ctime>
#include<vector>
#define ll long long
using namespace std;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,map[1010][1010],ans,pd[1010],id[1010],out[1010];
pair<int,int> a[1010];
int main()
{
	n=read();
	for(int i=1;i<=n;++i) a[i]=make_pair(-read(),i);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)
		for(int j=i,k=1;k<=-a[i].first;++k,j=(j==n+1?1:j+1))
			map[j][i]=1,pd[j]=1;
	for(int i=1;i<=n+1;++i) if(pd[i]) ++ans;
	printf("%d\n",ans);
	for(int i=1;i<=n+1;++i) if(pd[i])
	{
		//for(int j=1;j<=n;++j) out[j]=map[i][j];
		for(int j=1;j<=n;++j) out[a[j].second]=map[i][j];
		for(int j=1;j<=n;++j)
			printf("%d",out[j]);
		putchar('\n');
	}
	return 0;
}
//ore no turn,draw!