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
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
int a[55];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        cin>>n;
        for(int i=1;i<=n*2;i++) scanf("%d",&a[i]);
        sort(a+1,a+n*2+1);
        for(int i=n;i>=1;i--) printf("%d %d ",a[i],a[n*2-i+1]);
        puts("");
    }
    return 0;
}
//
/// 
//01
// 
//
//dp