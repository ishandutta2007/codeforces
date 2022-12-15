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
        int x,y;
        cin>>x>>y;
        if(x==1) puts(y<=1?"YES":"NO");
        else if(x<=3) puts(y<=3?"YES":"NO");
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