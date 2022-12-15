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
int cnt[105];
long long a[500005],mod=1000000007,ans;
int main() {
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        for(int i=0;i<60;i++) cnt[i]=0;
        for(int i=0;i<60;i++)
            for(int j=1;j<=n;j++)
                cnt[i]+=((1LL<<i)&a[j])>0;
        //for(int i=0;i<60;i++) printf("%d\n",cnt[i]);
        ans=0;
        for(int i=1;i<=n;i++){
            long long c1=0,c2=0;
            for(int j=0;j<60;j++){
                if(((1LL<<j)&a[i])!=0) c1+=(1LL<<j)%mod*n%mod,c1%=mod;
                else c1+=(1LL<<j)%mod*cnt[j]%mod,c1%=mod;
                c2+=(1LL<<j)%mod*cnt[j]%mod;
                if(((1LL<<j)&a[i])==0) c2-=(1LL<<j)%mod*cnt[j]%mod;
                c2%=mod;
            }
            //cout<<c1<<" "<<c2<<endl;
            ans+=c1*c2%mod,ans%=mod;
        }
        cout<<(ans+mod)%mod<<endl;
    }
    return 0;
}