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
int ans[1005][1005];
int t[4][4]={8,9,1,13,3,12,7,5,0,2,4,11,6,10,15,14};
int main() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++,puts(""))
        for(int j=1;j<=n;j++)
            printf("%d ",t[i%4][j%4]+((i-1)/4*(n/4)+(j-1)/4)*16),ans[i][j]=t[i%4][j%4]+((i-1)/4*(n/4)+(j-1)/4+1)*16;
    return 0;
}