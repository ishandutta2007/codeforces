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
int a[300005];
int main() {
    int T=1;
    cin>>T;
    while(T--) {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        int l=0;
        for(int i=1;i<=n;i++){
            if(a[i]>=i-1) l++;
            else break;
        }
        int r=n+1;
        for(int i=n;i>=1;i--){
            if(a[i]>=n-i) r--;
            else break;
        }
        if(l>=r) puts("Yes");
        else puts("No");
    }
    return 0;
}
//
/// 
//01
// 
//
//dp