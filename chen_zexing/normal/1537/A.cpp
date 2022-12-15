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
        int n,sum=0;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),sum+=a[i];
        if(sum==n){
            puts("0");
        }
        else if(sum<n){
            puts("1");
        }
        else{
            printf("%d\n",sum-n);
        }
    }
    return 0;
}
//
/// 
//01
// 
//
//dp