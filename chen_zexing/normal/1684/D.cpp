#pragma GCC optimize("Ofast,unroll-loops")
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
int a[200005],eq[200005],id[200005],f[200005];
bool cmp(int a,int b){
    return eq[a]<eq[b];
}
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        int n,k;
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),id[i]=i,eq[i]=a[i]-(n-i+1),f[i]=0;
        sort(id+1,id+n+1,cmp);
        for(int i=n-k+1;i<=n;i++) f[id[i]]=1;
        long long ans=0,cnt=0;
        for(int i=1;i<=n;i++){
            if(!f[i]) ans+=cnt+a[i];
            else cnt++;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
//unordered_map
//cf