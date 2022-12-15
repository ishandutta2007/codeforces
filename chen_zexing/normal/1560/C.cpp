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
        int k;
        cin>>k;
        int s=sqrt(k);
        if(s*s!=k) s++;
        int nd=k-(s-1)*(s-1);
        if(nd<=s){
            printf("%d %d\n",nd,s);
        }
        else{
            printf("%d %d\n",s,s-(nd-s));
        }
    }
    return 0;
}
//
/// 
//01
//