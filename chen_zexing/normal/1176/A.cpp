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
        long long n,cnt=0;
        cin>>n;
        while(n!=1){
            if(n%3&&n%5&&n%2) break;
            if(n%2==0) n/=2;
            else if(n%3==0) n/=3,n*=2;
            else if(n%5==0) n/=5,n*=4;
            cnt++;
        }
        printf("%lld\n",n==1?cnt:-1);
    }
    return 0;
}
//
/// 
//01
//