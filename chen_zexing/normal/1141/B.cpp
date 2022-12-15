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
int a[400005];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,ans=0,cnt=0;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),a[n+i]=a[i];
        for(int i=1;i<=n*2+1;i++){
            if(i==n*2+1) ans=max(ans,cnt);
            else{
                if(a[i]==0) ans=max(ans,cnt),cnt=0;
                else cnt++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
//
/// 
//01
//