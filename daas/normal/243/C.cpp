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
#define int long long
using namespace std;
const int MAXN=2e3+10;
int read()
{
	int kkk=0,x=1;
	char c=getchar();
	while((c<'0' || c>'9') && c!='-') c=getchar();
	if(c=='-') c=getchar(),x=-1;
	while(c>='0' && c<='9') kkk=kkk*10+(c-'0'),c=getchar();
	return kkk*x;
}
int n,cnt,X[MAXN],Y[MAXN],ins[MAXN][2];
int vis[MAXN][MAXN],fbd[MAXN][MAXN],S[MAXN][MAXN],change[4][2]={{-1,0},{1,0},{0,-1},{0,1}},dl[MAXN*MAXN][2],h,t,Cx[MAXN],Cy[MAXN];
signed main()
{
	n=read();
	X[++X[0]]=0;
	Y[++Y[0]]=0;
	X[++X[0]]=-1e9-1;
	X[++X[0]]=1e9+1;
	Y[++Y[0]]=-1e9-1;
	Y[++Y[0]]=1e9+1;
	for(int i=1,x=0,y=0;i<=n;++i)
	{
		char s[4]; scanf("%s",s);
		int val=read();
		ins[i][1]=val;
		if(s[0]=='U') ins[i][0]=0,x-=val;
		else if(s[0]=='D') ins[i][0]=1,x+=val;
		else if(s[0]=='L') ins[i][0]=2,y-=val;
		else if(s[0]=='R') ins[i][0]=3,y+=val;
		X[++X[0]]=x;
		Y[++Y[0]]=y;
	}
	sort(X+1,X+X[0]+1);
	X[0]=unique(X+1,X+X[0]+1)-X-1;
	sort(Y+1,Y+Y[0]+1);
	Y[0]=unique(Y+1,Y+Y[0]+1)-Y-1;
	for(int i=1;i<=X[0];++i)
		for(int j=1;j<=Y[0];++j)
		{
			S[2*i-1][2*j-1]=1;
			if(j!=Y[0]) S[2*i-1][2*j]=Y[j+1]-Y[j]-1;
			if(i!=X[0]) S[2*i][2*j-1]=X[i+1]-X[i]-1;
			if(i!=X[0] && j!=Y[0]) S[2*i][2*j]=(X[i+1]-X[i]-1)*(Y[j+1]-Y[j]-1);
		}
	for(int i=1;i<X[0];++i) if(X[i]+1==X[i+1]) Cx[2*i]=1;
	for(int i=1;i<Y[0];++i) if(Y[i]+1==Y[i+1]) Cy[2*i]=1;
	int xx=1,yy=1;
	while(X[xx]!=0) ++xx;
	while(Y[yy]!=0) ++yy;
	xx=2*xx-1;
	yy=2*yy-1;
	fbd[xx][yy]=1;
	for(int i=1,x=0,y=0;i<=n;++i)
	{
		int val=ins[i][1];
		if(ins[i][0]==0) x-=val;
		else if(ins[i][0]==1) x+=val;
		else if(ins[i][0]==2) y-=val;
		else if(ins[i][0]==3) y+=val;
		while(xx%2==0 || yy%2==0 || X[xx/2+1]!=x || Y[yy/2+1]!=y)
		{
			xx+=change[ins[i][0]][0];
			yy+=change[ins[i][0]][1];
			fbd[xx][yy]=1;
		}
	}
	/*for(int i=1;i<2*X[0];++i)
	{
		for(int j=1;j<2*Y[0];++j)
			cout<<fbd[i][j];
		cout<<endl;
	}
	for(int i=1;i<2*X[0];++i)
	{
		for(int j=1;j<2*Y[0];++j)
			cout<<setw(9)<<S[i][j];
		cout<<endl;
	}*/
	dl[++t][0]=1;
	dl[t][1]=1;
	vis[1][1]=1;
	while(h!=t)
	{
		int ux=dl[++h][0],uy=dl[h][1];
		for(int i=0;i<4;++i)
		{
			int nx=ux+change[i][0];
			int ny=uy+change[i][1];
			if(Cx[nx] || Cy[ny])
			{
				nx+=change[i][0];
				ny+=change[i][1];
			}
			if(nx<1 || nx>2*X[0]-1 || ny<1 || ny>2*Y[0]-1 || fbd[nx][ny] || vis[nx][ny]) continue;
			vis[nx][ny]=1;
			dl[++t][0]=nx;
			dl[t][1]=ny;
		}
	}
	int ans=0;
	for(int i=1;i<2*X[0];++i)
		for(int j=1;j<2*Y[0];++j)
			if(!vis[i][j])
				ans+=S[i][j];
	printf("%lld\n",ans);
	return 0;
}
//ore no turn,draw