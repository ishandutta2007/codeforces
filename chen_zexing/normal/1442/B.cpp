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
int a[200005],b[200005],nxt[200005],pre[200005],pos[200005];
unordered_map <int,int> mp;
int main() {
    int T;
    cin>>T;
    while(T--){
        long long ans=1;
        int n,k;
        scanf("%d%d",&n,&k);
        mp.clear();
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),pos[a[i]]=i;
        for(int i=1;i<=n;i++) nxt[i]=i+1,pre[i]=i-1;
        for(int i=1;i<=k;i++) scanf("%d",&b[i]),mp[pos[b[i]]]=1;
        mp[0]=mp[n+1]=1;
        for(int i=1;i<=k;i++){
            mp[pos[b[i]]]=0;
            int c=0,p=pos[b[i]];
            c=2-mp[p+1]-mp[p-1];
            ans=ans*c%998244353;
        }
        printf("%lld\n",ans);
        //cout<<endl;
    }
    return 0;
}