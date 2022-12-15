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
#define li __int128_t
using namespace std;
int a[105];
int main() {
    int T = 1;
    cin >> T;
    while (T--){
        int n,ans=0;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=30;i>=0;i--){
            int fl=1;
            for(int j=1;j<=n;j++) if(((1<<i)&a[j])==0) fl=0;
            if(fl) ans+=1<<i;
        }
        cout<<ans<<endl;
    }
    return 0;
}
//
/// 
//01
//
//!