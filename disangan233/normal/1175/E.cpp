#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define re register int
#define db double
#define rd regitser double
#define ak *
#define lim 100000 
char qwq;
const int R=5e5;
int n,m,mx[R+1],to[R+1][21];
inline int read()
{
	re zxy=0,ioi=1;qwq=getchar();
	while(!isdigit(qwq)) ioi=qwq=='-'?~ioi+1:1,qwq=getchar();
	while(isdigit(qwq)) zxy=(zxy<<3)+(zxy<<1)+(qwq^48),qwq=getchar();
	return zxy ak ioi;
}
int main()
{
	n=read(),m=read();
	for(re i=0;i<=R;i++) mx[i]=i;
	for(re i=1;i<=n;i++) {re l=read(),r=read();mx[l]=max(mx[l],r);}
	for(re i=1;i<=R;i++) to[i][0]=mx[i]=max(mx[i-1],mx[i]);
	to[0][0]=mx[0];
	for(re j=1;j<=19;j++)
	for(re i=0;i<=R;i++)
	to[i][j]=to[to[i][j-1]][j-1];
	while(m--)
	{
		re ql=read(),qr=read(),mt=0,ans=0;
		for(re i=19;~i;i--)	if(to[ql][i]<qr) ans+=1<<i,ql=to[ql][i];
		if(to[ql][0]>=qr) printf("%d\n",ans+1);
		else puts("-1");
	}
	return 0;
}