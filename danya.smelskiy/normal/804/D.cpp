#include <bits/stdc++.h>
using namespace std;


bool used[100005];
vector<long long> v[100005];
long long to1[100005],to2[100005];
long long clr[100005];
long long all;
long long n,m,q,x,y;

long long len1[100005],len2[100005];
long long sz[100005];
long long diam;
long long d[100005];
vector<long long> qq[100005];
map<pair<long long,long long>,long double> ans;
vector<long long> p[100005];
vector<long long> qq2[100005];
void dfs1(long long x,long long y=-1){
    used[x]=true;
    ++sz[all];
    clr[x]=all;
    qq[all].push_back(x);
    long long mx1=0,mx2=0;
    for (long long i=0;i<v[x].size();++i) {
        long long to=v[x][i];
        if (to==y) continue;
        dfs1(to,x);
        if (len1[to]+1>mx2) {
            mx2=len1[to]+1;
            to2[x]=to;
            if (mx2>mx1) {
                swap(mx2,mx1);
                swap(to1[x],to2[x]);
            }
        }
    }
    len1[x]=mx1;
    len2[x]=mx1;
    diam=max(diam,mx1+mx2);
}
void dfs2(long long x,long long y=-1,long long ll=0){
    len2[x]=max(len2[x],ll);
    for (long long i=0;i<v[x].size();++i) {
        long long to=v[x][i];
        if (to==y) continue;
        long long lto=ll+1;
        if (to1[x] && to1[x]!=to) lto=max(lto,len1[to1[x]]+2);
        else if (to2[x] && to2[x]!=to) lto=max(lto,len1[to2[x]]+2);
        dfs2(to,x,lto);
    }
}
inline long double solve(long long x,long long y,long long z=0){
    x=clr[x]; y=clr[y];
    if (x==y) return -1.;
    if (sz[x]>sz[y]) swap(x,y);
    if (sz[x]>=sqrt(n) && z) return ans[make_pair(x,y)];
    long double res=0;
    long long dd=max(d[x],d[y]);
    for (long long i=0;i<qq2[x].size();++i) {
        long long ll1=qq2[x][i]+1;
        long long l=0;
        long long r=qq2[y].size()-1;
        while (l<r-1) {
            long long mid=(l+r)>>1;
            if (qq2[y][mid]+ll1>=dd) r=mid;
            else l=mid;
        }
        if (qq2[y][l]+ll1>=dd) r=l;
        if (qq2[y][r]+ll1>=dd) {
            long double res2=0;
            res2=(qq2[y].size()-r)*ll1+p[y][(long long)p[y].size()-1]-(r ? p[y][r-1] : 0);
            res+=res2;
        }
        if (qq2[y][0]+ll1<dd) {
            if (qq2[y][r]+ll1<dd) ++r;
            res+=r*dd;
        }
    }
    return (long double)(res)/(long double)(qq[x].size()*qq[y].size());
}
main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>q;
    for (long long i=1;i<=m;++i) {
        long long x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    vector<long long> vv;
    for (long long i=1;i<=n;++i)
    if (used[i]==false){
        ++all;
        diam=0;
        dfs1(i);
        d[all]=diam;
        dfs2(i);
        if (sz[all]>=sqrt(n)) vv.push_back(i);
        for (long long j=0;j<qq[all].size();++j) {
            long long to=qq[all][j];
            qq2[all].push_back(len2[to]);
        }
        sort(qq2[all].begin(),qq2[all].end());
        for (long long j=0;j<qq2[all].size();++j) {
            p[all].push_back(qq2[all][j]);
            if (j) p[all][j]+=p[all][j-1];
        }
    }
    for (long long i=0;i<vv.size();++i)
    for (long long j=i+1;j<vv.size();++j) {
        long double res=solve(vv[i],vv[j],0);
        long long x=clr[vv[i]];
        long long y=clr[vv[j]];
        ans[make_pair(x,y)]=ans[make_pair(y,x)]=res;
    }
    for (long long i=1;i<=q;++i) {
        cin>>x>>y;
        cout<<fixed<<setprecision(6)<<solve(x,y,1)<<'\n';
    }
}