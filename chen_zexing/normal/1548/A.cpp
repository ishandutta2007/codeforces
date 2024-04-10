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
int cnt[200005],ans;
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,m;
        cin>>n>>m;
        ans=n;
        for(int i=1,x,y;i<=m;i++){
            scanf("%d%d",&x,&y);
            cnt[min(x,y)]++;
            if(cnt[min(x,y)]==1) ans--;
        }
        int q;
        cin>>q;
        while(q--){
            int t,x,y;
            scanf("%d",&t);
            if(t==1){
                scanf("%d%d",&x,&y);
                cnt[min(x,y)]++;
                if(cnt[min(x,y)]==1) ans--;
            }
            else if(t==2){
                scanf("%d%d",&x,&y);
                cnt[min(x,y)]--;
                if(cnt[min(x,y)]==0) ans++;
            }
            else printf("%d\n",ans);
        }
    }
    return 0;
}
//
/// 
//01
// 
//
//dp
//!