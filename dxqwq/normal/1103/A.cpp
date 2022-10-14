#include<bits/stdc++.h>
#define mp make_pair
#define pi pair<int,int>
#define pb push_back
//#define int long long
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int x=-1,y=-1;
char s[1000003];
signed main()
{
	scanf("%s",s);
	int n=strlen(s);
	for(int i=0; i<n; i++) if(s[i]=='0')
	{
		++x,x%=2;
		printf("%d 1\n",2*x+1);
	}
	else
	{
		++y,y%=4;
		printf("%d 2\n",y+1);
	}
	return 0;
}