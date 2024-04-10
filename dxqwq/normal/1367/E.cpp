#include<bits/stdc++.h>
int s[26];
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
using namespace std;
int main(){
	int T=read();
	while(T--)
	{
		int n=read(),m=read();
		for(int i=0; i<26; i++) s[i]=0;
		for(int i=1; i<=n; i++) s[getchar()-97]++;
		while (1)
		{
			int x=__gcd(n,m),y=0;
			for(int i=0; i<26; i++) y+=s[i]/(n/x);
			if(y>=x) break;
			--n;
		}
		printf("%d\n",n);
	}
	return 0;
}