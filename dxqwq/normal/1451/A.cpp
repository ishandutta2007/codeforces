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
		int n=read();
		if(n==1) puts("0");
		else if(n==2) puts("1"); 
		else if(n==3) puts("2");
		else if(n&1) puts("3");
		else puts("2");
	}
	return 0;
}