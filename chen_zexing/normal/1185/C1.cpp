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
int a[200005];
int cnt[105];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,m,tot=0,now,ans;
        cin>>n>>m;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++){
            tot+=a[i];
            now=tot,ans=0;
            for(int j=100;j>=1;j--){
                if(now<=m) break;
                if(now-cnt[j]*j<=m){
                    int r=now-m;
                    ans+=r/j+(r%j>0);
                    break;
                }
                else now-=cnt[j]*j,ans+=cnt[j];
            }
            printf("%d ",ans);
            cnt[a[i]]++;
        }
    }
    return 0;
}
//
/// 
//01
//