#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>
using namespace std;
int n,a[1005],i,k,j;
int main()
{
    scanf("%d",&n);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=n;i<<=1)
    {
        for(j=1;j<=n;j+=i)
        {
            for(k=j;k<j+i-1;k++)
                if(a[k]>a[k+1])
                    break;
            if(k==j+i-1)
                break;
        }
        if(j>n)
            break;
    }
    printf("%d",i>>1);
}