#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#define hash hassh
using namespace std;
int n,m;
long long ans=1;
int a[1005][1005],l[1005],t[1005];
long long mod=1000000007;
int main() {
    cin>>n>>m;
    int f=1;
    for(int i=1;i<=n;i++) scanf("%d",&l[i]);
    for(int j=1;j<=m;j++) scanf("%d",&t[j]);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            a[i][j]=2;
    for(int i=1;i<=n;i++) {
        for (int j = 1; j <= l[i]; j++)
            a[i][j] = 1;
        a[i][l[i]+1]=0;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=t[i];j++){
            if(a[j][i]) a[j][i]=1;
            else f=0;
        }
        if(a[t[i]+1][i]!=1) a[t[i]+1][i]=0;
        else f=0;
    }
    if(f==0) puts("0");
    else{
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(a[i][j]==2)
                    ans=ans*2%mod;
        printf("%lld\n",ans);
    }
    return 0;
}