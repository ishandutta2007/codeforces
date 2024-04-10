#include <bits/stdc++.h>
using namespace std;

int depth[100005];
int tin[100005],tout[100005];
int kol[100005];
int n,m;
int x,y;
vector<int> q[100005];
vector<pair<int,int> > qq[100005];
int timer;
vector<int> v[100005];
int t[500005];
string s;
int root;
int last[100005];
int all;
int ans[100005];
int name[100005];
map<string,int> num;
void dfs1(int x,int y,int d){
    depth[x]=d;
    tin[x]=++timer;
    q[d].push_back(x);
    ++kol[d];
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (to!=y) dfs1(to,x,d+1);
    }
    tout[x]=timer;
}
void update(int x,int y){
    t[x]+=y;
    x>>=1;
    while (x) {
        t[x]+=y;
        x>>=1;
    }
}
int get(int l,int r,int ll,int rr,int x){
    if (l>r || ll>r || l>rr) return 0;
    if (l>=ll && r<=rr) return t[x];
    int mid=(l+r)>>1;
    return get(l,mid,ll,rr,x+x)+get(mid+1,r,ll,rr,x+x+1);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    vector<int> roots;
    for (int i=1;i<=n;++i) {
        cin>>s;
        if (!num[s]) num[s]=++all;
        name[i]=num[s];
        cin>>x;
        if (!x) roots.push_back(i);
        else v[x].push_back(i);
    }
    for (int i=0;i<roots.size();++i) {
        int x=roots[i];
        dfs1(x,-1,1);
    }
    for (int i=1;i<=n;++i)
        kol[i]+=kol[i-1];
    cin>>m;
    for (int i=1;i<=m;++i) {
        cin>>x>>y;
        if (depth[x]+y>n || !(q[depth[x]+y].size())) {
            continue;
        }
        int l=0;
        int r=q[depth[x]+y].size()-1;
        while (l<r-1) {
            int mid=(l+r)>>1;
            if (tin[q[depth[x]+y][mid]]>=tin[x]) r=mid;
            else l=mid;
        }
        if (tin[q[depth[x]+y][l]]>=tin[x]) r=l;
        if (tin[q[depth[x]+y][r]]>tout[x] || tin[q[depth[x]+y][r]]<tin[x]) continue;
        int ll=r;
        l=0;
        r=q[depth[x]+y].size()-1;
        while (l<r-1) {
            int mid=(l+r)>>1;
            if (tin[q[depth[x]+y][mid]]<=tout[x]) l=mid;
            else r=mid;
        }
        if (tin[q[depth[x]+y][r]]<=tout[x]) l=r;
        qq[kol[depth[x]+y-1]+l+1].push_back(make_pair(ll,i));
    }
    for (int i=1;i<=n;++i)
    if (q[i].size()) {
        int sz=1;
        while (sz<q[i].size()) sz+=sz;
        for (int j=1;j<=sz+sz;++j)
            t[j]=0;
        for (int j=0;j<q[i].size();++j) {
            int x=q[i][j];
            x=name[x];
            if (last[x]) update(sz-1+last[x],-1);
            last[x]=j+1;
            update(sz-1+last[x],1);
            for (int k=0;k<qq[j+1+kol[i-1]].size();++k) {
                int ll=qq[j+1+kol[i-1]][k].first;
                int res=get(1,sz,ll+1,j+1,1);
                ans[qq[j+1+kol[i-1]][k].second]=res;
            }
        }
        for (int j=0;j<q[i].size();++j)
            last[name[q[i][j]]]=0;
    } else break;
    for (int i=1;i<=m;++i)
        cout<<ans[i]<<'\n';
}