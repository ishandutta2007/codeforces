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
using namespace std;
int pre[1005];
int main() {
    int T;
    char c;
    scanf("%d",&T);
    while(scanf("%c",&c)&&c!='\n');
    while(T--)
    {
        int x=1;
        pre[0]=0;
        while(scanf("%c",&c)&&c!='\n')
        {
            if(c=='1') pre[x]=pre[x-1]+1;
            if(c=='0') pre[x]=pre[x-1];
            x++;
        }
        int ans=9999;
        for(int i=0;i<x;i++)
        {
            if(i-pre[i]+pre[x-1]-pre[i]<ans)
                ans=i-pre[i]+pre[x-1]-pre[i];
        }
        for(int i=0;i<x;i++)
        {
            if(pre[i]+x-1-i-pre[x-1]+pre[i]<ans)
                ans=pre[i]*2+x-1-i-pre[x-1];
        }
        printf("%d\n",ans);
    }
    return 0;
}