#include <bits/stdc++.h>
using namespace std;


int n,m;
int nn;
int ans[200005];

void build(int l,int r,int x){
    //cout<<l<<" "<<r<<" "<<x<<'\n';
    if (l==r-1) {
        ans[l]=x;
        return;
    }
    if (l==r) return;
    if (!m) {
        ans[r-1]=x;
        return;
    }
    if (m==1) {
        cout<<"-1";
        exit(0);
    }
    m-=2;
    int mid=(l+r)>>1;
    if (!x) x=nn--;
    build(l,mid,x);
    build(mid,r,0);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    m--;
    nn=n;
    build(0,n,0);
    if (m!=0) {
        cout<<"-1";
        return 0;
    }
    for (int i=n-1;i>=0;--i)
        if (ans[i]==0) ans[i]=nn--;
    for (int i=0;i<n;++i)
        cout<<ans[i]<<" ";
}