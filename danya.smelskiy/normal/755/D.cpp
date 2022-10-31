#include <bits/stdc++.h>
using namespace std;
long long n,k;
long long ans,last,x,sz;
long long tree[6000001];
inline void update(long long x){
    x+=sz-1;
    tree[x]++;
    x/=2;
    while (x>0){
        tree[x]=tree[x+x]+tree[x+x+1];
        x/=2;
    }
}
long long get(long long l,long long r,long long ll,long long rr,long long v){
    if (l>r || l>rr || r<ll) return 0;
    if (l>=ll && r<=rr) return tree[v];
    long long mid=(l+r)/2;
    return get(l,mid,ll,rr,v+v)+get(mid+1,r,ll,rr,v+v+1);
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    //if (n==1000000 && k==500001)
        k=min(k,n-k);
    ans=1;
    last=1;
    sz=1;
    long long llast,y;
    while (sz<n) sz*=2;
    for (int i=1;i<=n;++i){
        x=last+k;
        llast=last+1;
        y=x-1;
        if (x>n) x-=n;
        if (y>n) y-=n;
        if (llast>n) llast-=n;
        if (llast>y){
         //   cout<<llast<<" "<<y<<endl;
           // cout<<get(1,sz,llast,n,1)<<" "<<get(1,sz,1,y,1)<<endl;
            ans+=get(1,sz,llast,n,1)+get(1,sz,1,y,1)+1;
            update(x);
            update(last);
        } else {
         //   cout<<llast<<" "<<y<<endl;
           // cout<<get(1,sz,llast,y,1)<<endl;
            ans+=get(1,sz,llast,y,1)+1;
            update(x);
            update(last);
        }
        last=x;
        cout<<ans<<" ";
      //  if (i==5) break;
    }

}