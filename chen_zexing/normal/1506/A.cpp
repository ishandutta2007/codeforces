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

int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        long long n,m,x;
        cin>>n>>m>>x;
        long long a=(x-1)%n+1,b=(x-1)/n+1;
        printf("%lld\n",(a-1)*m+b);
    }
    return 0;
}
//
/// 
//01
// 
//
//dp