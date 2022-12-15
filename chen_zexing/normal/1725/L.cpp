#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int a[100005],tree[100005];
long long pre[100005],b[100005];
void add(int x,int n){
    while(x<=n) tree[x]++,x+=x&-x;
}
int query(int x){
    int ans=0;
    while(x) ans+=tree[x],x-=x&-x;
    return ans;
}
int main() {
    int T = 1, kase = 0;
    //cin >> T;
    while (T--){
        int n;
        cin>>n;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]),pre[i]=pre[i-1]+a[i],b[i]=pre[i];
        sort(b,b+n);
        if(b[0]<0||b[n-1]>b[n]){
            puts("-1");
            continue;
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            int eq=lower_bound(b,b+n,pre[i])-b+1;
            ans+=query(n)-query(eq);
            add(eq,n);
        }
        printf("%lld\n",ans);
    }
    return 0;
}