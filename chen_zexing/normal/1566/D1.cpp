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
int a[305];
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n,m,ans=0;
        cin>>n>>m;
        for(int i=1;i<=m;i++){
            scanf("%d",&a[i]);
            for(int j=1;j<i;j++) if(a[j]<a[i]) ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
//
/// 
//01
//