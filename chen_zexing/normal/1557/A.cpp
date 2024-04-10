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
int a[100005];
int main() {
    int T = 1;
    cin >> T;
    while (T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        double s1=0;
        for(int i=1;i<n;i++) s1+=a[i];
        s1=(s1)/(n-1);
        printf("%.8lf\n",s1+a[n]);
    }
    return 0;
}
//
/// 
//01
//
//!