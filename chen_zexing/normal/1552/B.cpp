#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#include <bitset>
#define hash hassh
#define li __int128_t
using namespace std;
int a[50005][6],ans[6];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n,f=1,tar=0;
        scanf("%d",&n);
        for(int j=1;j<=5;j++) ans[j]=INT_MAX;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=5;j++) scanf("%d",&a[i][j]);
            int cnt=0;
            for(int j=1;j<=5;j++) if(ans[j]>a[i][j]) cnt++;
            if(cnt>=3) for(int j=1;j<=5;j++) ans[j]=a[i][j],tar=i;
        }
        for(int i=1;i<=n;i++){
            if(i==tar) continue;
            int cnt=0;
            for(int j=1;j<=5;j++) if(ans[j]>a[i][j]) cnt++;
            if(cnt>=3) f=0;
        }
        printf("%d\n",f?tar:-1);
    }
    return 0;
}
//
/// 
//01
// 
//
//dp
//