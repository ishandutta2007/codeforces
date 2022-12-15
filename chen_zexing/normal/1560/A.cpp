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
        int cnt=0,now=1;
        while(1){
            if(now%3==0||now%10==3){
                now++;
                continue;
            }
            else{
                cnt++;
            }
            if(cnt==k){
                cout<<now<<endl;
                break;
            }
            else now++;
        }
    }
    return 0;
}
//
/// 
//01
//