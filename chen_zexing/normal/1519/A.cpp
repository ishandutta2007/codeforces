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
        long long r,b,d;
        cin>>r>>b>>d;
        if(r>b) swap(r,b);
        if((d+1)*r<b) puts("NO");
        else puts("YES");
    }
    return 0;
}
//
/// 
//01
// 
//
//dp