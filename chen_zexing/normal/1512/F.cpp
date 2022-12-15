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
long long a[200005],b[200005];
int main() {
    int T=1;
    cin>>T;
    while(T--){
        int n,c;
        cin>>n>>c;
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        for(int i=1;i<n;i++) scanf("%lld",&b[i]);
        long long ans=INT_MAX,temp=0,tot=0;
        for(int i=1;i<=n;i++){
            if(c<=tot) ans=min(ans,temp);
            else ans=min(ans,temp+(c-tot)/a[i]+((c-tot)%a[i]>0));
            if(i==n) continue;
            if(b[i]<=tot) tot-=b[i],temp++;
            else{
                long long d=(b[i]-tot)/a[i]+((b[i]-tot)%a[i]>0);
                temp+=d+1;
                tot+=d*a[i],tot-=b[i];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
//
/// 
//01
// 
//
//dp