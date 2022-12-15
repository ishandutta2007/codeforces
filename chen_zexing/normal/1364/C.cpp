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
int a[100005],b[100005],cant[1000005],used[1000005];
int main() {
    int n,f=1;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        cant[a[i]]++;
    }
    for(int i=1;i<=n;i++) if(a[i]>i){
            f=0;
            break;
        }
    if(f==0) printf("-1\n");
    else
    {
        int now=0;
        for(int i=1;i<=n;i++) if(a[i]!=a[i-1])
            {
                b[i]=a[i-1];
                used[b[i]]++;
            }
        for(int i=1;i<=n;i++)
        {
            while(used[now]) now++;
            while(cant[now]) now++;
            cant[a[i]]--;
            if(a[i]==a[i-1]) {
                b[i] = now;
                used[now]++;
            }
        }
        for(int i=1;i<=n;i++) printf("%d ",b[i]);
        printf("\n");
    }
    return 0;
}