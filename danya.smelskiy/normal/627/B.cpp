#include <bits/stdc++.h>
using namespace std;



int n,k;
long long a,b;
int q;
long long t[3][1000005];
int sz;
long long w[1000005];

inline void update(int x,int y,long long z) {
    y+=sz-1;
    t[x][y]=z;
    y>>=1;
    while (y) {
        t[x][y]=t[x][y+y]+t[x][y+y+1];
        y>>=1;
    }
}

long long get(int l,int r,int ll,int rr,int x,int y) {
    if (l>r || ll>r || l>rr || ll>rr) return 0;
    if (l>=ll && r<=rr) return t[y][x];
    int mid=(l+r)>>1;
    return get(l,mid,ll,rr,x+x,y)+get(mid+1,r,ll,rr,x+x+1,y);
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k>>a>>b>>q;
    sz=1;
    while (sz<n) sz+=sz;
    while (q--) {
        long long tp,x,y;
        cin>>tp;
        if (tp==1) {
            cin>>x>>y;
            w[x]+=y;
            update(1,x,min(w[x],b));
            update(2,x,min(w[x],a));
        } else {
            cin>>x;
            long long res=get(1,sz,1,x-1,1,1)+get(1,sz,x+k,n,1,2);
            cout<<res<<'\n';
        }
    }
}