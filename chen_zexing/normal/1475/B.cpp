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
        int n;
        scanf("%d",&n);
        int t=n/2020;
        if(n%2020<=t) puts("YES");
        else puts("NO");
    }
    return 0;
}