#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
#include <stdlib.h>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#include <bitset>
#include <list>
#define hash hassh
#define li __int128_t
#define ull unsigned long long
using namespace std;
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        long long a,b,x;
        int f=0;
        scanf("%lld%lld%lld",&a,&b,&x);
        if(x>max(a,b)){
            puts("NO");
            continue;
        }
        if(a<b) swap(a,b);
        while(a%b){
            if(a%b==x%b&&x<=a) f=1;
            long long temp=a%b;
            a=b,b=temp;
        }
        if(a%b==x%b&&x<=a) f=1;
        if(f) puts("YES");
        else puts("NO");
    }
    return 0;
}
//
/// 
//01
//