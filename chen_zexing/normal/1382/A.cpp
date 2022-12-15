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
#include <bitset>
#include <vector>
using namespace std;
int have[1005];
int main() {
    int T;
    cin>>T;
    while(T--)
    {
        memset(have,0,sizeof(have));
        int n,m,f=0,p;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        {
            int t;
            scanf("%d",&t);
            have[t]=1;
        }
        for(int i=1;i<=m;i++)
        {
            int t;
            scanf("%d",&t);
            if(have[t])
            {
                p=t;
                f=1;
            }
        }
        if(f)
        {
            printf("YES\n1 %d\n",p);
        }
        else printf("NO\n");
    }
    return 0;
}