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
long long mod=1000000007;
int main() {
    int T=1;
    cin>>T;
    while(T--) {
        int n,k;
        cin>>n>>k;
        long long ans=1;
        for(int i=1;i<=k;i++) ans=ans*n%mod;
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