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
int cnt[105];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        vector <int> v;
        int n;
        cin>>n;
        for(int i=1,t;i<=n;i++){
            scanf("%d",&t),cnt[t]++;
            if(cnt[t]==1) v.push_back(t);
        }
        if(v.size()==1) puts("0");
        else if(v.size()==2){
            if(abs(v[0]-v[1])%2) printf("%d\n",abs(v[0]-v[1]));
            else printf("%d\n",abs(v[0]-v[1])/2);
        }
        else if(v.size()==3){
            sort(v.begin(),v.end());
            if(v[1]-v[0]==v[2]-v[1]) printf("%d\n",v[1]-v[0]);
            else puts("-1");
        }
        else puts("-1");
    }
    return 0;
}
//
/// 
//01
//