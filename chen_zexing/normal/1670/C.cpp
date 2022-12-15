#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <climits>
#include <algorithm>
#include <complex>
#include <string.h>
#include <iomanip>
#include <assert.h>
#include <random>
using namespace std;
int a[100005],b[100005],c[100005];
int fa[100005],sz[100005],f[100005];
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n;
        long long ans=1,mod=1e9+7;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),fa[i]=i,sz[i]=1,f[i]=0;
        for(int i=1;i<=n;i++) scanf("%d",&b[i]);
        for(int i=1;i<=n;i++) scanf("%d",&c[i]);
        for(int i=1;i<=n;i++){
            int x=find(a[i]),y=find(b[i]);
            if(x!=y) fa[y]=x,sz[x]+=sz[y];
        }
        for(int i=1;i<=n;i++) if(c[i]) f[find(a[i])]=1;
        for(int i=1;i<=n;i++) if(fa[i]==i&&sz[i]>1&&f[i]==0) ans=ans*2%mod;
        printf("%lld\n",ans);
    }
    return 0;
}
//unordered_map