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
char s[100003];
int main()
{
	int T=read();
	while(T--)
	{
		int n=read(),q=read();
		scanf("%s",s+1);
		for(;q--;)
		{
			int l=read(),r=read();
			bool f=0;
			for(int i=1; i<l; i++)
			if(s[i]==s[l]) f=1;
			for(int i=r+1; i<=n; i++)
			if(s[r]==s[i]) f=1;
			if(f) puts("YES");
			else puts("NO");
		}
	}
	return 0;
}