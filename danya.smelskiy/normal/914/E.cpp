#include <bits/stdc++.h>
using namespace std;

int n;
string s;
vector<int> v[200005];
bool used[200005];
int mt[(1<<21)+5];
long long ans[200005];
int cnt[200005];
int pw[100];
int mx[200005];
vector<int> q,qq;


void dfs1(int x,int y=-1) {
    cnt[x]=1;
    mx[x]=0;
    q.push_back(x);
    for (int i=0;i<(int)v[x].size();++i) {
        int to=v[x][i];
        if (to!=y && used[to]==false) {
            dfs1(to,x);
            cnt[x]+=cnt[to];
            if (mx[x]<cnt[to]) {
                mx[x]=cnt[to];
            }
        }
    }
}

long long dfs2(int x,int y,int z) {
    qq.push_back(z);
    long long res=0;
    res+=mt[z];
    for (int i=0;i<(int)v[x].size();++i) {
        int to=v[x][i];
        if (to!=y && used[to]==false) {
            res+=dfs2(to,x,(z^pw[(s[to]-'a')]));
        }
    }
    ans[x]+=res;
    return res;
}

void solve(int x) {
    int zz=s[x]-'a';
    zz=pw[zz];
    vector<int> qqq;
    mt[zz]=1;
    qqq.push_back(zz);
    for (int i=0;i<20;++i)
        mt[(zz^pw[i])]++;

    for (int i=0;i<(int)v[x].size();++i) {
        int y=v[x][i];
        if (used[y]) continue;
        qq.clear();
        ans[x]+=dfs2(y,-1,(1<<(s[y]-'a')));
        for (int j=0;j<(int)qq.size();++j) {
            int p=(qq[j]^zz);
            qqq.push_back(p);
            mt[p]++;
            for (int k=0;k<20;++k)
                mt[(p^pw[k])]++;
        }
    }
    for (int i=0;i<qqq.size();++i) {
        int p=qqq[i];
        --mt[p];
        for (int k=0;k<20;++k)
            --mt[(p^pw[k])];
    }
    qqq.clear();
    for (int i=v[x].size()-1;i>=0;--i) {
        int y=v[x][i];
        if (used[y]) continue;
        qq.clear();
        dfs2(y,-1,(1<<(s[y]-'a')));
        for (int j=0;j<(int)qq.size();++j) {
            int p=(qq[j]^zz);
            qqq.push_back(p);
            mt[p]++;
            for (int k=0;k<20;++k)
                mt[(p^pw[k])]++;
        }
    }
    for (int i=0;i<qqq.size();++i) {
        int p=qqq[i];
        --mt[p];
        for (int k=0;k<20;++k)
            --mt[(p^pw[k])];
    }

}

void build(int x) {
    q.clear();
    dfs1(x);
    int c=-1;
    int mn=1e9;
    int all=cnt[x];
    for (int i=0;i<(int)q.size();++i) {
        int y=q[i];
        int z=max(mx[y],all-cnt[y]);
        if (z<mn) {
            mn=z;
            c=y;
        }
    }
    used[c]=true;
    solve(c);
    for (int i=0;i<(int)v[c].size();++i) {
        int to=v[c][i];
        if (used[to]==false) build(to);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    for (int i=0;i<=30;++i)
        pw[i]=(1<<i);
    cin>>n;
    for (int i=1;i<n;++i) {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    cin>>s;
    s="#"+s;
    build(1);
    for (int i=1;i<=n;++i)
        cout<<ans[i]+1ll<<" ";
}