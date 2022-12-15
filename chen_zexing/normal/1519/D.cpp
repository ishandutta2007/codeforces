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
long long ans;
int a[5005],b[5005];
int main() {
    int T = 1;
    //cin >> T;
    while (T--) {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) scanf("%d",&b[i]),ans+=1LL*a[i]*b[i];
        long long temp=ans,o=ans;
        for(int i=1;i<=n;i++) {
            temp=o;
            for (int j = 1; j <=min(n-i,i-1); j++) {
                temp-=1LL*a[i-j]*b[i-j],temp-=1LL*a[i+j]*b[i+j];
                temp+=1LL*a[i-j]*b[i+j],temp+=1LL*a[i+j]*b[i-j];
                ans=max(ans,temp);
            }
        }
        for(int i=1;i<n;i++){
            temp=o;
            temp-=1LL*a[i]*b[i],temp-=1LL*a[i+1]*b[i+1];
            temp+=1LL*a[i]*b[i+1],temp+=1LL*a[i+1]*b[i];
            ans=max(ans,temp);
            for(int j=1;j<=min(i-1,n-i-1);j++){
                temp-=1LL*a[i-j]*b[i-j],temp-=1LL*a[i+j+1]*b[i+j+1];
                temp+=1LL*a[i-j]*b[i+j+1],temp+=1LL*a[i+j+1]*b[i-j];
                ans=max(ans,temp);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
//
/// 
//01
// 
//
//dp