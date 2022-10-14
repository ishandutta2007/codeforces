#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
#include <immintrin.h>
using namespace std;

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
 
using ll=long long;
using pii=pair<int, int>;
//#define int ll
const int MOD = 1000000007;

int aray[200005];
int n;

struct tag {
    pii mp;
    int orz;
    const tag operator+(const tag& o) const {
        return {max(mp,o.mp),orz|o.orz};
    }
} segt[800006];

void bld(int idx,int l,int r){
    if(r-l==1){
        segt[idx]={mp(aray[l],l),aray[l]};
        return;
    }
    bld(idx*2,l,(l+r)/2);
    bld(idx*2+1,(l+r)/2,r);
    segt[idx]=segt[idx*2]+segt[idx*2+1];
}

tag qry(int idx,int l,int r,int L,int R){
    if(L<=l&&r<=R)return segt[idx];
    if(R<=l||r<=L)return {mp(-1,0),0};
    return qry(idx*2,l,(l+r)/2,L,R)+qry(idx*2+1,(l+r)/2,r,L,R);
}

ll solve(int l,int r){
    if(l==r)return 1;
    if(l>r)return 0;
    auto [a,b]=qry(1,0,n,l,r+1);
    int m=a.se,v=a.fi;
    ll x=0;
    // if(v==b)x=r-l+1;
    {
        int cnt=0;
        for(int i=18;i>=0;i--){
            int tes=cnt|(1<<i);
            if((m+tes-1<=r)&&(qry(1,0,n,m,m+tes).orz==v))cnt=tes;
        }
        int A=cnt;
        cnt=0;
        for(int i=18;i>=0;i--){
            int tes=cnt|(1<<i);
            if((l<=m-tes+1)&&(qry(1,0,n,m-tes+1,m+1).orz==v))cnt=tes;
        }
        ll B=cnt;
        // cout<<m<<' '<<A<<' '<<B<<endl;
        x=A*B;
    }
    return x+solve(l,m-1)+solve(m+1,r);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin>>n;
    mt19937 rng(0);
    rep(i,n)cin>>aray[i];
    // 10000 4994729
    // 50000 1249973533
    // rep(i,n)aray[i]=rng()%(512);
    bld(1,0,n);
    cout<<1ll*n*(n+1)/2-solve(0,n-1)<<endl;
}