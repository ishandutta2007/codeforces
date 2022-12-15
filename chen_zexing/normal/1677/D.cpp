#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
#include <complex>
#include <string.h>
#include <iomanip>
#include <assert.h>
#include <random>
using namespace std;
int a[1000005];
long long mod=998244353;
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n,k;
        cin>>n>>k;
        long long ans=1;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            if(a[i]==-1){
                if(i<=n-k) ans*=i+k,ans%=mod;
            }
            else if(a[i]==0){
                if(i<=n-k) ans*=k+1,ans%=mod;
            }
            else{
                if(i<=n-k&&a[i]>=i||i>n-k) ans=0;
            }
            //cout<<ans<<endl;
        }
        for(int i=1;i<=k;i++) ans=ans*i%mod;
        printf("%lld\n",ans);
    }
    return 0;
}
//unordered_map