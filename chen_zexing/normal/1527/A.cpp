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
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        scanf("%d",&n);
        int temp=1,pos=0;
        while(temp*2<=n) temp*=2,pos++;
        printf("%d\n",(1<<pos)-1);
    }
    return 0;
}
//
/// 
//01
// 
//
//dp