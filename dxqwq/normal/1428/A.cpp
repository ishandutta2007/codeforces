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
	int T=read();
	while(T--)
	{
		int a=read(),b=read(),c=read(),d=read();
		if(a==c) printf("%d\n",abs(d-b));
		else if(b==d) printf("%d\n",abs(c-a));
		else printf("%d\n",2+abs(c-a)+abs(d-b));
	}
	return 0;
}