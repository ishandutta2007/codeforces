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
        long long n;
        scanf("%lld",&n);
        int f=0;
        while(n>1){
            if(n%2){
                f=1;
                break;
            }
            else n/=2;
        }
        if(f) puts("YES");
        else puts("NO");
    }
    return 0;
}