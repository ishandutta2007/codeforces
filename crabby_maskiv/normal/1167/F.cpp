#include<bits/stdc++.h>
#define getnum(p) (num[p]+tag[p]*(rgt[p]-lft[p]+1))
//#define TIME
using namespace std;
typedef long long ll;
const int N=500005;
const ll inf=0x3f3f3f3f;
const ll mod=1000000007;
int n,m;
int ls[3*N],rs[3*N],lft[3*N],rgt[3*N];
ll num[3*N],tag[3*N];
int rt,P;
void update(int p){
    num[p]=(getnum(ls[p])+getnum(rs[p]))%mod;
    return;
}
void pushd(int p){
    if(!tag[p]) return;
    tag[ls[p]]+=tag[p];tag[rs[p]]+=tag[p];
    num[p]=getnum(p);tag[p]=0;
    return;
}
int build(int l,int r){
    int p=++P;
    tag[p]=num[p]=0;
    lft[p]=l;rgt[p]=r;
    if(l==r) return p;
    int mid=(l+r)>>1;
    ls[p]=build(l,mid);
    rs[p]=build(mid+1,r);
    return p;
}
void change(int p,int pos){
    if(lft[p]==rgt[p]){
        tag[p]++;
        return;
    }
    pushd(p);
    int mid=(lft[p]+rgt[p])>>1;
    if(pos<=mid){
        tag[rs[p]]++;
        change(ls[p],pos);
    }
    else change(rs[p],pos);
    update(p);
    return;
}
ll query(int pos){
    if(pos<1||pos>n) return 0;
    int p=rt;
    ll ans=0;
    while(lft[p]<rgt[p]){
        pushd(p);
        int mid=(lft[p]+rgt[p])>>1;
        if(pos>mid){
            ans+=getnum(ls[p]);
            ans%=mod;
            p=rs[p];
        }
        else p=ls[p];
    }
    ans+=getnum(p);
    ans%=mod;
    return ans;
}
ll _query(int pos){
    int p=rt;
    ll ans=0;
    while(lft[p]<rgt[p]){
        pushd(p);
        int mid=(lft[p]+rgt[p])>>1;
        if(pos>mid) p=rs[p];
        else p=ls[p];
    }
    ans+=getnum(p);
    return ans;
}
struct node{
    ll v;int id;
    bool operator <(const node &b)const
    {
        return v<b.v;
    }
};
node a[N];
int main(){
    ios::sync_with_stdio(0);
    int i,j;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>a[i].v;a[i].id=i;
    }
    sort(a+1,a+n+1);
    ll ans=0;
    rt=build(1,n);
    for(i=1;i<=n;i++){
        int x=a[i].id;
        change(rt,x);
        ll k1=query(x-1);
        ll k2=_query(x);
        ll k3=((getnum(rt)-k1-k2)%mod+mod)%mod;
        ans+=(a[i].v*((n-x+1)*(k2*x-k1)%mod+x*(k3-(n-x)*k2)%mod)%mod+mod)%mod;
        ans%=mod;
    }
    cout<<ans;
    return 0;
}