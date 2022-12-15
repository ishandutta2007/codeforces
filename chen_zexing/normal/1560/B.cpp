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
    cin >> T;
    while (T--) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        int len=abs(a-b)*2;
        if(c>len||a>len||b>len){
            puts("-1");
        }
        else{
            printf("%d\n",c+len/2<=len?c+len/2:c-len/2);
        }
    }
    return 0;
}
//
/// 
//01
//