#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
#include <memory.h>
#include <sstream>
#include <ctime>

using namespace std;

long long arr[5005];
vector <long long> v;
vector < vector <int> > g;

int dp[5005];
int cnt[5005];

bool ok(int i,int j) {
    if (arr[j]%arr[i]!=0) return false;
    return (cnt[i]-cnt[j]==i-j||cnt[i]<i-j);
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i) {
        scanf("%I64d",&arr[i]);
        while(arr[i]%2==0) arr[i]/=2,cnt[i]++;
        for(int j=i-1;j>=0;--j) {
            if (ok(i,j))
                dp[i]=max(dp[i],dp[j]);
        }
        ++dp[i];
    }
    int ans=0;
    for(int j=0;j<n;++j)
        ans=max(ans,dp[j]);
    printf("%d\n",n-ans);
    return 0;
}