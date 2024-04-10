#include<bits/stdc++.h>
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
char ch[1000003];
using namespace std;
int main()
{
	int n=read();
	while(n--)
	{
		scanf("%s",ch);
		int len=strlen(ch);
		printf("%c",ch[0]);
		for(int i=1; i<len; i+=2) printf("%c",ch[i]);
		puts(""); 
	}
	return 0;
}