#include<bits/stdc++.h>
using namespace std;
int T,cnt;
char s[5];
int main()
{
    for(scanf("%d",&T);T--;)
    {
        scanf("%s %s",s,s+2),cnt=0;
        for(int i=0;i<4;++i)
        {
            bool flag=1;
            for(int j=0;j<i;++j)
                if(s[j]==s[i]) {flag=0;break;}
            cnt+=flag;
        }
        printf("%d\n",cnt-1);
    }
    return 0;
}