#include <bits/stdc++.h>
#define rep(i,l,r) for (int i=l,i##end=r;i<=i##end;++i)
#define per(i,r,l) for (int i=r,i##end=l;i>=i##end;--i)
#define sit set< pr >::iterator
#define pr pair<int,int>
#define mp make_pair
#define fi first
#define se second
using namespace std;
const int N=1e6+6;
pr b[N]; int a[N];
set< pr > s;
int main(){
    int n; scanf("%d",&n);
    rep(i,1,n) scanf("%d",&a[i]);
    rep(i,1,n){
        int t; scanf("%d",&t);
        b[i]=mp(t,i);
    }
    sort(b+1,b+1+n);
    long long ans=0; s.insert(mp(a[b[n].se],a[b[n].se]));
    per(i,n-1,1){
        int u=b[i].se; sit it=s.lower_bound(mp(a[u]+1,0));
        if (it==s.begin()){
            if (it->fi>a[u]+1) s.insert(mp(a[u],a[u]));
            else{ int r=it->se; s.erase(it); s.insert(mp(a[u],r)); }
            continue;
        }
        sit itr=it; --it;
        if (it->se<a[u]-1){
            if (itr->fi==a[u]+1){ int r=itr->se; s.erase(itr); s.insert(mp(a[u],r)); }
            else s.insert(mp(a[u],a[u]));
            continue;
        }
        int x=it->se+1; ans+=(long long)(x-a[u])*b[i].fi;
        int t1=it->fi; s.erase(it); s.insert(mp(t1,x));
        if (itr!=s.end()&&itr->fi==x+1){
            int t2=itr->se; s.erase(mp(t1,x)),s.erase(itr);
            s.insert(mp(t1,t2));
        }

    }
    cout<<ans<<endl;
    return 0;
}