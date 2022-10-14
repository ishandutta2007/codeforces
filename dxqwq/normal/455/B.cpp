#include<bits/stdc++.h>
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int n=read(),k=read(),cnt;
int f[100003];
char s[100003];
int trie[200003][26];
inline void dfs(int x)
{
	bool t=0;
	for(int i=0; i<26; ++i) if(trie[x][i]) dfs(trie[x][i]),f[x]|=f[trie[x][i]],t=1;
	t?f[x]^=3:f[x]=1;
}
int main()
{
	for(int i=1; i<=n; ++i)
	{
		scanf("%s",s);
		int len=strlen(s),now=0;
		for(int j=0; j<len; ++j) (trie[now][s[j]-'a'])?now=trie[now][s[j]-'a']:now=trie[now][s[j]-'a']=++cnt;
	}
	dfs(0);
	if(!f[0]) puts("First"); else if(f[0]==3) puts("Second"); else if((k&1)&&f[0]==2) puts("First"); else puts("Second");
	return 0;
}