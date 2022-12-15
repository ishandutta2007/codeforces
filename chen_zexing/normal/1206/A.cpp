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
int a[105],b[105],u[405];
int main() {
    int n,m;
    cin>>n;
    for(int i=1;i<=n;i++) {
        cin >> a[i];
        u[a[i]] = 1;
    }
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>b[i];
        u[b[i]]=1;
    }
    int f=0;
    for(int i=1;i<=n&&f==0;i++)
        for(int j=1;j<=m;j++)
            if(u[a[i]+b[j]]==0)
            {
                printf("%d %d\n",a[i],b[j]);
                f=1;
                break;
            }
}