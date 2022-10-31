#include <bits/stdc++.h>
using namespace std;

int n;
long double x,y;
pair<long double,int> a[200005];
long double tree[600005];
int sz;
long double p=3.14159265358979323846;
long double q[200005];
long double get(int l,int r,int ll,int rr,int x){
    if (l>r || ll>r || l>rr) return 0.0;
    if (l>=ll && r<=rr) return tree[x];
    int mid=(l+r)>>1;
    return max(get(l,mid,ll,rr,x+x),get(mid+1,r,ll,rr,x+x+1));
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i) {
        cin>>x>>y;
        long double z=x*x*y;
        a[i]=make_pair(z,i);
    }
    sort(a+1,a+n+1);
    sz=1;
    while (sz<n) sz+=sz;
    long double ans=0;
    for (int j=1;j<=n;++j) {
        if (j!=n && a[j].first==a[j+1].first) continue;
        else {
        int i=j;
        while (true){
            if (!i || (i<j && a[i].first!=a[i+1].first)) {
                ++i;
                while (i<=j) {
                    int z=a[i].second+sz-1;
                    tree[z]=q[i];
                    z>>=1;
                    while (z) {
                        tree[z]=max(tree[z+z],tree[z+z+1]);
                        z>>=1;
                    }
                    ++i;
                }
                break;
            }
            long double res=a[i].first+get(1,sz,1,a[i].second,1);
            ans=max(ans,res);
            q[i]=res;
            --i;
        }
        }
    }
    ans=ans*p;
    cout<<fixed<<setprecision(10)<<ans;
}