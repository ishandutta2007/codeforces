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
        int a,b;
        scanf("%d%d",&a,&b);
        if(a==b){
            puts("0");
            continue;
        }
        if(a>b&&(a-b)%2==0||a<b&&(b-a)%2) puts("1");
        else puts("2");
    }
    return 0;
}
//
/// 
//01
// 