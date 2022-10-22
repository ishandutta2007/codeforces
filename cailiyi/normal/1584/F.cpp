#include<bits/stdc++.h>
#define N 10
#define M 52
using namespace std;
inline int id(char ch)
{
    if(ch<='Z') return ch-'A'+1;
    return ch-'a'+27;
}
int T,n,len[N],nxt[N][M*2+5][M+5],num[N][M*2+5],last[M+5],f[M+5][1<<N],p[N][M+5][2];
char s[N][M*2+5];
inline int get(int x,int s,int y)
{
    int ret=0;
    for(int i=0;i<n;++i)
    {
        int w=p[i][x][s>>i&1];
        if(nxt[i][w][y]==len[i]+1) return -1;
        ret|=num[i][nxt[i][w][y]]<<i;
    }
    return ret;
}
inline int dfs(int x,int s)
{
    if(~f[x][s]) return f[x][s];
    for(int y=1;y<=M;++y)
    {
        int temp=get(x,s,y);
        if(~temp) f[x][s]=max(f[x][s],dfs(y,temp));
    }
    return ++f[x][s];
}
inline void put(int x) {putchar(x<=26?'A'+x-1:'a'+x-27);}
inline void print(int x,int s)
{
    if(!f[x][s]) return;
    for(int y=1;y<=M;++y)
    {
        int temp=get(x,s,y);
        if(~temp && f[y][temp]+1==f[x][s])
            return put(y),print(y,temp);
    }
}
int main()
{
    for(scanf("%d",&T);T--;)
    {
        scanf("%d",&n);
        for(int i=0;i<n;++i)
        {
            scanf("%s",s[i]+1);
            len[i]=strlen(s[i]+1);
            fill(last,last+M+1,len[i]+1);
            for(int j=len[i];~j;--j)
            {
                for(int k=1;k<=M;++k) nxt[i][j][k]=last[k];
                if(!j) break;
                int ch=id(s[i][j]);
                num[i][j]=(last[ch]!=(len[i]+1));
                p[i][ch][num[i][j]]=last[ch]=j;
            }
        }
        memset(f,-1,sizeof f);
        printf("%d\n",dfs(0,0));
        print(0,0),putchar('\n');
    }
    return 0;
}