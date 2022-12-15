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
using namespace std;
struct node{
    int x,w,id;
    friend bool operator <(node a,node b){
        return a.w<b.w;
    }
}a[200005];
bool cmp(node a,node b){
    return a.x<b.x;
}
int main() {
    int T = 1;
    cin >> T;
    while (T--) {
        int k,n;
        long long ans=0;
        scanf("%d%d",&k,&n);
        for(int i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].w),a[i].id=i;
        sort(a+1,a+n+1);
        for(int i=1;i<=k*2;i++) ans+=a[i].w;
        printf("%lld\n",ans);
        sort(a+1,a+k*2+1,cmp);
        for(int i=1;i<=k;i++) printf("%d %d\n",a[i].id,a[k*2+1-i].id);
        puts("");
    }
    return 0;
}
//unordered_map