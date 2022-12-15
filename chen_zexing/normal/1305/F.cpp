#include <stdio.h>
#include<iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <algorithm>
#include <queue>
#include <climits>
#include <stdlib.h>
#include <set>
#include <unordered_map>
#include <map>
#include <stack>
#include <unordered_set>
#define hash hassh
using namespace std;
vector <long long> fac;
long long a[200005],n;
int main() {
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
    int ans=n;
    fac.push_back(2);
    fac.push_back(3);
    for(int i=1;i<=30;i++)
    {
        int t=1LL*rand()*rand()%n+1;
        long long k=a[t];
        //cout<<a[t]<<endl;
        for(int j=2;1LL*j*j<=k;j++)
            if(k%j==0){
                fac.push_back(j);
                fac.push_back(k/j);
                while(k%j==0) k/=j;
            }
        if(k>1) fac.push_back(k);
        k=a[t]+1;
        //cout<<a[t]<<endl;
        for(int j=2;1LL*j*j<=k;j++)
            if(k%j==0){
                fac.push_back(j);
                fac.push_back(k/j);
                while(k%j==0) k/=j;
            }
        if(k>1) fac.push_back(k);
        k=a[t]-1;
        //cout<<a[t]<<endl;
        for(int j=2;1LL*j*j<=k;j++)
            if(k%j==0){
                fac.push_back(j);
                fac.push_back(k/j);
                while(k%j==0) k/=j;
            }
        if(k>1) fac.push_back(k);
    }
    for(int i=0;i<fac.size();i++)
        if(fac[i]){
            long long cnt=0;
            for(int j=1;j<=n;j++)
                cnt+=a[j]>=fac[i]?min(a[j]%fac[i],(fac[i]-a[j]%fac[i])):fac[i]-a[j]%fac[i];
            if(cnt>ans) continue;
            ans=min(ans,int(cnt));
            //cout<<fac[i]<<" "<<cnt<<endl;
        }

    cout<<ans<<endl;
    return 0;
}