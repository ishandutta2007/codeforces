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
int a[200005];
map <int,int> mp;
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int mx=0,n;
        mp.clear();
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),mp[a[i]]++,mx=max(mx,mp[a[i]]);
        printf("%d\n",max(n%2,mx*2-n));
    }
    return 0;
}
//
/// 
//01
// 
//
//dp