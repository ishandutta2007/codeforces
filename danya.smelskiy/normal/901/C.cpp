#include <bits/stdc++.h>
using namespace std;

int used[300005];
bool used2[300005];
vector<int> v[300005];
vector<int> qq[300005];
int pred[300005];
int n,m;
vector<pair<int,int> > qqq[300005];
long long t[4000000];
long long q[4000000];
long long ans[300005];
int mm;
int sz;

void dfs(int x,int y=-1){
    used[x]=1;
    pred[x]=y;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (used2[to] || to==y) continue;
        if (used[to]==2) continue;
        if (used[to]==0) {
            dfs(to,x);
            continue;
        }
        vector<int> q;
        int xx=x;
        while (xx!=to) {
            q.push_back(xx);
            xx=pred[xx];
        }
        q.push_back(xx);
        int mn=1e9,mx=-1e9;
        for (int j=0;j<q.size();++j) {
            mn=min(mn,q[j]);
            mx=max(mx,q[j]);
            used2[q[j]]=true;
        }
        qq[mx].push_back(mn);
    }
    used[x]=2;
}
void push(int x,int l,int r){
    if(!q[x]) return;
    q[x+x]+=q[x];
    q[x+x+1]+=q[x];
    int mid=(l+r)>>1;
    t[x+x]+=(long long)(mid-l+1)*q[x];
    t[x+x+1]+=(long long)(r-mid)*q[x];
    q[x]=0;
}
void update(int l,int r,int ll,int rr,int x){
    if (l>r || ll>r || l>rr) return;
    if (l>=ll && r<=rr) {
        t[x]+=(long long )(r-l+1);
        q[x]++;
        return;
    }
    int mid=(l+r)>>1;
    push(x,l,r);
    update(l,mid,ll,rr,x+x);
    update(mid+1,r,ll,rr,x+x+1);
    t[x]=t[x+x]+t[x+x+1];
}
long long get(int l,int r,int ll,int rr,int x){
    if (l>r || ll>r || l>rr) return 0;
    if (l>=ll && r<=rr) return t[x];
    int mid=(l+r)>>1;
    push(x,l,r);
    return get(l,mid,ll,rr,x+x)+get(mid+1,r,ll,rr,x+x+1);
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;++i) {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (int i=1;i<=n;++i)
        if (used2[i]==false) dfs(i);
    cin>>mm;
    for (int i=1;i<=mm;++i) {
        int x,y;
        cin>>x>>y;
        qqq[y].push_back(make_pair(x,i));
    }
    int last=1;
    sz=1;
    while (sz<n) sz+=sz;
    for (int i=1;i<=n;++i) {
        for (int j=0;j<qq[i].size();++j) {
            last=max(last,qq[i][j]+1);
        }
        update(1,sz,last,i,1);
        for (int j=0;j<qqq[i].size();++j) {
            long long res=get(1,sz,qqq[i][j].first,i,1);
            ans[qqq[i][j].second]=res;
        }
    }
    for (int i=1;i<=mm;++i)
        cout<<ans[i]<<'\n';
}