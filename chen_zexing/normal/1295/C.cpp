#include <stdio.h>
#include <iostream>
#include <queue>
#include <cstdio>
#include <stack>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string.h>
#include <limits.h>
#include <map>
#include <string>
using namespace std;
char s[100005],t[100005];
int nxt[100005][28],a[28];
int main() {
    int T;
    cin>>T;
    while(T--)
    {
        memset(a,0,sizeof(a));
        scanf("%s",s);
        scanf("%s",t);
        int ans=1;
        memset(nxt,-1,sizeof(nxt));
        for(int i=0;i<strlen(s);i++) a[s[i]-'a']=1;
        int f=1;
        for(int i=0;i<strlen(t);i++)
            if(a[t[i]-'a']==0)
            {
                f=0;
                break;
            }
        if(f==0)
        {
            printf("-1\n");
            continue;
        }
        for(int i=0;i<26;i++)
        {
            int now=0;
            while(now<strlen(s))
            {
                while(s[now]-'a'!=i&&now<strlen(s)) now++;
                if(now>=strlen(s)) break;
                for(int j=now;nxt[j][i]==-1&&j>=0;j--) nxt[j][i]=now;
                now++;
            }
        }
        /*
        for(int i=0;i<26;i++,printf("\n"))
            for(int j=0;j<strlen(s);j++)
                printf("%d ",nxt[j][i]);
                */
        int p=0;
        for(int i=0;i<strlen(t);i++)
        {
            if(nxt[p][t[i]-'a']!=-1&&p<strlen(s)) p=nxt[p][t[i]-'a']+1;
            else
            {
                i--;
                p=0;
                ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}