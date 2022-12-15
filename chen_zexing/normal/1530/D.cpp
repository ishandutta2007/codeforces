#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#include <bitset>
#define hash hassh
using namespace std;
int a[200005],b[200005],in[200005],v[200005],from[200005],ans;
void dfs(int x,int st){
    if(v[a[x]]==0) b[x]=a[x],from[a[x]]=x,v[a[x]]=1,dfs(a[x],st),ans++;
    else{
        b[x]=st,from[st]=x,v[st]=1;
        return;
    }
}
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) in[i]=0;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),in[a[i]]++,b[i]=v[i]=0;
        ans=0;
        for(int i=1;i<=n;i++) if(in[i]==0) dfs(i,i);
        for(int i=1;i<=n;i++) if(!b[i]) b[i]=a[i],ans++;
        for(int i=1;i<=n;i++) if(from[i]==i){
                b[i]=a[i],b[from[a[i]]]=i,from[i]=from[a[i]],from[a[i]]=i;
            }
        printf("%d\n",ans);
        for(int i=1;i<=n;i++) printf("%d ",b[i]);
        puts("");
    }
    return 0;
}
//
/// 
//01
// 
//
//dp
//