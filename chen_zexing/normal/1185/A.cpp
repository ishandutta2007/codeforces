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
#define hash hassh
#define li __int128_t
#define ull unsigned long long
using namespace std;
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        long long a,b,c,d;
        cin>>a>>b>>c>>d;
        if(a>b) swap(a,b);
        if(a>c) swap(a,c);
        if(b>c) swap(b,c);
        printf("%lld\n",max(d-b+a,0LL)+max(d-c+b,0LL));
    }
    return 0;
}
//
/// 
//01
//