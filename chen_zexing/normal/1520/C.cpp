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
int ans[105][105];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        cin>>n;
        if(n==2){
            puts("-1");
            continue;
        }
        if(n==1){
            puts("1");
            continue;
        }
        vector <int> v;
        for(int i=1;i<=n*n;i+=2) v.push_back(i);
        for(int i=2;i<=n*n;i+=2) v.push_back(i);
        for(int i=1;i<=n;i++,puts(""))
            for(int j=1;j<=n;j++)
                printf("%d ",v[(i-1)*n+j-1]);
    }
    return 0;
}
//
/// 
//01
// 
//
//dp