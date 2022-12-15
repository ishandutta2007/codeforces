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
using namespace std;
int n,k,m[500005],b[500005],a[500005],mn[500005];
int main() {
    cin>>n>>k;
    for(int i=1;i<=n;i++) scanf("%d",&m[i]);
    for(int i=1;i<=k;i++) scanf("%d",&b[i]);
    for(int i=1;i<=n;i++) a[i]=m[i]-i;
    int f=1;
    for(int i=2;i<=k;i++) if(a[b[i]]<a[b[i-1]]) f=0;
    if(!f){
        puts("-1");
        return 0;
    }
    b[0]=0,b[k+1]=n+1;
    a[0]=INT_MIN,a[n+1]=INT_MAX;
    int ans=0;
    for(int i=1;i<=k+1;i++){
        for(int j=1;j<=b[i]-b[i-1]-1;j++) mn[j]=INT_MAX;
        mn[0]=0;
        int cnt=0;
        for(int j=b[i-1]+1;j<b[i];j++){
            if(a[j]<a[b[i-1]]) continue;
            int l=0,r=cnt;
            while(l<r){
                int mid=(l+r)/2+1;
                if(mn[mid]<=a[j]) l=mid;
                else r=mid-1;
            }
            mn[l+1]=min(mn[l+1],a[j]);
            if(l==cnt&&a[j]<=a[b[i]]) cnt++;
        }
        ans+=b[i]-b[i-1]-1-cnt;
        //cout<<ans<<endl;
    }
    printf("%d\n",ans);
    return 0;
}