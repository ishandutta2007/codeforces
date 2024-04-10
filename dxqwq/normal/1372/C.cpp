#include<bits/stdc++.h>
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
using namespace std;
int main()
{
	int T=read();
	while(T--)
	{
		int n=read();
		bool x=1,y=1;
		int z=1;
		for(int i=1; i<=n; i++) if(read()==i) 
		{
			y=0;
			if(z==0) z=-1;
		} 
		else 
		{
			x=0;
			if(z==1) z=0;
			if(z==-1) z=-2;
		}
		if(x) puts("0"); else if(y || z!=-2) puts("1"); else puts("2");
	 } 
	return 0;
}