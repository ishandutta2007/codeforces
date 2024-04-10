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
int mp[400005];
int main() {
    int q,x,ans=0;
    scanf("%d%d",&q,&x);
    while(q--)
    {
        int t;
        scanf("%d",&t);
        mp[t%x]++;
        while(mp[ans%x])
        {
            mp[ans%x]--;
            ans++;
        }
        printf("%d\n",ans);
    }
    return 0;

}