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
int a[200005],cnt[105],f[200005],pre[200005];
unordered_map <int,int> mp;
int main() {
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),cnt[a[i]]++;
    int mx=0,t=0,p=0,ans=0;
    for(int i=1;i<=100;i++) mx=max(mx,cnt[i]);
    for(int i=1;i<=100;i++) if(cnt[i]==mx) t++,p=i;
    if(t>1){
        printf("%d\n",n);
        return 0;
    }
    for(int i=1;i<=100;i++){
        if(i==p) continue;
        for(int j=1;j<=n;j++){
            if(a[j]==p) f[j]=1;
            else if(a[j]==i) f[j]=-1;
            else f[j]=0;
        }
        for(int j=1;j<=n;j++) pre[j]=pre[j-1]+f[j];
        mp.clear();
        mp[0]=1;
        mx=0;
        for(int j=1;j<=n;j++) {
            if (mp[pre[j]]) mx=max(mx,j-mp[pre[j]]+1);
            else mp[pre[j]]=j+1;
        }
        ans=max(ans,mx);
    }
    printf("%d\n",ans);
    return 0;
}