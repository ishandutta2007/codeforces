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
        scanf("%d",&n);
        int t=n%11;
        if(t<=n/11/10) puts("YES");
        else puts("NO");
    }
    return 0;
}
//
/// 
//01
// 
//
//dp