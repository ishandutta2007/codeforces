#include <bits/stdc++.h>
using namespace std;
const long long md=1e9+7;
int all;
long long sz;
int n,m;

int ts[2300000];
int tf[2300000];
bool tl[2300000],tr[2300000];

int a[400005];
int ansl[400005];
int ansr[400005];
vector<int> qq;
map<int,int> pl;
pair<int ,long long> dpl[400005];
pair<int ,long long> dpr[400005];
long long x;
vector<int> v[400005];
pair<int,long long> q[400005];
inline int add(int x){
    tl[x]=false;
    tr[x]=false;
    ts[x]=0;
    tf[x]=0;
}
pair<int ,long long> get(long long l,long long r,long long ll,long long rr,long long x){
    if (x==0 || l>r || l>rr || ll>r) return make_pair(0,0);
    if (l>=ll && r<=rr) return make_pair(tf[x],ts[x]);
    long long mid=(l+r)/2;
    pair<int ,long long> a1,a2;
    if (tl[x]==false) a1=make_pair(0,0); else a1=get(l,mid,ll,rr,x+x);
    if (tr[x]==false) a2=make_pair(0,0); else a2=get(mid+1,r,ll,rr,x+x+1);
    if (a1.first==a2.first) return make_pair(a1.first,(a1.second+a2.second)%md);
    else {
        if (a1.first>a2.first) return a1;
        else return a2;
    }
}
void update(long long l,long long r,long long ll,long long x,long long y,long long z){
    if (l==r) {
        if (tf[x]<y) {
            tf[x]=y;
            ts[x]=z;
        } else if (tf[x]==y) {
            ts[x]=(ts[x]+z)%md;
        }
        return;
    }
    int mid=(l+r)/2;
    if (ll<=mid){ if (tl[x]==false) { tl[x]=true; add(x+x);} update(l,mid,ll,x+x,y,z);}
    else { if (tr[x]==false) { tr[x]=true; add(x+x+1);} update(mid+1,r,ll,x+x+1,y,z); }
    pair<int,long long> a1,a2;
    if (tl[x]==false) a1=make_pair(0,0); else
    a1=make_pair(tf[x+x],ts[x+x]);
    if (tr[x]==false) a2=make_pair(0,0); else
    a2=make_pair(tf[x+x+1],ts[x+x+1]);
    if (a1.first==a2.first) {
        tf[x]=a1.first;
        ts[x]=(a1.second+a2.second)%md;
    } else {
        if (a1.first<a2.first) swap(a1,a2);
        tf[x]=a1.first;
        ts[x]=a1.second;
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    sz=1;
    while (sz<800000) sz+=sz;
    for (int i=1;i<=n;++i){
        cin>>a[i];
        ++a[i];
        qq.push_back(a[i]);
    }
    add(1);
    update(1,sz,1,1,0,1);
    for (int i=1;i<=m;++i) {
        cin>>q[i].first>>q[i].second;
        ++q[i].second;
        qq.push_back(q[i].second);
        v[q[i].first].push_back(i);
    }
    sort(qq.begin(),qq.end());
    int last=1;
    for (int i=0;i<qq.size();++i){
        if (i==qq.size()-1 || qq[i]!=qq[i+1]) {
            ++last;
            pl[qq[i]]=last;
        }
    }
    for (int i=1;i<=n;++i)
        a[i]=pl[a[i]];
    for (int i=1;i<=m;++i)
        q[i].second=pl[q[i].second];

    for (int i=1;i<=n;++i) {
        for (int j=0;j<v[i].size();++j) {
            x=v[i][j];
            x=q[x].second;
            ansl[v[i][j]]=get(1,sz,1,x-1,1).first+1;
        }
        pair<int,long long> z=get(1,sz,1,a[i]-1,1);
        z.first++;

        update(1,sz,a[i],1,z.first,z.second);


      if (n<0 || m<0) cout<<all<<"."<<endl;

        dpl[i]=z;
    }



    add(1);
    update(1,sz,800000,1,0,1);
    for (int i=n;i>0;--i) {
        for (int j=0;j<v[i].size();++j) {
            x=v[i][j];
            x=q[x].second;
            ansr[v[i][j]]=get(1,sz,x+1,800000,1).first;
        }
        pair<int ,long long> z=get(1,sz,a[i]+1,800000,1);
        z.first++;
        dpr[i]=z;
        update(1,sz,a[i],1,z.first,z.second);
    }
    pair<int,long long> nvp;
    nvp=get(1,sz,1,800000,1);
    for (int i=1;i<=m;++i) {
        int ansnow=nvp.first-1;
        ansnow=max(ansnow,ansl[i]+ansr[i]);
        int zz=dpl[q[i].first].first+dpr[q[i].first].first-1;
        long long z=(dpl[q[i].first].second*dpr[q[i].first].second)%md;
        if (!(zz==nvp.first && z==nvp.second)) ansnow=max(ansnow,nvp.first);
        cout<<ansnow<<'\n';
    }
}