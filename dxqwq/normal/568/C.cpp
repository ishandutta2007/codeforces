// Problem: C. New Language
// Contest: Codeforces - Codeforces Round #315 (Div. 1)
// URL: https://codeforces.com/problemset/problem/568/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I flg deliverance.
#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
// #define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
char s[403];
bool e[403][403];
int pos[403][403];
int n,m,len;
char str[403],ans[403];
bool getans(int x,bool first)
{
    if(x==n) return 1;
    bool use[2][2];
    memset(use,0,sizeof(use));
    for(int c=first?0:str[x]-'a';c<len;c++)
    {
        ans[x]=c+'a';
        if(pos[x][x]&(s[c]=='V'?1:2))
        {
            if(use[s[c]=='V'][first||ans[x]>str[x]]) continue;
            memcpy(pos[x+1],pos[x],sizeof(pos[x]));
            for(int i=0;i<2*n;i++)
                (e[x*2+(s[c]=='V')][i])&&(pos[x+1][i/2]=2-(i&1));
            if(getans(x+1,first||ans[x]>str[x])) return 1;
            use[s[c]=='V'][first||ans[x]>str[x]]=1;
        }
    }
    return 0;
}
signed main(){
    scanf("%s",s);
    len=strlen(s),n=read(),m=read();
    for(int u,v; m--;)
    {
        u=(read()-1)<<1;
        char a=getchar();
        v=(read()-1)<<1;
        char b=getchar();
        u+=(a=='V'),v+=(b=='V');
        e[u][v]=e[v^1][u^1]=1;
    }
    for(int k=0; k<2*n; k++)
    	for(int i=0; i<2*n; i++) if(i!=k)
    		for(int j=0; j<2*n; j++) if(i!=j&&k!=j)
        		e[i][j]|=e[i][k]&&e[k][j];
    bool flg=0;
    for(int i=0; i<n; i++)
    {
        int u=i<<1,v=(i<<1)+1;
        if(e[u][v]&&e[v][u]) flg=1;
        else if(e[v][u]) pos[0][i]=2;
        else if(e[u][v]) pos[0][i]=1;
        else pos[0][i]=3;
    }
    scanf("%s",str);
    if(!flg&&getans(0,false)) printf("%s\n",ans);
    else printf("-1\n");
}