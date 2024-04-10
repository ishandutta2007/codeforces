#include <bits/stdc++.h>
using namespace std;


int n;
int sz;
int a[500005];
int t[3000005];
int m;
int cnt;


void f(int l,int r,int ll,int rr,int x,int y) {
    if (l>r || ll>r || l>rr || ll>rr || cnt>=2)  return;
    if (l>=ll && r<=rr && t[x]%y==0) return;
    if (l==r) {
        ++cnt;
        return;
    }
    int mid=(l+r)>>1;
    f(l,mid,ll,rr,x+x,y);
    f(mid+1,r,ll,rr,x+x+1,y);
}

inline void update(int x,int y) {
    x+=sz-1;
    t[x]=y;
    x>>=1;
    while (x) {
        t[x]=__gcd(t[x+x],t[x+x+1]);
        x>>=1;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    sz=1;
    while (sz<n) sz+=sz;
    for (int i=1;i<=n;++i)
        t[sz+i-1]=a[i];
    for (int i=sz-1;i>0;--i)
        t[i]=__gcd(t[i+i],t[i+i+1]);
    cin>>m;
    int tp,x,y,z;
    while (m--) {
        cin>>tp;
        if (tp==1) {
            cin>>x>>y>>z;
            cnt=0;
            f(1,sz,x,y,1,z);
            if (cnt<=1) {
                cout<<"YES"<<'\n';
            } else cout<<"NO"<<'\n';
        } else {
            cin>>x>>y;
            update(x,y);
        }
    }
}