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
int a[305][305];
int main() {
    int T;
    cin>>T;
    while(T--)
    {
        memset(a,0,sizeof(a));
        int n,k;
        scanf("%d%d",&n,&k);
        if(k%n==0)
        {
            printf("0\n");
            int t=k/n;
            for(int i=0;i<n;i++)
                for(int j=i+1;j<=i+t;j++)
                    a[i][j%n]=1;
        }
        else{
            printf("2\n");
            int t=k/n;
            int m=k-t*n;
            for(int i=0;i<m;i++)
                for(int j=i+1;j<=i+t+1;j++)
                    a[i][j%n]=1;
            for(int i=m;i<n;i++)
                for(int j=i+1;j<=i+t;j++)
                    a[i][j%n]=1;
        }
        for(int i=0;i<n;i++,printf("\n"))
            for(int j=0;j<n;j++)
                printf("%d",a[i][j]);
    }
    return 0;
}