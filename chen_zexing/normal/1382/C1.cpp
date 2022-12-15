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
char a[100005],b[100005];
int ans1[100005],ans2[100005];
int main() {
    int T;
    cin>>T;
    while(T--)
    {
        int n,now,t1=1,t2=1,k=0;
        cin>>n;
        scanf("%s",a);
        scanf("%s",b);
        now=a[0]-'0';
        for(int i=1;i<n;i++)
        {
            if(now!=a[i]-'0')
            {
                ans1[t1++]=i;
                now=a[i]-'0';
                k++;
            }
        }
        if(now==1)
        {
            ans1[t1++]=n;
            k++;
        }
        now=b[0]-'0';
        for(int i=1;i<n;i++)
        {
            if(now!=b[i]-'0')
            {
                ans2[t2++]=i;
                now=b[i]-'0';
                k++;
            }
        }
        if(now==1)
        {
            ans2[t2++]=n;
            k++;
        }
        printf("%d ",k);
        for(int i=1;i<t1;i++) printf("%d ",ans1[i]);
        for(int i=t2-1;i>=1;i--) printf("%d ",ans2[i]);
        printf("\n");
    }
    return 0;
}