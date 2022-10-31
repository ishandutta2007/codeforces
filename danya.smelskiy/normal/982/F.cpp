#include <bits/stdc++.h>
using namespace std;

int n,m,x,y;
vector<int> v[100005];
vector<int> vv[100005];
int cnt[100005];
int all;
int used2[100005];
vector<int> ccc,ccc2;
int pos_in[100005];
int pos;
bool used[100005];
int all2;
int num[100005];
set<int> s[100005];
bool used3[100005];
int ob[100005];
bool used4[100005];
int clr[100005];
vector<int> q;
int pred[100005];
bool cycl;

void dfs(int x) {
    used[x]=true;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (!used[to]) dfs(to);
    }
    q.push_back(x);
}

void dfs2(int x,int y) {
    clr[x]=y;
    ++cnt[y];
    for (int i=0;i<vv[x].size();++i) {
        int to=vv[x][i];
        if (!clr[to]) dfs2(to,y);
    }
}

void dfs3(int x,int y=-1) {
    if (cycl) return;
    pred[x]=y;
    used2[x]=1;
    for (int i=0;i<v[x].size() && !cycl;++i) {
        int to=v[x][i];
        if (used[to]) continue;
        if (used2[to]==2) continue;
        if (used2[to]==0) {
            dfs3(to,x);
            continue;
        }
        int xx=x;
        while (true) {
            ccc.push_back(xx);
            if (xx==to) break;
            xx=pred[xx];
        }
        cycl=true;
        used2[x]=2;
        return;
    }
    used2[x]=2;
}

void get_cycl() {
    cycl=false;
    ccc.clear();
    memset(used2,0,sizeof(used2));
    for (int i=1;i<=n;++i) if (!used[i]) {
        dfs3(i);
        if (cycl) break;
    }
}

void dfs4(int x) {
    used3[x]=true;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (used3[to]==false && used[to]==false) dfs4(to);
    }
    q.push_back(x);
}

inline void add2(int l,int r) {
    ob[l]++;
    ob[r+1]--;
}

inline void add(int l,int r) {
    if (l<=r) add2(l,r);
    else {
        add2(l,n);
        add2(1,r);
    }
}

int mx1[100005];
int mx2[100005];

void solve(int x) {
    num[x]=x;
    int nxt=x;
    int z;
    mx2[x]=1e9;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (!used4[to] && !used3[to]) continue;
        if (used4[to]) {
            mx1[nxt]=max(mx1[nxt],pos_in[to]);
            mx2[nxt]=min(mx2[nxt],pos_in[to]);
        }
        if (!used3[to]) continue;
        mx1[x]=max(mx1[x],mx1[to]);
        mx2[x]=min(mx2[x],mx2[to]);
    }
    int xx;
    for (int i=0;i<vv[x].size();++i) {
        int to=vv[x][i];
        if (used4[to]) {
            if (mx1[x]) add(mx1[x],pos_in[to]),++all2;
            if (mx2[x]<1e9) add(mx2[x],pos_in[to]),++all2;
        }
    }
}

inline void solve2(int x) {
    memset(used,false,sizeof(used));
    used[x]=true;
    get_cycl();
    if (!cycl) {
        cout<<x;
        exit(0);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;++i) {
        cin>>x>>y;
        v[x].push_back(y);
        vv[y].push_back(x);
    }
    for (int i=1;i<=n;++i)
        if (!used[i]) dfs(i);
    reverse(q.begin(),q.end());
    for (int i=0;i<q.size();++i) {
        x=q[i];
        if (!clr[x]) dfs2(x,++all);
    }
    int z=0;
    for (int i=1;i<=all;++i)
        if (cnt[i]>=2) ++z,pos=i;
    if (z!=1) {
        cout<<"-1";
        return 0;
    }
    memset(used,false,sizeof(used));
    for (int i=1;i<=n;++i)
        if (clr[i]!=pos) used[i]=true;
    get_cycl();
//    for (int i=0;i<ccc.size();++i)
  //      cout<<ccc[i]<<'\n';
    reverse(ccc.begin(),ccc.end());
    for (int i=0;i<ccc.size();++i)
        used[ccc[i]]=true,used4[ccc[i]]=true,pos_in[ccc[i]]=i+1;
    ccc2=ccc;
    get_cycl();
    if (cycl) {
        cout<<"-1";
        return 0;
    }
    ccc=ccc2;
    q.clear();
    for (int i=1;i<=n;++i)
        if (used[i]==false && used3[i]==false) dfs4(i);
    for (int i=0;i<q.size();++i)
        solve(q[i]);
    for (int i=1;i<=n;++i)
    if (used4[i]) {
        for (int j=0;j<v[i].size();++j) {
            int to=v[i][j];
            if (used4[to]) ++all2,add(pos_in[to],pos_in[i]);
        }
    }
    int ss=0;
    for (int i=1;i<=ccc.size();++i) {
        ss+=ob[i];
        if (ss==all2) {
            solve2(ccc[i-1]);
            cout<<"-1";
            return 0;
        }
    }
    cout<<"-1";
}