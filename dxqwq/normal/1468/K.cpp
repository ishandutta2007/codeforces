#include<bits/stdc++.h>
//#define int long long
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int X[5003],Y[5003];
char s[5003];
signed main()
{
	int T=read();
	while(T--)
	{
		scanf("%s",s+1);
		int len=strlen(s+1);
		for(int i=1,x=0,y=0; i<=len; i++)
		{
			if(s[i]=='U') ++y;
			else if(s[i]=='D') --y;
			else if(s[i]=='L') --x;
			else ++x;
			X[i]=x,Y[i]=y;
		}
		bool F=0;
		for(int i=1,x,y; i<=len; i++) 
		{
			x=0,y=0;
			for(int j=1; j<=len; j++)
			{
				if(s[j]=='U') 
				{
					++y;
					if(x==X[i]&&y==Y[i]) --y;
				}
				else if(s[j]=='D') 
				{
					--y;
					if(x==X[i]&&y==Y[i]) ++y;
				}
				else if(s[j]=='L') 
				{
					--x;
					if(x==X[i]&&y==Y[i]) ++x;
				}
				else 
				{
					++x;
					if(x==X[i]&&y==Y[i]) --x;
				}
			}
			if(x==0&&y==0) 
			{
				printf("%d %d\n",X[i],Y[i]);
				F=1;
				break;
			}
		}
		if(!F) puts("0 0");
 	}
	return 0;
}