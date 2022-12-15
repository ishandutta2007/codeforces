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
        int x,now=1;
        cin>>x;
        while(now<=x) now*=2;
        int tar=now-1;
        now/=2;
        if(x==tar){
            puts("0");
            continue;
        }
        vector <int> ans;
        int cnt=0;
        now/=2;
        while(now){
            if(x==tar) break;
            while(x&now) now/=2;
            cnt++,ans.push_back(log2(now*2)),x^=(now*2-1);;
            if(x==tar) break;
            now/=2,x++,cnt++;
        }
        printf("%d\n",cnt);
        for(auto t:ans) printf("%d ",t);
        puts("");
    }
    return 0;
}
//
/// 
//01
//