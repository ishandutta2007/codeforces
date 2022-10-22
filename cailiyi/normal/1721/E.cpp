#include<bits/stdc++.h>
#define N 1000000
using namespace std;
char s[N+20];
int n,q,nxt[N+20],last[N+20][26];
int main()
{
    scanf("%s",s+1),n=strlen(s+1);
    memset(last[0],-1,sizeof last[0]);
    for(int i=1;i<=n;++i)
    {
        nxt[i]=last[i-1][s[i]-'a']+1;
        memcpy(last[i],last[nxt[i]],sizeof last[i]);
        last[i][s[nxt[i]+1]-'a']=nxt[i];
    }
    for(scanf("%d",&q);q--;)
    {
        scanf("%s",s+1+n);
        for(int i=n+1;s[i];++i)
        {
            nxt[i]=last[i-1][s[i]-'a']+1;
            memcpy(last[i],last[nxt[i]],sizeof last[i]);
            last[i][s[nxt[i]+1]-'a']=nxt[i];
            printf("%d ",nxt[i]);
        }
        putchar('\n');
    }
    return 0;
}