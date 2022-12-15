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
int l[105],r[105];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,k;
        cin>>n>>k;
        if(k==1||k==n){
            printf("%d\n",n*3);
        }
        else{
            if(k>n/2) k=n-k+1;
            printf("%d\n",n*3+k-1);
        }
    }
    return 0;
}
//
/// 
//01
//