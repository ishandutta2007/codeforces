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
long long mod=1000000007;
long long zero[200005],ans[200005],pre[200005];
int b[200005];
unordered_map<long long ,long long> mp;
int main() {
    int T=1;
    cin>>T;
    while(T--) {
        int n;
        cin>>n;
        mp.clear();
        for(int i=1;i<=n;i++) scanf("%d",&b[i]),pre[i]=pre[i-1]+b[i];
        ans[0]=1;
        ans[1]=1,zero[1]=(b[1]==0);
        mp[0]=1;
        mp[b[1]]=2;
        for(int i=2;i<=n;i++){
            ans[i]=ans[i-1]*2-zero[i-1];
            ans[i]%=mod;
            zero[i]=ans[mp[pre[i]]-1];
            mp[pre[i]]=i+1;
            //cout<<ans[i]<<" "<<zero[i]<<" ";
        }
        printf("%lld\n",(ans[n]+mod)%mod);
    }
    return 0;
}