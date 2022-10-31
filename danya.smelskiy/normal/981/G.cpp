#include <bits/stdc++.h>
using namespace std;
const long long md=998244353;



int n,m,sz;
long long t[2000005];
long long q[2000005];
long long qq[2000005];
set<pair<int,int> > s[200005];

void push(int x,int l,int r) {
    if (qq[x]) {
        qq[x+x]=(qq[x+x]*qq[x])%md;
        qq[x+x+1]=(qq[x+x+1]*qq[x])%md;
        q[x+x]=(q[x+x]*qq[x])%md;
        q[x+x+1]=(q[x+x+1]*qq[x])%md;
        t[x+x]=(t[x+x]*qq[x])%md;
        t[x+x+1]=(t[x+x+1]*qq[x])%md;
        qq[x]=1;
    }
    int mid=(l+r)>>1;
    if (q[x]) {
        q[x+x]+=q[x];
        q[x+x+1]+=q[x];
        t[x+x]+=(mid-l+1)*1ll*q[x];
        t[x+x]%=md;
        t[x+x+1]+=(r-mid)*1ll*q[x];
        t[x+x+1]%=md;
        if (q[x+x]>=md) q[x+x]-=md;
        if (q[x+x+1]>=md) q[x+x+1]-=md;
        q[x]=0;
    }
}

void update_sum(int l,int r,int ll,int rr,int x) {
    if (l>r || ll>r || l>rr || ll>rr) return;
    if (l>=ll && r<=rr) {
        q[x]++;
        t[x]+=(r-l+1);
        if (q[x]>=md) q[x]-=md;
        if (t[x]>=md) t[x]-=md;
        return;
    }
    int mid=(l+r)>>1;
    push(x,l,r);
    update_sum(l,mid,ll,rr,x+x);
    update_sum(mid+1,r,ll,rr,x+x+1);
    t[x]=t[x+x]+t[x+x+1];
    if (t[x]>=md) t[x]-=md;
}

void update_mult(int l,int r,int ll,int rr,int x) {
    if (l>r || ll>r || l>rr || ll>rr) return;
    if (l>=ll && r<=rr) {
        t[x]=t[x]+t[x];
        q[x]=q[x]+q[x];
        qq[x]=qq[x]+qq[x];
        if (t[x]>=md) t[x]-=md;
        if (q[x]>=md) q[x]-=md;
        if (qq[x]>=md) qq[x]-=md;
        return;
    }
    int mid=(l+r)>>1;
    push(x,l,r);
    update_mult(l,mid,ll,rr,x+x);
    update_mult(mid+1,r,ll,rr,x+x+1);
    t[x]=t[x+x]+t[x+x+1];
    if (t[x]>=md) t[x]-=md;
}

long long get(int l,int r,int ll,int rr,int x) {
    if (l>r || l>rr || ll>r || ll>rr) return 0;
    if (l>=ll && r<=rr) return t[x];
    int mid=(l+r)>>1;
    push(x,l,r);
    long long res=get(l,mid,ll,rr,x+x)+get(mid+1,r,ll,rr,x+x+1);
    if (res>=md) res-=md;
    return res;
}

inline void split(int x,int l,int r,int k) {
    if (k>=r || k<l) return;
    s[x].erase(s[x].find(make_pair(l,r)));
    s[x].insert(make_pair(l,k));
    s[x].insert(make_pair(k+1,r));
}

pair<int,int> poc[200005];
int sz1;


inline void get_poc(int l,int r,int x) {
    if (s[x].empty()) {
        update_sum(1,sz,l,r,1);
        s[x].insert(make_pair(l,r));
        return;
    }
    set<pair<int,int> > ::iterator z=s[x].lower_bound(make_pair(l,0));
    if (z!=s[x].begin()) {
        --z;
        if (z->second>=l) split(x,z->first,z->second,l-1);
    }
    sz1=0;
    while (!s[x].empty()) {
        z=s[x].lower_bound(make_pair(l,0));
        if (z==s[x].end() || z->first>r) break;
        if (z->second>r) {
            split(x,z->first,z->second,r);
            continue;
        }
        poc[++sz1]=make_pair(z->first,z->second);
        s[x].erase(z);
    }
    if (sz1==0) {
        update_sum(1,sz,l,r,1);
        s[x].insert(make_pair(l,r));
        return;
    }
    for (int i=1;i<=sz1;++i) {
        update_mult(1,sz,poc[i].first,poc[i].second,1);
    }
    for (int i=2;i<=sz1;++i) {
        update_sum(1,sz,poc[i-1].second+1,poc[i].first-1,1);
    }
    update_sum(1,sz,l,poc[1].first-1,1);
    update_sum(1,sz,poc[sz1].second+1,r,1);
    s[x].insert(make_pair(l,r));
}


int main() {
//    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    sz=1;
    while (sz<n) sz+=sz;
    for (int i=1;i<=sz+sz;++i)
        qq[i]=1;
    int tp,l,r,x;
    for (int i=1;i<=m;++i) {
        cin>>tp;
        if (tp==1) {
            cin>>l>>r>>x;
            get_poc(l,r,x);
            continue;
        }
        cin>>l>>r;
        cout<<get(1,sz,l,r,1)<<'\n';
    }
}