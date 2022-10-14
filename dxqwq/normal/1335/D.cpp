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
char a[13][13];
int main()
{
	int T=read();
	while(T--)
	{
		for(int i=1; i<=9; i++) scanf("%s",a[i]);
		for(int i=1; i<=9; i++) for(int j=0; j<9; j++) if(a[i][j]=='2') a[i][j]='3';
		for(int i=1; i<=9; i++) printf("%s\n",a[i]);
	}
	return 0;
}