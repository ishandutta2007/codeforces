#include<cstdio>
#define N 1000010
using namespace std;
int s[N],t[N],n,mx,a,T;
bool chk(int l,int r)
{
	if(r>mx) r=mx;
	return s[r]-s[l-1]>0;
}
bool check()
{
	for(int i=1;i<=mx;i++)
	{
		if(!t[i]) continue;
		for(int j=i;j<=mx;j+=i)
			if(chk(j,j+i-1)&&!t[j/i]) return 0;
	}
	return 1;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&mx);
		for(int i=1;i<=n;i++)
			scanf("%d",&a),t[a]=1;
		for(int i=1;i<=mx;i++) s[i]=s[i-1]+t[i];
		printf("%s\n",check()?"Yes":"No");
		for(int i=1;i<=mx;i++) t[i]=s[i]=0;
	}
}