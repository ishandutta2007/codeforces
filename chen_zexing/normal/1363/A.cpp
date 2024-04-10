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
int a[1005];
int main() {
    int T;
    cin>>T;
    while(T--)
    {
        int n,x,even=0,odd=0;
        scanf("%d%d",&n,&x);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i]%2) odd++;
            else even++;
        }
        if(!odd)
        {
            printf("No\n");
            continue;
        }
        odd--;
        x--;
        if(x>even+(odd/2)*2||even==0&&x%2) printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}