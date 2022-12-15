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
        int n,m;
        cin>>n>>m;
        if(m%n){
            puts("-1");
            continue;
        }
        int r=m/n,cnt=0;
        while(r%2==0) cnt++,r/=2;
        while(r%3==0) cnt++,r/=3;
        if(r==1) printf("%d\n",cnt);
        else puts("-1");
    }
    return 0;
}
//
/// 
//01
//