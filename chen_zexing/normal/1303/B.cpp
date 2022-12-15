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
int n,g,b;
int main() {
    int T=1;
    cin>>T;
    while(T--) {
        scanf("%d%d%d",&n,&g,&b);
        int tar=(n+1)/2;
        if(tar%g) printf("%lld\n",max(1LL*n,1LL*tar/g*(g+b)+tar%g));
        else printf("%lld\n",max(1LL*n,1LL*(tar/g-1)*(g+b)+g));
    }
    return 0;
}
//
/// 
//01
// 
//
//dp