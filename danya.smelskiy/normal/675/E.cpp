#include <bits/stdc++.h>
using namespace std;

int n;
int a[100005];
int tree[500005];
long long dp[100005];
long long ans;
int sz;

int get(int l,int r,int ll,int rr,int x){
    if (l>r || ll>r || l>rr) return 0;
    if (l>=ll && r<=rr) return tree[x];
    int mid=(l+r)>>1;
    int res1=get(l,mid,ll,rr,x+x);
    int res2=get(mid+1,r,ll,rr,x+x+1);
    return (a[res1]>a[res2] ? res1 : res2);
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<n;++i) {
        cin>>a[i];
    }
    a[n]=n;
    sz=1;
    while (sz<n) sz+=sz;
    for (int i=1;i<=n;++i)
        tree[sz+i-1]=i;
    for (int i=sz-1;i>0;--i) {
        tree[i]= (a[tree[i+i]]>a[tree[i+i+1]] ? tree[i+i] : tree[i+i+1]);
    }
    for (int i=n-1;i>0;--i) {
        int res=get(1,sz,i+1,a[i],1);
        dp[i]=dp[res]-(a[i]-res)+n-i;
        ans+=dp[i];
    }
    cout<<ans;
}