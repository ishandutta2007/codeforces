#include <bits/stdc++.h>
using namespace std;
const int szblock=250;


int l,r;
long long k;
int n,m;

map<long long,int> mt;
long long a[100005];
short t[100005];
int last;
vector<pair<pair<int,int>,int> > qq;
vector<long long> v;
vector<int> q[120000];
int lnow[120000];
int rnow[120000];
int to1[120000],to2[120000];
long long res;
long long ans[100005];

inline bool cmp(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b){
    int l1=(a.first.first+szblock-1)/szblock;
    int l2=(b.first.first+szblock-1)/szblock;
    if (l1!=l2) return l1<l2;
    return a.first.second<b.first.second;
}
inline long long kol_in_range(int l,int r,long long x){


    ////!!!!LOG

    if (!x) return 0ll;
    lnow[x]=min(lnow[x],rnow[x]);
    rnow[x]=max(rnow[x],lnow[x]);
    while (rnow[x]<q[x].size()-1 && q[x][rnow[x]+1]<=r) ++rnow[x];
    while (lnow[x] && q[x][lnow[x]-1]>=l) --lnow[x];
    while (rnow[x]>=0 && q[x][rnow[x]]>r) --rnow[x];
    if (rnow[x]==-1) {
        rnow[x]=0;
        lnow[x]=0;
        return 0;
    }
    if (q[x][rnow[x]]<l) return 0;
    while (lnow[x]<q[x].size() && q[x][lnow[x]]<l) ++lnow[x];
    return rnow[x]-lnow[x]+1;
}
inline void addr(int ll,int rr){
    long long z=to2[rr];
    long long res2=kol_in_range(ll-1,rr-1,z);
    res+=res2;
}
inline void addl(int ll,int rr){
    long long z=to1[ll-1];
    long long res2=kol_in_range(ll,rr,z);
    res+=res2;
}
inline void delr(int ll,int rr){
    long long z=to2[rr];
    long long res2=kol_in_range(ll-1,rr-1,z);
    res-=res2;
}
inline void dell(int ll,int rr){
    long long z=to1[ll-1];
    long long res2=kol_in_range(ll,rr,z);
    res-=res2;
}

inline void solve(int ll,int rr){
    while (r<rr) {
        ++r;
        addr(l,r);
    }
    while (r>rr) {
        delr(l,r);
        --r;
    }
    while (l<ll) {
        dell(l,r);
        ++l;
    }
    while (l>ll) {
        --l;
        addl(l,r);
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>k;
    for (int i=1;i<=n;++i) {
        cin>>t[i];
    }
    for (int i=1;i<=n;++i) {
        cin>>a[i];
        a[i]=(a[i-1]+(t[i]==1 ? a[i] : -a[i]));
        v.push_back(a[i]);
    }
    v.push_back(0);
    sort(v.begin(),v.end());
    last=0;
    for (int i=0;i<v.size();++i) if (!i || v[i]!=v[i-1]) {
        mt[v[i]]=++last;
    }
    q[mt[0]].push_back(0);
    for (int i=1;i<=n;++i) {
        q[mt[a[i]]].push_back(i);
    }
    cin>>m;
    for (int i=1;i<=m;++i) {
        cin>>l>>r;
        qq.push_back(make_pair(make_pair(l,r),i));
    }
    for (int i=0;i<=n;++i) {
        to1[i]=mt[a[i]+k];
        to2[i]=mt[a[i]-k];
    }
    sort(qq.begin(),qq.end(),cmp);
    l=qq[0].first.first;
    r=qq[0].first.second;
    for (int i=l;i<=r;++i)
        addr(l,i);
    ans[qq[0].second]=res;
    for (int i=1;i<qq.size();++i) {
        solve(qq[i].first.first,qq[i].first.second);
        ans[qq[i].second]=res;
    }
    for (int i=1;i<=m;++i)
        cout<<ans[i]<<'\n';
}