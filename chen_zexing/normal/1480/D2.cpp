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
int a[100005],b[100005],ans[100005],now[100005],pre[100005];
int dfs(int x){
    if(ans[x]!=-1) return ans[x];
    if(x==0) return 0;
    ans[x]=dfs(x-1);
    if(pre[x]) ans[x]=max(ans[x],dfs(pre[x]+1)+1);
    return ans[x];
}
int main() {
    int T=1;
    //cin>>T;
    while(T--){
        int n,x=0;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) if(a[i]!=a[i-1]) b[++x]=a[i];
        for(int i=1;i<=x;i++) pre[i]=now[b[i]],now[b[i]]=i;
        memset(ans,-1,sizeof(ans));
        dfs(x);
        int mx=0;
        for(int i=1;i<=x;i++) mx=max(mx,ans[i]);
        cout<<x-mx<<endl;
    }
    return 0;
}