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
char a[1000003];
int main()
{
	scanf("%s",a);
	int len=strlen(a);
	long long p=0,q=0;
	long long ans=0;
	for(int i=1; i<len; i++) if(a[i]=='v' && a[i-1]=='v') ++p,ans+=q; else if(a[i]=='o')q+=p;
	cout<<ans;
	return 0;
}