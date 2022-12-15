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
long long a[1000005];
int main() {
    long long sum=0;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) scanf("%lld",&a[i]),a[i]+=a[i-1];
    sum=a[n];
    if(sum<=1){
        puts("-1");
        return 0;
    }
    long long ans=LLONG_MAX;
    for(int i=2;1LL*i*i<=sum;i++){
        if(sum%i==0){
            while(sum%i==0) sum/=i;
            long long temp=0;
            for(int j=1;j<=n;j++) temp+=min(a[j]%i,i-a[j]%i);
            ans=min(ans,temp);
        }
    }
    if(sum>1){
        long long temp=0;
        for(int j=1;j<=n;j++) temp+=min(a[j]%sum,sum-a[j]%sum);
        ans=min(ans,temp);
    }
    cout<<ans<<endl;
    return 0;
}