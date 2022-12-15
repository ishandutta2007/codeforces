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
        long long n,x,y;
        cin>>n>>x>>y;
        printf("%lld ",min(n,max(1LL,x+y-n+1)));
        printf("%lld\n",min(n,x+y-1));
    }
    return 0;
}