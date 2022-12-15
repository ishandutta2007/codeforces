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
        int n,k,ans=0;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>l[i]>>r[i];
        cin>>k;
        for(int i=1;i<=n;i++) if(r[i]>=k) ans++;
        cout<<ans<<endl;
    }
    return 0;
}
//
/// 
//01
//