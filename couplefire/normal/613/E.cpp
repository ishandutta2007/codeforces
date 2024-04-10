#include <bits/stdc++.h>
#define pb push_back
#define int long long
using namespace std;
 
inline int read()
{
	int sum=0,ff=1; char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-') ff=-1;
		ch=getchar();
	}
	while(isdigit(ch))
		sum=sum*10+(ch^48),ch=getchar();
	return sum*ff;
}
 
const int N=2005;
const int mo=1e9+7;
const int base=131;
 
char ch[3][N],t[N];
int Hash1[3][N],Hash2[3][N],Hasht[N],bin[N];
int n,m,f[3][N][N],g[3][N][N],ans,gs;
 
inline int get1(int l,int r,int id)
{
	return Hash1[id][r]-Hash1[id][l-1]*bin[r-l+1];
}
 
inline int get2(int l,int r,int id)
{
	return Hash2[id][l]-Hash2[id][r+1]*bin[r-l+1];
}
 
inline void Add(int &x,int y)
{
	x+=y;
	if(x>=mo) x-=mo;
}
 
inline int merge(int H1,int H2,int len)
{
	return H2+H1*bin[len];
}
 
inline void dp()
{
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	for ( int i=1;i<=m;i++ ) 
		Hasht[i]=Hasht[i-1]*base+(t[i]-'a'+1);
	for ( int i=1;i<=2;i++ ) 
		for ( int j=1;j<=n;j++ )
			for ( int k=j;k>=1;k-- )
			{
				int len=2*(j-k+1);
				if(len>m) continue;
				int HA=get1(k,j,i);
				int HB=get2(k,j,3-i);
				int HH=Hasht[len];
				if(merge(HB,HA,j-k+1)==HH) 
				{
					if(len==m) gs++;
					else g[i][j][len]=1;
				}
			}
	for ( int i=1;i<=2;i++ ) 
		for ( int j=1;j<=n;j++ )
			if(ch[i][j]==t[1]) g[i][j][1]=1;
	for ( int i=m;i>=1;i-- ) 
		Hasht[i]=Hasht[i+1]*base+(t[i]-'a'+1);
	for ( int k=1;k<m;k++ ) 
		for ( int j=1;j<=n;j++ ) 
			for ( int i=1;i<=2;i++ ) 
			{
				if(g[i][j][k]) 
					if(j<n&&ch[i][j+1]==t[k+1]) 
						Add(f[i][j+1][k+1],g[i][j][k]);
				if(f[i][j][k]) 
				{
					if(j<n&&ch[i][j+1]==t[k+1]) 
						Add(f[i][j+1][k+1],f[i][j][k]);
					if(ch[3-i][j]==t[k+1]) 
						Add(g[3-i][j][k+1],f[i][j][k]);
				}
			}
	for ( int i=1;i<=2;i++ ) 
		for ( int j=1;j<=n;j++ ) 
		{
			if(ch[i][j]==t[m]) 
			{
				if(m==1) Add(ans,1);
				Add(ans,f[i][j-1][m-1]);
				Add(ans,g[i][j-1][m-1]);
			}
			for ( int k=j;k<=n;k++ )
			{
				int len=(k-j+1)*2;
				if(len>m) continue;
				int HA=get1(j,k,3-i);
				int HB=get2(j,k,i);
				int HH=Hasht[m-len+1];
				if(merge(HA,HB,k-j+1)==HH)
				{
					if(len==m&&m!=2) gs++;
					else 
					{
						Add(ans,f[i][j-1][m-len]);
						Add(ans,g[i][j-1][m-len]);
					}
				}
			}
		}
}
					
signed main()
{
	scanf("%s",ch[1]+1);
	scanf("%s",ch[2]+1);
	n=strlen(ch[1]+1);
	scanf("%s",t+1);
	m=strlen(t+1);
	bin[0]=1;
	int Lim=max(n,m);
	for ( int i=1;i<=Lim;i++ ) 
		bin[i]=bin[i-1]*base; 
	for ( int i=1;i<=2;i++ ) 
		for ( int j=1;j<=n;j++ ) 
			Hash1[i][j]=Hash1[i][j-1]*base+(ch[i][j]-'a'+1);
	for ( int i=1;i<=2;i++ ) 
		for ( int j=n;j>=1;j-- ) 
			Hash2[i][j]=Hash2[i][j+1]*base+(ch[i][j]-'a'+1);
	dp();
	reverse(t+1,t+m+1);
	dp();
	Add(ans,gs/2);
	if(m==1) ans/=2;
	printf("%lld\n",ans);
	return 0;
}