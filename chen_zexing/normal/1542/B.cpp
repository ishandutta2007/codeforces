#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
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
using namespace std;
int cnt[5];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        long long n,a,b;
        scanf("%lld%lld%lld",&n,&a,&b);
        vector <long long> v;
        v.push_back(1);
        long long now=1;
        if(a>1){
            now*=a;
            while(now<=n) v.push_back(now),now*=a;
        }
        int f=0;
        for(int i=0;i<v.size();i++)
            if((n-v[i])%b==0)
                f=1;
        puts(f?"YES":"NO");
    }
    return 0;
}
//
/// 
//01
// 
//
//dp
//