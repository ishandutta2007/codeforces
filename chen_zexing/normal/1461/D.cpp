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
unordered_map<long long,int> mp;
int a[1000005];
long long pre[1000005];
void cnt(int l,int r){
    if(l==r){
        mp[a[l]]=1;
        return;
    }
    mp[pre[r]-pre[l-1]]=1;
    //cout<<pre[r]-pre[l-1]<<endl;
    int t=(a[l]+a[r])/2;
    if(a[r]>t){
        cnt(l,upper_bound(a+l,a+r,t)-a-1);
        cnt(upper_bound(a+l,a+r,t)-a,r);
    }
    else return;
}
int main() {
    int T;
    cin>>T;
    while(T--){
        mp.clear();
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
        cnt(1,n);
        for(int i=1;i<=m;i++){
            long long t;
            scanf("%lld",&t);
            if(mp[t]) puts("Yes");
            else puts("No");
        }
    }
    return 0;
}