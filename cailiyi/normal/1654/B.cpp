#include<bits/stdc++.h>
#define N 200000
using namespace std;
char s[N+5];
bool vis[26];
int T,n,first;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",s+1),n=strlen(s+1);
        memset(vis,0,sizeof vis);
        for(int i=n;i;--i)
            if(!vis[s[i]-'a']) first=i,vis[s[i]-'a']=1;
        printf("%s\n",s+first);
    }
    return 0;
}