#include <stdio.h>
#include<iostream>
#include<string>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>
#include <map>
using namespace std;
int a[1005];
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n,c1=0,c2=0;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        if(n%4==0){
            printf("%d\n",n/2);
            for(int i=1;i<=n/4;i++)
            {
                c1=c2=0;
                for(int j=i*4-3;j<=i*4;j++)
                {
                    if(a[j]==1) c1++;
                    else c2++;
                }
                if(c1>=2) printf("1 1 ");
                else printf("0 0 ");
            }
            printf("\n");
        }
        else{
            if(a[n-1]!=a[n]) printf("%d\n",n/2);
            else printf("%d\n",n/2+1);
            for(int i=1;i<=n/4;i++)
            {
                c1=c2=0;
                for(int j=i*4-3;j<=i*4;j++)
                {
                    if(a[j]==1) c1++;
                    else c2++;
                }
                if(c1>=2) printf("1 1 ");
                else printf("0 0 ");
            }
            if(a[n-1]!=a[n]) printf("0\n");
            else printf("%d %d\n",a[n-1],a[n]);
        }
    }
    return 0;
}