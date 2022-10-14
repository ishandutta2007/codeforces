// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
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

pii segt[300005<<2];
int laz[300005<<2];

void bld(int idx,int l,int r){
    segt[idx]={0,l};
    if(r-l==1)return;
    bld(idx*2,l,(l+r)/2);
    bld(idx*2+1,(l+r)/2,r);
}

void tag(int idx,int l,int r,int v){
    laz[idx]+=v;
    segt[idx].fi+=v;
}

void pd(int idx,int l,int r){
    if(r-l==1)return;
    tag(idx*2,l,(l+r)/2,laz[idx]);
    tag(idx*2+1,(l+r)/2,r,laz[idx]);
    laz[idx]=0;
}

void iadd(int idx,int l,int r,int L,int R,int v){
    if(L<=l&&r<=R)return tag(idx,l,r,v);
    if(R<=l||r<=L)return;
    pd(idx,l,r);
    iadd(idx*2,l,(l+r)/2,L,R,v);
    iadd(idx*2+1,(l+r)/2,r,L,R,v);
    segt[idx]=min(segt[idx*2],segt[idx*2+1]);
}

pii qmin(int idx,int l,int r,int L,int R){
    if(L<=l&&r<=R)return segt[idx];
    if(R<=l||r<=L)return {1000000000,0};
    pd(idx,l,r);
    return min(qmin(idx*2,l,(l+r)/2,L,R),qmin(idx*2+1,(l+r)/2,r,L,R));
}

int fenw[300005];
const int HIGH=300002;

void ad(int i,int v){
    while(i<=HIGH){
        fenw[i]+=v;
        i+=(i&(-i));
    }
}

int qr(int i){
    int s=0;
    while(i){
        s+=fenw[i];
        i-=(i&(-i));
    }
    return s;
}

int perm[300005];
int ord[300005];
int pos[300005];
bool codd[300005];
set<int> fupdlz;

bool cansub(int pos){
    return qr(pos)>0;
}

void forceupd(int pos) {
    assert(cansub(pos));
    iadd(1,1,HIGH,pos,HIGH,-1);
    ad(pos,-1);
    auto [X,Y]=qmin(1,1,HIGH,pos,HIGH);
    if(X<0){
        iadd(1,1,HIGH,Y,HIGH,1);
        ad(Y,1);
        fupdlz.insert(Y);
    }
}

void consider(int value) {
    if(codd[value])return;
    codd[value]=1;
    iadd(1,1,HIGH,pos[value],HIGH,1);
    ad(pos[value],1);
    auto g=fupdlz.lower_bound(pos[value]);
    if(g!=fupdlz.end()&&cansub(*g)){
        // cout<<pos[value]<<' '<<*g<<' '<<qr(*g)<<endl;
        forceupd(*g);
        fupdlz.erase(g);
    }
}

void updtime(int nxt) {
    if(cansub(ord[nxt]))forceupd(ord[nxt]);
    else fupdlz.insert(ord[nxt]);
}

bool check(int value) {
    consider(value);
    int ini=qr(pos[value]-1);
    int v2=qmin(1,1,HIGH,pos[value],HIGH).fi;
    //cout<<value<<' '<<ini<<' '<<v2<<endl;
    if(v2<=0)return 0;
    return 1;
}

signed main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    int n;cin>>n;
    bld(1,1,HIGH);
    rep1(i,n){
        cin>>perm[i];
        pos[perm[i]]=i;
    }
    rep1(i,n)cin>>ord[i];
    int ans=n;
    rep1(i,n){
        while(!check(ans))ans--;
        cout<<ans<<" \n"[i==n];
        if(i!=n)updtime(i);
    }
}