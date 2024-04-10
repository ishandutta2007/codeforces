#include <bits/stdc++.h>
using namespace std;

int cnt[100005];
vector<int> v[100005];
char ans[100005];
bool used[100005];
int mx[100005];
vector<int> q;
int n;


void dfs(int x,int y=-1) {
    cnt[x]=1;
    q.push_back(x);
    mx[x]=0;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (to!=y && used[to]==false) {
            dfs(to,x);
            cnt[x]+=cnt[to];
            mx[x]=max(mx[x],cnt[to]);
        }
    }
}

void build(int x,char c) {
    q.clear();
    dfs(x);
    int all=cnt[x];
    int mn=1e9;
    int pos=x;
    for (int i=0;i<q.size();++i) {
        int to=q[i];
        if (max(mx[to],all-cnt[to])<mn) {
            mn=max(mx[to],all-cnt[to]);
            pos=to;
        }
    }
    x=pos;
    used[x]=true;
    ans[x]=c;
    ++c;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (used[to]==false) build(to,c);
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<n;++i) {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    build(1,'A');
    for (int i=1;i<=n;++i)
        cout<<ans[i]<<" ";
}