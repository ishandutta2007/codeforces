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
long long mod=998244353;
int l[55],r[55],ll[55],rr[55];
long long cnt[100005],pre[100005],ans[100005];
long long solve(int n,int m,int g){
    int mx=m/g;
    for(int i=1;i<=n;i++){
        ll[i]=l[i]/g,rr[i]=r[i]/g;
        if(ll[i]*g<l[i]) ll[i]++;
        if(ll[i]>rr[i]) return 0;
    }
    for(int i=0;i<=mx;i++) pre[i]=0;
    for(int i=ll[1];i<=rr[1];i++) pre[i]=i-ll[1]+1;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=mx;j++){
            int mxp=j-ll[i],mnp=j-rr[i];
            cnt[j]=pre[min(mxp,mx)]-pre[max(mnp-1,0)],cnt[j]%=mod;
            //cout<<g<<" "<<i<<" "<<j<<" "<<mxp<<" "<<mnp<<" "<<cnt[j]<<endl;
        }
        for(int j=1;j<=mx;j++) pre[j]=(pre[j-1]+cnt[j])%mod;
    }
    return pre[mx];
}
int main() {
    int T = 1;
    //cin >> T;
    while (T--){
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++) scanf("%d%d",&l[i],&r[i]);
        for(int i=m;i>=1;i--){
            long long temp=solve(n,m,i);
            for(int j=i*2;j<=m;j+=i) temp-=ans[j],temp%=mod;
            ans[i]=temp;
        }
        cout<<(ans[1]+mod)%mod<<endl;
    }
    return 0;
}
//
/// 
//01
//
//!