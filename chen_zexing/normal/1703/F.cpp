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
int a[200005],tree[200005];
void add(int x,int n){
    while(x<=n) tree[x]++,x+=x&-x;
}
int query(int x){
    if(x<0) return 0;
    int ans=0;
    while(x) ans+=tree[x],x-=x&-x;
    return ans;
}
int main() {
    int T = 1, kase = 0;
    cin >> T;
    while (T--) {
        long long ans=0;
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),tree[i]=0;
        for(int i=1;i<=n;i++){
            if(a[i]<i){
                ans+=query(min(n,a[i]-1));
                add(i,n);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
//unordered_map
//cf