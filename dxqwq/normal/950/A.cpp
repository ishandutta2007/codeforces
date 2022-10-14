#include<bits/stdc++.h>
#define mp make_pair
#define pi pair<int,int>
#define pb push_back
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}

int main()
{
	int a=read(),b=read(),c=read();
	if(a>b+c) printf("%d\n",(b+c)*2);
	else if(b>a+c) printf("%d\n",(a+c)*2);
	else printf("%d\n",a+b+c-(a+b+c)%2);
	return 0;
}