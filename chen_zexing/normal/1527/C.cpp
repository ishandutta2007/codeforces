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
int a[100005];
map <int,long long> mp;
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        long long ans=0;
        cin>>n;
        mp.clear();
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            ans+=mp[a[i]]*(n-i+1);
            mp[a[i]]+=i;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
//
/// 
//01
// 
//
//dp