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
        int n,x;
        cin>>n>>x;
        for(int i=1;i<=40;i++){
            long long tar=n-i*x,now=tar,cnt=0;
            if(tar<0) continue;
            while(now) cnt+=now%2,now/=2;
            if(i>=cnt&&i<=tar){
                cout<<i<<endl;
                exit(0);
            }
        }
        puts("-1");
    }
    return 0;
}
//
/// 
//01
//