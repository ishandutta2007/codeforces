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
int a[55];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,h,m;
        cin>>n>>h>>m;
        for(int i=1;i<=n;i++) a[i]=h;
        for(int i=1,l,r,x;i<=m;i++){
            cin>>l>>r>>x;
            for(int j=l;j<=r;j++) a[j]=min(a[j],x);
        }
        int ans=0;
        for(int i=1;i<=n;i++) ans+=a[i]*a[i];
        cout<<ans<<endl;
    }
    return 0;
}
//
/// 
//01
//