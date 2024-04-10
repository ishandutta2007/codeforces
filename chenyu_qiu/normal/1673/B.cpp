#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cmath>
#define ll long long
using namespace std;
inline int getint(){
    char c=getchar();int x=0;bool p=0;
    while((c>'9'||c<'0')&&c!='-')c=getchar();
    if(c=='-')p=1,c=getchar();
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    if(p)x=-x;return x;
}
#define maxn 200020
char s[maxn];
int n;
bool d[30],vis[30][30],f[30];
int main(){
	int t=getint();
	while(t--){
		scanf("%s",s+1);
		n=strlen(s+1);
		memset(d,0,sizeof(d));
		for(int i=1;i<=n;++i)d[s[i]-'a'+1]=1;
		memset(f,0,sizeof(f));
		memset(vis,0,sizeof(vis));
		bool p=1;
		for(int i=1;i<=n;++i){
			int nc=s[i]-'a'+1;
			for(int j=1;j<=26;++j)vis[j][nc]=1;
			if(!f[nc]){f[nc]=1;memset(vis[nc],0,sizeof(vis[nc]));continue;}
			for(int j=1;j<=26;++j)if(vis[nc][j]!=d[j]){p=0;break;}
			memset(vis[nc],0,sizeof(vis[nc]));
			if(!p)break;
		}
		if(p)puts("YES");
		else puts("NO");
	}
	return 0;
}