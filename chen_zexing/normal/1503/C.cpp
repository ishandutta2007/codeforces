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
long long dp[100005];
struct node{
    long long a,c,id;
}a[100005];
bool cmp(node a,node b){
    return a.a<b.a;
}
int main() {
    int T=1;
    //cin>>T;
    while(T--) {
        int n;
        cin>>n;
        long long ans=0;
        for(int i=1;i<=n;i++) scanf("%lld%lld",&a[i].a,&a[i].c),ans+=a[i].c;
        sort(a+1,a+n+1,cmp);
        long long mx=min(a[1].a+a[1].c,a[2].a);
        int l=1;
        for(int i=2;i<=n;i++){
            dp[i]=a[i].a-mx;
            mx=max(mx,min(a[i].a+a[i].c,a[i+1].a)-dp[i]);
            //cout<<"#"<<" "<<mx<<endl;
            while(a[l].a+a[l].c<=a[i+1].a&&l<=i) mx=max(mx,a[l].a+a[l].c-dp[l]),l++;
            if(l<=i) mx=max(mx,a[i+1].a-dp[l]);
            //cout<<dp[i]<<" "<<mx<<endl;
        }
        cout<<ans+dp[n]<<endl;
    }
   return 0;
}
//
/// 
//01
// 
//
//dp