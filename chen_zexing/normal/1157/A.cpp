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
unordered_map <int,int> mp;
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,cnt=1;
        cin>>n;
        mp[n]=1;
        while(1){
            n++;
            while(n%10==0) n/=10;
            if(mp[n]){
                printf("%d\n",cnt);
                exit(0);
            }
            mp[n]=1,cnt++;
        }
    }
    return 0;
}
//
/// 
//01
//