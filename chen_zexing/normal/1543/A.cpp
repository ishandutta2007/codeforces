#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#include <bitset>
#define hash hassh
using namespace std;
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        long long a,b;
        scanf("%lld%lld",&a,&b);
        if(a>b) swap(a,b);
        if(a==b){
            puts("0 0");
            continue;
        }
        if(a==0){
            printf("%lld 0\n",b);
            continue;
        }
        if(a*2<=b){
            printf("%lld %lld\n",b-a,min(b-a*2,a));
        }
        else{
            long long nd=a/(b-a)+(a%(b-a)>0);
            nd*=(b-a);
            printf("%lld %lld\n",b-a,min(nd-a,a-(nd-(b-a))));
        }
    }
    return 0;
}
//
/// 
//01
// 
//
//dp
//