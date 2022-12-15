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
    while(T--){
        int a[3];
        cin>>a[0]>>a[1]>>a[2];
        sort(a,a+3);
        if(a[0]+a[1]>=a[2]-1) puts("Yes");
        else puts("No");
    }
    return 0;
}