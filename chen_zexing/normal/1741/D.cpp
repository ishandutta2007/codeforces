#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
int a[300005];
pair<pair<int,int>,int> solve(int l,int r){
    if(l==r) return {{a[l],a[l]},0};
    int mid=(l+r)>>1;
    auto ll=solve(l,mid),rr=solve(mid+1,r);
    if(ll.first.first==-1||rr.first.first==-1) return {{-1,-1},-1};
    if(ll.first.second+1==rr.first.first) return {{ll.first.first,rr.first.second},ll.second+rr.second};
    else if(rr.first.second+1==ll.first.first) return {{rr.first.first,ll.first.second},ll.second+rr.second+1};
    else return {{-1,-1},-1};
}
int main(){
    int T = 1, kase = 0;
    cin >> T;
    while (T--){
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        printf("%d\n",solve(1,n).second);
    }
    return 0;
}