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
int x[200005],y[200005];
int xx[300005],yy[300005];
map <pair<int,int>,int> cntx,cnty;
unordered_map <int,int> totx,toty;
unordered_map <int,int> mpx,mpy;
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        cntx.clear(),cnty.clear(),mpx.clear(),mpy.clear(),totx.clear(),toty.clear();
        for(int i=1;i<=n;i++) scanf("%d",&x[i]),mpx[x[i]]=1;
        for(int i=1;i<=m;i++) scanf("%d",&y[i]),mpy[y[i]]=1;
        long long ans=0;
        for(int i=1,xx,yy;i<=k;i++){
            scanf("%d%d",&xx,&yy);
            if(mpx[xx]&&mpy[yy]) continue;
            if(mpx[xx]){
                int bl=lower_bound(y+1,y+m+1,yy)-y;
                ans+=toty[bl],ans-=cnty[make_pair(bl,xx)];
                cnty[make_pair(bl,xx)]++,toty[bl]++;
            }
            else{
                int bl=lower_bound(x+1,x+n+1,xx)-x;
                ans+=totx[bl],ans-=cntx[make_pair(bl,yy)];
                cntx[make_pair(bl,yy)]++,totx[bl]++;
            }
            //cout<<ans<<endl;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
//
/// 
//01
//