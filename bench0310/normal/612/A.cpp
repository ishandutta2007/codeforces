#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,p,q;
    scanf("%d%d%d",&n,&p,&q);
    char s[n+1];
    scanf("%s",s);
    for(int o=0;o*p<=n;o++)
    {
        if((n-o*p)%q) continue;
        printf("%d\n",o+(n-o*p)/q);
        for(int i=0;i<o*p;i+=p)
        {
            for(int j=0;j<p;j++) printf("%c",s[i+j]);
            printf("\n");
        }
        for(int i=o*p;i<n;i+=q)
        {
            for(int j=0;j<q;j++) printf("%c",s[i+j]);
            printf("\n");
        }
        return 0;
    }
    printf("-1\n");
    return 0;
}