#include <bits/stdc++.h>
using namespace std;


int n,m,q;
map<string,int> number;
int p[100005];
bool used[100005];
int c[100005];
vector<pair<int,int> > v[100005];
bool ans[100005];
vector<pair<pair<int,int>,pair<int,int> > >   qq;


int get(int x) {
    if (x==p[x]) return x;
    else return p[x]=get(p[x]);
}

void dfs(int x,int y,int z) {
    c[x]=z;
    used[x]=true;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i].first;
        int len=v[x][i].second;
        len^=z;
        if (to!=y && used[to]==false) dfs(to,x,len);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m>>q;
    for (int i=1;i<=n;++i) {
        string s;
        cin>>s;
        number[s]=i;
    }
    for (int i=1;i<=n;++i)
        p[i]=i;
    for (int i=1;i<=m;++i) {
        int t,x,y;
        cin>>t;
        string s1,s2;
        cin>>s1>>s2;
        x=number[s1];
        y=number[s2];
        int xx=get(x);
        int yy=get(y);
        if (xx!=yy) {
            p[xx]=yy;
            v[x].push_back(make_pair(y,t-1));
            v[y].push_back(make_pair(x,t-1));
            ans[i]=true;
        } else {
            qq.push_back(make_pair(make_pair(x,y),make_pair(t-1,i)));
        }
    }
    for (int i=1;i<=n;++i)
        if (used[i]==false) dfs(i,-1,0);
    for (int i=0;i<qq.size();++i) {
        int x=qq[i].first.first;
        int y=qq[i].first.second;
        int z=c[x]^c[y];
        if (z==qq[i].second.first) ans[qq[i].second.second]=true;
    }
    for (int i=1;i<=m;++i)
        cout<<(ans[i] ? "YES" : "NO")<<'\n';
    while (q--) {
        string s1,s2;
        cin>>s1>>s2;
        int x=number[s1];
        int y=number[s2];
        if (get(x)!=get(y)) cout<<3<<'\n';
        else {
            int z=c[x]^c[y];
            cout<<(z ? 2 : 1)<<'\n';
        }
    }
}