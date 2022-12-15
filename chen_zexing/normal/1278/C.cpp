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
int n,a[200005];
int pre[200005],suf[200005];
unordered_map <int,int>mp;
int main() {
    int T;
    cin>>T;
    while(T--){
        cin>>n;
        for(int i=1;i<=n*2;i++) scanf("%d",&a[i]);
        mp.clear();
        mp[0]=0;
        for(int i=1;i<=n;i++) pre[i]=pre[i-1]+(a[i]==1?1:-1);
        suf[n*2+1]=0;
        for(int i=n*2;i>=n+1;i--) suf[i]=suf[i+1]+(a[i]==1?-1:1);
        int ans=0;
        for(int i=1;i<=n;i++) mp[pre[i]]=i;
        for(int i=n*2+1;i>=n+1;i--){
            if(suf[i]==0) ans=max(ans,mp[suf[i]]+n*2-i+1);
            else if(mp[suf[i]]) ans=max(ans,mp[suf[i]]+n*2-i+1);
        }
        cout<<n*2-ans<<endl;
    }
    return 0;
}