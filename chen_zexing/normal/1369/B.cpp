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
char a[100005];
int main() {
    int T;
    cin>>T;
    while(T--)
    {
        int n,i,j;
        scanf("%d",&n);
        scanf("%s",a);
        for(i=n-1;i>=0&&a[i]=='1';i--);
        for(j=0;j<n&&a[j]=='0';j++) printf("0");
        if(j<i+1) printf("0");
        for(j=i+1;j<n;j++) printf("1");
        printf("\n");
    }
    return 0;
}