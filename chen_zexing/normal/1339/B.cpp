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
int a[100005];
bool cmp(int a,int b)
{
    return a<b;
}
int main() {
    int T;
    cin>>T;
    while(T--)
    {
        int n,l,r;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1,cmp);
        if(n%2) l=r=n/2+1;
        else
        {
            l=n/2;
            r=n/2+1;
        }
        while(l&&r<=n)
        {
            printf("%d ",a[l]);
            if(l!=r) printf("%d ",a[r]);
            l--;
            r++;
        }
        printf("\n");
    }
    return 0;
}