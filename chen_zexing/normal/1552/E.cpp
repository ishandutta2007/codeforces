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
int a[10005],f[105],vis[105];
struct answer{
    int l,r;
}ans[105];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,k,tot=0;
        cin>>n>>k;
        for(int i=1;i<=n*k;i++) scanf("%d",&a[i]);
        for(int i=1;i<=ceil(double(n)/(k-1));i++){
            int now=1;
            for(int j=1;j<=min(k-1,n-tot);j++){
                for(int t=1;t<=n;t++) f[t]=0;
                for(int t=now;t<=n*k;t++){
                    if(f[a[t]]&&vis[a[t]]==0){
                        ans[a[t]].l=f[a[t]],ans[a[t]].r=t;
                        now=t+1,vis[a[t]]=1;
                        break;
                    }
                    f[a[t]]=t;
                }
            }
            tot+=k-1;
        }
        for(int i=1;i<=n;i++) printf("%d %d\n",ans[i].l,ans[i].r);
    }
    return 0;
}
//
/// 
//01
// 
//
//dp
//