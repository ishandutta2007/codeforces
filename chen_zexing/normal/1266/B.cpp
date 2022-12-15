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
        long long n;
        cin>>n;
        if(n<15){
            puts("NO");
            continue;
        }
        int t=n%14;
        t+=14;
        if(t>=15&&t<=20) puts("YES");
        else puts("NO");
    }
    return 0;
}