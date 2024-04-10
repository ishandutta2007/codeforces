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
using namespace std;
int a[105];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int p1=-1,p2=-1,mn=INT_MAX,mx=INT_MIN;
        for(int i=1;i<=n;i++){
            if(a[i]<mn) mn=a[i],p1=i;
            if(a[i]>mx) mx=a[i],p2=i;
        }
        if(p1>p2) swap(p1,p2);
        printf("%d\n",min(min(n-p1+1,p2),p1+n-p2+1));
    }
    return 0;
}
//
/// 
//01
// 
//
//dp