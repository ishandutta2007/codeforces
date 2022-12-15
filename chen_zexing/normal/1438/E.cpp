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
#define hash hassh
using namespace std;
int a[200005];
long long ub[200005];
int main() {
    long long ans=0;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        int x=0;
        while(1LL<<x<=a[i]) x++;
        ub[i]=1LL<<x;
    }
    for(int i=1;i<=n-2;i++){
        long long sum=0;
        for(int j=i+1;j<n;j++){
            sum+=a[j];
            if(sum>=ub[i]) break;
            if((a[i]^a[j+1])==sum){
                ans++;
            }
        }
    }
    for(int i=n;i>=3;i--){
        long long sum=0;
        for(int j=i-1;j>1;j--){
            sum+=a[j];
            if(sum>=ub[i]) break;
            if((a[j-1]^a[i])==sum&&ub[j-1]<=sum) ans++;
        }
    }
    printf("%lld\n",ans);
    return 0;
}