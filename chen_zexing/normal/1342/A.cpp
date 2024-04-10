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
#define hash hassh
using namespace std;
int main() {
    int T;
    cin>>T;
    while(T--){
        long long a,b,x,y;
        cin>>x>>y>>a>>b;
        printf("%lld\n",min(a*abs(x-y)+b*min(abs(x),abs(y)),a*(abs(x)+abs(y))));
    }
    return 0;
}