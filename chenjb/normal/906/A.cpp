#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
int v[30];
char s[210000],b[30],now;
int main()
{
    memset(v,0,sizeof(v));
    now=26;
    int n;
    scanf("%d",&n);
    int flag=0;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        char tt[5];
        scanf("%s",tt);
        scanf("%s",s);
        int len=strlen(s);
        if (tt[0]=='.')
        {
            for(int j=0;j<len;j++)
            {
                if (s[j]<'a'||s[j]>'z')continue;
                if (v[s[j]-'a']==0){ v[s[j]-'a']=1; now--; }
            }
            if (now==1)flag=1;
        }
        if (tt[0]=='!')
        {
            if (flag)ans++;
            memset(b,0,sizeof(b));
            int tmp=0;
            for(int j=0;j<len;j++)
            {
                if (s[j]<'a'||s[j]>'z')continue;
                b[s[j]-'a']=1;
                if (v[s[j]-'a']==0)tmp++;
            }
            for(int j=0;j<26;j++)if (b[j]==0 && v[j]==0){ v[j]=1; now--; }
            if (now==1)flag=1;
            if (tmp==1)flag=1;
        }
        if (tt[0]=='?')
        {
            if (flag && i!=n)ans++;
            if (flag)continue;
            if (s[0]<'a'||s[0]>'z')continue;
            if (v[s[0]-'a']==0){ v[s[0]-'a']=1; now--; }
            if (now==1)flag=1;
        }
    }
    printf("%d\n",ans);
}