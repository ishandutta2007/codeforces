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
int fa[100005],sz[100005];
int a[100005],b[100005];
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n,cnt=0;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) scanf("%d",&b[i]);
        for(int i=1;i<=n;i++) fa[i]=i,sz[i]=1;
        for(int i=1;i<=n;i++){
            if(a[i]==b[i]) continue;
            int x=find(a[i]),y=find(b[i]);
            if(x!=y) fa[y]=x,sz[x]+=sz[y];
            else cnt+=sz[x]/2;
        }
        long long ans=0;
        for(int i=1;i<=cnt;i++) ans+=n-i*2+1;
        printf("%lld\n",ans*2);
    }
    return 0;
}
//unordered_map