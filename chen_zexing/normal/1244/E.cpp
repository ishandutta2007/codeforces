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
long long a[100005],n,k;
long long pre[100005];
int check(long long dif){
    long long mn=1e15;
    for(int i=1;i<=n;i++){
        long long temp=0;
        temp+=1LL*(i-1)*a[i]-pre[i-1];
        int l=i+1,r=n+1;
        a[n+1]=1e10;
        while(l<r){
            int mid=(l+r)>>1;
            if(a[mid]-a[i]<=dif) l=mid+1;
            else r=mid;
        }
        if(l!=n+1) temp+=pre[n]-pre[l-1]-1LL*(n-l+1)*(a[i]+dif);
        if(temp<=k) return 1;
    }
    for(int i=n;i>=1;i--){
        long long temp=0;
        temp+=pre[n]-pre[i]-1LL*(n-i)*a[i];
        int l=0,r=n-1;
        a[0]=-1e10;
        while(l<r){
            int mid=(l+r)>>1;
            mid++;
            if(a[i]-a[mid]<=dif) r=mid-1;
            else l=mid;
        }
        if(l) temp+=1LL*(l)*(a[i]-dif)-pre[l];
        if(temp<=k) return 1;
    }
    return 0;
}
int main() {
    int T=1;
    //cin>>T;
    while(T--) {
        cin>>n>>k;
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
        int l=0,r=1e9;
        while(l<r){
            int mid=(l+r)>>1;
            if(check(mid)) r=mid;
            else l=mid+1;
        }
        printf("%d\n",l);
    }
    return 0;
}