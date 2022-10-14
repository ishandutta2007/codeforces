#include<bits/stdc++.h>
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
inline long long readll(){
   long long s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
using namespace std;
char ch[1000003];
int main()
{
	int T=read();
	while(T--)
	{
		scanf("%s",ch);
		int t=strlen(ch),x=0,y=0,z=0;
		for(int i=0; i<t; i++) if(ch[i]=='P') x++; else if(ch[i]=='R') y++; else z++;
		if(x>y) if(x>z) for(int i=0; i<t; i++) printf("S");
		else for(int i=0; i<t; i++) printf("R");
		else if(y>z) for(int i=0; i<t; i++) printf("P");
		else for(int i=0; i<t; i++) printf("R");
		puts("");
	}
	return 0;
}