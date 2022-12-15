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
int a[105][105],s[205];
int main() {
    int T;
    cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m;
        long long sum=0;
        memset(s,0,sizeof(s));
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                scanf("%d",&a[i][j]),s[i+j]^=a[i][j];
        for(int i=1;i<=n+m;i++) sum+=s[i];
        if(sum) puts("Ashish");
        else puts("Jeel");
    }
    return 0;
}