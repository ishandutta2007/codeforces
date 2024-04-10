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
char a[1000003];
int main()
{
	int T=read();
	while(T--)
	{
		scanf("%s",a+1);
		int n=strlen(a+1);
		int x=0,y=0,z=0;
		for(int i=1; i<=n; i++) if(a[i]=='(')
		++x;
		else if(a[i]==')') 
		{
			if(x) --x,++z;
		}
		else if(a[i]=='[')
		{
			++y;
		}
		else
		{
			if(y) --y,++z;
		}
		printf("%d\n",z);
	}
	return 0;
}