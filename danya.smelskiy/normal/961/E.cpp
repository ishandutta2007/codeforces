#include <bits/stdc++.h>
using namespace std;



int n;
int sz;
int a[200005];
vector<int> v[2000005];
long long ans;


long long get(int l,int r,int ll,int rr,int x,int y) {
    if (l>r || ll>r || l>rr || ll>rr) return 0;
    if (l>=ll && r<=rr) {
        int l1=0;
        int r1=v[x].size()-1;
        if (r1<0) return 0;
        while (l1<r1-1) {
            int mid=(l1+r1)>>1;
            if (v[x][mid]>=y) l1=mid;
            else r1=mid;
        }
        if (v[x][r1]>=y) l1=r1;
        if (v[x][l1]>=y) return l1+1;
        else return 0;
    }
    int mid=(l+r)>>1;
    return get(l,mid,ll,rr,x+x,y)+get(mid+1,r,ll,rr,x+x+1,y);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    sz=1;
    while (sz<n) sz+=sz;
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        v[sz+i-1].push_back(a[i]);
    }
    for (int i=sz-1;i>0;--i) {
        vector<int> v1=v[i+i];
        vector<int> v2=v[i+i+1];
        int l=0;
        int r=0;
        while (l<v1.size() || r<v2.size()) {
            if (l==v1.size() || (r<v2.size() && v2[r]>v1[l])) v[i].push_back(v2[r++]);
            else v[i].push_back(v1[l++]);
        }
    }
    for (int i=1;i<=n;++i) {
        ans+=get(1,sz,1,min(a[i],n),1,i);
        if (i<=a[i]) --ans;
    }
    ans/=2;
    cout<<ans;
}