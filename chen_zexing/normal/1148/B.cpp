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
long long a[200005],b[200005],ta,tb,k;
struct flight{
    long long t,type;
}f[400005];
bool cmp(flight a,flight b){
    return a.t<b.t||a.t==b.t&&a.type<b.type;
}
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        int n,m;
        cin>>n>>m>>ta>>tb>>k;
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]),a[i]+=ta,f[i]=flight{a[i],1};
        for(int i=1;i<=m;i++) scanf("%lld",&b[i]),f[i+n]=flight{b[i],2};
        b[m+1]=LLONG_MAX;
        long long ans=0;
        if(k>=n||k>=m){
            puts("-1");
            return 0;
        }
        for(int i=1;i<=min((long long)(n),k+1);i++){
            int l=1,r=m+1;
            while(l<r){
                int mid=(l+r)>>1;
                if(b[mid]>=a[i]) r=mid;
                else l=mid+1;
            }
            if(l+k-i+1>m){
                ans=-1;
                break;
            }
            ans=max(ans,b[l+k-i+1]+tb);
        }
        cout<<ans<<endl;
    }
    return 0;
}