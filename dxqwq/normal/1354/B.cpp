#include<bits/stdc++.h>
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
using namespace std;
char s[1000003];
int main()
{
	int T=read();
	while(T--)
	{
		scanf("%s",s);
		int l=0,r=0,len=strlen(s),x=0,y=0,z=0,ans=len;
		if(s[0]=='1') x++; 
		if(s[0]=='2') y++; 
		if(s[0]=='3') z++; 
		while(!(x&&y&&z))
		{
			++r;
			if(r==len) break;
			if(s[r]=='1') x++; 
			if(s[r]=='2') y++; 
			if(s[r]=='3') z++; 
		}
		if(!(x&&y&&z))
		{
			puts("0");
			continue;
		}
		while(1) 
		{
			while(1)
			{
				if(s[l]=='1') if(x==1) break; else --x,++l;
				if(s[l]=='2') if(y==1) break; else --y,++l;
				if(s[l]=='3') if(z==1) break; else --z,++l;
			}
			ans=min(ans,r-l+1);
			++r;
			if(r==len) break;
			if(s[r]=='1') x++; 
			if(s[r]=='2') y++; 
			if(s[r]=='3') z++; 
		}
		printf("%d\n",ans);
	}
	return 0;
}