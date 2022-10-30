#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
//#define int long long
//const int N = ;

inline int read()
{
	int X=0;bool flag=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')flag=0;ch=getchar();}
	while(ch>='0'&&ch<='9'){X=(X<<1)+(X<<3)+ch-'0';ch=getchar();}
	if(flag)return X;
	return ~(X-1);
}

inline void write(int X)
{
	if(X<0){X=~(X-1);putchar('-');}
	if(X>9){write(X/10);}
	putchar(X%10+'0');
}

int T,n,m;
char imap[100][100];
bool vis[60][60];
bool in[60][60];

signed main()
{
	T=read();
	while(T--)
	{
		n=read(),m=read();
		/*for(int i=0;i<=n+1;i++)
			for(int j=0;j<=m+1;j++)
				imap[i][j]='.';*/
		memset(imap,0,sizeof imap);
		memset(vis,0,sizeof vis);
		bool flag1=1,flag2=0;
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			char temp[100];
			cin>>temp+1;
			for(int j=1;j<=m;j++)
			{
				imap[i][j]=temp[j];
				if(temp[j]=='R'||temp[j]=='W')flag2=1;
			}
		}
		if(!flag2)imap[1][1]='R';
			for(int i=1;i<=n;i++)
				for(int j=1;j<=m;j++)
					for(int k=1;k<=n;k++)
						for(int h=1;h<=m;h++)
						{
							
							if(imap[k][h]=='R')
							{
								in[k][h]=1;
								if(imap[k][h+1]=='R'||imap[k][h-1]=='R'||imap[k-1][h]=='R'||imap[k+1][h]=='R')
								{
									flag1=0;
									i=n+1,j=m+1,k=n+1,h=m+1;
								}
								if(!vis[k][h])
								{
									vis[k][h]=true;
									cnt++;
								}
								if(!vis[k+1][h]&&k<n)
								{
									vis[k+1][h]=true;
									cnt++;
								}
								if(!vis[k-1][h]&&k>1)
								{
									vis[k-1][h]=true;
									cnt++;
								}
								if(!vis[k][h+1]&&h<m)
								{
									vis[k][h+1]=true;
									cnt++;
								}if(!vis[k][h-1]&&h>1)
								{
									vis[k][h-1]=true;
									cnt++;
								}
								imap[k][h+1]='W';
								imap[k][h-1]='W';
								imap[k+1][h]='W';
								imap[k-1][h]='W';
								if(cnt>=n*m)i=n+1,j=m+1,k=n+1,h=m+1;
							}
							else if(imap[k][h]=='W')
							{
								in[k][h]=1;
								if(imap[k][h+1]=='W'||imap[k][h-1]=='W'||imap[k-1][h]=='W'||imap[k+1][h]=='W')
								{
									flag1=0;
									i=n+1,j=m+1,k=n+1,h=m+1;
								}
								if(!vis[k][h])
								{
									vis[k][h]=true;
									cnt++;
								}
								if(!vis[k+1][h]&&k<n)
								{
									vis[k+1][h]=true;
									cnt++;
								}
								if(!vis[k-1][h]&&k>1)
								{
									vis[k-1][h]=true;
									cnt++;
								}
								if(!vis[k][h+1]&&h<m)
								{
									vis[k][h+1]=true;
									cnt++;
								}
								if(!vis[k][h-1]&&h>1)
								{
									vis[k][h-1]=true;
									cnt++;
								}
								imap[k][h+1]='R';
								imap[k][h-1]='R';
								imap[k+1][h]='R';
								imap[k-1][h]='R';	
								if(cnt>=n*m)i=n+1,j=m+1,k=n+1,h=m+1;
							}
						}
		if(flag1)
		{
			cout<<"YES"<<endl;
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=m;j++)
				{
					printf("%c",imap[i][j]);
				}
				puts("");
			}
		}
		else cout<<"NO"<<endl;	
	}
	return 0;
}