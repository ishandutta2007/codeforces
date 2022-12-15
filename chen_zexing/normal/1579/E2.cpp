#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <cmath>
#include <assert.h>
#include <algorithm>
#include <stdlib.h>
#include <queue>
#include <climits>
#include <set>
#include <unordered_map>
#include <time.h>
#include <map>
#include <stack>
#include <unordered_set>
#include <bitset>
#include <list>
#define hash hassh
#define li __int128_t
#define ull unsigned long long
using namespace std;
int tree[200005],b[200005],a[200005],n;
void update(int x){
    while(x<=n) tree[x]++,x+=x&-x;
}
int query(int x){
    int ans=0;
    while(x) ans+=tree[x],x-=x&-x;
    return ans;
}
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),b[i]=a[i],tree[i]=0;
        sort(b+1,b+n+1);
        for(int i=1;i<=n;i++) a[i]=lower_bound(b+1,b+n+1,a[i])-b;
        long long ans=0;
        for(int i=1;i<=n;i++) ans+=min(query(a[i]-1),query(n)-query(a[i])),update(a[i]);
        printf("%lld\n",ans);
    }
    return 0;
}
//
/// 
//01
//