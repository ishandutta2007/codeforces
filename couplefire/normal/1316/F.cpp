#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1000005;
const int mod =1e+9+7;
const int dbg = 0;

struct item {
    int v,x,t;
    bool operator < (const item &b) {
        return v < b.v;
    }
} I[N];
int n,m,seq[N],src[N],m1[N],m2[N],pos[N],p[N],iqp[N],qp[N];

int qpow(int p,int q) {
    return (q&1?p:1)*(q?qpow(p*p%mod,q/2):1)%mod;
}

int inv(int p) {
    return qpow(p,mod-2);
}

struct node {
    int val,sz,vl,vr;
} a[N*3];

node merge(node l,node r) {
    node ret;
    ret.val=(l.val+r.val+l.vl*r.vr%mod*iqp[l.sz]%mod)%mod;
    ret.sz=l.sz+r.sz;
    ret.vl=(l.vl+r.vl*qp[l.sz])%mod;
    ret.vr=(l.vr+r.vr*iqp[l.sz])%mod;
    return ret;
}

void open(int p,int l,int r,int x) {
    if(l==r) {
        a[p]={0,1,I[x].v,I[x].v*inv(2)%mod};
    }
    else {
        if(x<=(l+r)/2) open(p*2,l,(l+r)/2,x);
        else open(p*2+1,(l+r)/2+1,r,x);
        a[p]=merge(a[p*2],a[p*2+1]);
    }
}

void open(int x) {
    if(dbg) cout<<"open "<<x<<endl;
    open(1,1,n+m,x);
}

void close(int p,int l,int r,int x) {
    if(l==r) {
        a[p]={0,0,0,0};
    }
    else {
        if(x<=(l+r)/2) close(p*2,l,(l+r)/2,x);
        else close(p*2+1,(l+r)/2+1,r,x);
        a[p]=merge(a[p*2],a[p*2+1]);
    }
}

void close(int x) {
    if(dbg) cout<<"close "<<x<<endl;
    close(1,1,n+m,x);
}

signed main() {
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<=1e6;i++) {
        iqp[i]=inv(qpow(2,i));
        qp[i]=qpow(2,i);
    }
    for(int i=1;i<=n;i++) {
        cin>>p[i];
        I[i].v=p[i];
        I[i].x=i;
        I[i].t=0;
    }
    cin>>m;
    for(int i=1;i<=m;i++) {
        int t1,t2;
        cin>>t1>>t2;
        m1[i]=t1;
        m2[i]=t2;
        I[n+i].v=t2;
        I[n+i].x=i;
        I[n+i].t=1;
    }
    sort(I+1,I+n+m+1);
    for(int i=1;i<=n+m;i++) {
        src[i]=I[i].v;
        if(I[i].t==0) {
            seq[I[i].x]=i;
        }
        else {
            pos[I[i].x]=i;
        }
    }
    for(int i=1;i<=n;i++) {
        open(seq[i]);
    }
    cout<<a[1].val<<endl;
    for(int i=1;i<=m;i++) {
        close(seq[m1[i]]);
        open(pos[i]);
        seq[m1[i]]=pos[i];
        cout<<a[1].val<<endl;
    }
}