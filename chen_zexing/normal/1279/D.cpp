#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
int n;
vector <int> v[1000005];
long long mod=998244353;
long long qpow(long long a,long long b){
    long long ans=1;
    while(b){
        if(b&1) ans=ans*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return ans;
}
int cnt[1000005];
long long pro[1000005];
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        long long ans=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            int k;
            scanf("%d",&k);
            for(int j=1,t;j<=k;j++){
                scanf("%d",&t);
                v[k].push_back(t);
                cnt[t]++;
                pro[t]+=qpow(n,mod-2)*qpow(k,mod-2)%mod,pro[t]%=mod;
            }
        }
        for(int i=1;i<=1000000;i++){
            ans+=pro[i]*cnt[i]%mod*qpow(n,mod-2)%mod;
            ans%=mod;
        }
        cout<<ans<<endl;
    }
    return 0;
}