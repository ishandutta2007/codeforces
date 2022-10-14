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
char s[1000003];
signed main()
{
	int T=read();
	while(T--)
	{
		int n=read();
		scanf("%s",s+1);
		for(int i=1; i<=n; i++) if(s[i]=='b') printf("%c",s[i]);
		for(int i=1; i<=n; i++) if(s[i]!='b') printf("%c",s[i]);
		puts("");
	}
	return 0;
}