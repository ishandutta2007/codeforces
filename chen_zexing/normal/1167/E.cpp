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
int a[1000005];
int fst[1000005],lst[1000005];
int pre[1000005],suf[1000005];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n,x;
        cin>>n>>x;
        long long ans=0;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),lst[a[i]]=i;
        for(int i=n;i>=1;i--) fst[a[i]]=i;
        memset(pre,-1,sizeof(pre));
        memset(suf,-1,sizeof(suf));
        pre[0]=0;
        for(int i=1;i<=x;i++){
            if(fst[i]==0){
                pre[i]=pre[i-1];
                continue;
            }
            if(fst[i]<pre[i-1]) break;
            pre[i]=lst[i];
        }
        suf[x+1]=n+1;
        for(int i=x;i>=1;i--){
            if(lst[i]==0){
                suf[i]=suf[i+1];
                continue;
            }
            if(lst[i]>suf[i+1]) break;
            suf[i]=fst[i];
        }
        int r=1;
        for(int i=1;i<=x;i++){
            if(pre[i-1]==-1) break;
            while(r<=x&&(suf[r+1]==-1||suf[r+1]<pre[i-1])) r++;
            if(r>x) break;
            ans+=x-r+1;
            r=max(r,i+1);
        }
        printf("%lld\n",ans);
    }
    return 0;
}
//
/// 
//01
//