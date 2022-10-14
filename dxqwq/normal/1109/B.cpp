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
char s[100003];
int cnt[1003];
signed main()
{
	scanf("%s",s);
	int n=strlen(s);
	for(int i=0; i<n; i++) ++cnt[s[i]];
	for(int i='a'; i<='z'; i++) if(cnt[i]>=n-1) puts("Impossible"),exit(0);
	if(n<=3) puts("Impossible");
	else if(n&1) puts("2");
	else 
	{
		int ans=0;
		while(!(n&1))
		{
			n>>=1,ans=0;
			for(int i=0; i<n; i++) if(s[i]!=s[i+n]) ans=1;
			if(ans) puts("1"),exit(0);			
		}
		puts("2");
	}
	return 0;
}
//abacaba