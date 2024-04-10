#include <stdio.h>
#include <iostream>
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
        sort(a+1,a+n+1);
        if(a[1]<0) puts("NO");
        else{
            puts("YES");
            puts("101");
            for(int i=0;i<=100;i++) printf("%d ",i);
            puts("");
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