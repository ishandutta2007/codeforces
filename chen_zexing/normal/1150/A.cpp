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
        int n,m,r,mn=INT_MAX,mx=0,t;
        cin>>n>>m>>r;
        for(int i=1;i<=n;i++) cin>>t,mn=min(mn,t);
        for(int i=1;i<=m;i++) cin>>t,mx=max(mx,t);
        cout<<r+(r/mn*max(mx-mn,0))<<endl;
    }
    return 0;
}
//
/// 
//01
//