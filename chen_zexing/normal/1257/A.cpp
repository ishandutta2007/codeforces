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
    int T=1;
    cin>>T;
    while(T--) {
        int n,x,a,b;
        cin>>n>>x>>a>>b;
        printf("%d\n",min(n-1,abs(a-b)+x));
    }
    return 0;
}
//
/// 
//01
// 
//
//dp