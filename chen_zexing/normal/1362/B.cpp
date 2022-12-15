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
int a[1050],b[1050],s[1050];
int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        memset(a,0,sizeof(a));
        memset(b,0,sizeof(b));
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&s[i]);
            a[s[i]]++;
        }
        int ans=-1;
        for(int i=1;i<=1024;i++)
        {
            memset(b,0,sizeof(b));
            int f=1;
            for(int j=1;j<=n;j++) {
                b[i ^ s[j]]++;
            }
            for(int j=0;j<=1024;j++)
            {
                if(a[j]!=b[j])
                {
                    f=0;
                    break;
                }
            }
            if(f)
            {
                ans=i;
                break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}