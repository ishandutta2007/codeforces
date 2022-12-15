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
int fa[400005],a[400005][2],pos[400005][2];
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) fa[i]=i;
        for(int i=1;i<=n;i++) scanf("%d",&a[i][0]),pos[a[i][0]][0]=i;
        for(int i=1;i<=n;i++) scanf("%d",&a[i][1]),pos[a[i][1]][1]=i;
        for(int i=1;i<=n;i++){
            int x,y;
            x=find(i),y=find(pos[a[i][0]][1]);
            if(x!=y) fa[y]=x;
            y=find(pos[a[i][1]][0]);
            if(x!=y) fa[y]=x;
        }
        long long ans=1,mod=1000000007;
        for(int i=1;i<=n;i++) if(fa[i]==i) ans=ans*2%mod;
        printf("%lld\n",ans);
    }
    return 0;
}
//
/// 
//01
// 
//
//dp