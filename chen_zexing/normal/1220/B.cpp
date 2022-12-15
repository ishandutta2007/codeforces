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
#include <unordered_set>
#define hash hassh
using namespace std;
int a[1005][1005];
int f[1005];
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                scanf("%d",&a[i][j]);
        f[2]=sqrt(1LL*a[2][1]*a[3][2]/a[3][1]);
        f[1]=a[2][1]/f[2];
        for(int i=3;i<=n;i++) f[i]=a[i][1]/f[1];
        for(int i=1;i<=n;i++) printf("%d ",f[i]);
    }
    return 0;
}