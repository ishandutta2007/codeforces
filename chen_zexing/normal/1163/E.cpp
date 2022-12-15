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
#include <list>
#define hash hassh
#define li __int128_t
#define ull unsigned long long
using namespace std;
int bi[20],b[20];
int ans[400005];
void solve(int l,int r,int sz,int dir){
    if(sz==0){
        ans[l]=0;
        return;
    }
    if(dir==1){
        int mid=(l+r)>>1;
        solve(l,mid,sz-1,1),solve(mid+1,r,sz-1,-1);
        for(int i=mid+1;i<=r;i++) ans[i]^=bi[sz-1];
    }
    else{
        int mid=(l+r)>>1;
        solve(l,mid,sz-1,1),solve(mid+1,r,sz-1,-1);
        for(int i=l;i<=mid;i++) ans[i]^=bi[sz-1];
    }
    //cout<<l<<" "<<r<<endl;
    //for(int i=l;i<=r;i++) cout<<ans[i]<<" ";puts("");
}
int a[200005];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int tt=17;tt>=0;tt--) {
            memset(b,0,sizeof(b));
            memset(bi,0,sizeof(bi));
            for (int i = 1, x; i <= n; i++) {
                x=a[i];
                if(x>=(1<<(tt+1))) continue;
                int o = x;
                for (int j = 18; j >= 0; j--) {
                    if (x < (1 << j)) continue;
                    if (((1 << j) & x) && !bi[j]) {
                        bi[j] = o, b[j] = x;
                        break;
                    }
                    x ^= b[j];
                }
            }
            int pos;
            for (int i = 0; i <= 18; i++)
                if (!bi[i] || i == 18) {
                    pos = i;
                    break;
                }
            pos--;
            if(pos!=tt) continue;
            solve(0, (1 << (pos + 1)) - 1, pos + 1, 1);
            printf("%d\n", pos + 1);
            for (int i = 0; i < (1 << pos + 1); i++) printf("%d ", ans[i]);
            exit(0);
        }
        puts("0");
        puts("0");
    }
    return 0;
}
//
/// 
//01
//