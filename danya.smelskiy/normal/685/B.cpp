#include <bits/stdc++.h>
using namespace std;

int n,m;

int ans[300005];
int pred[300005];
vector<int> v[300005];
int cnt[300005];
int mx[300005];


void dfs1(int x,int y) {
    pred[x]=y;
    cnt[x]=1;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        dfs1(to,x);
        cnt[x]+=cnt[to];
        if (cnt[to]>mx[x]) mx[x]=cnt[to];
    }
}


void dfs2(int x,int y) {
    int nxt1=0;
    int mm=0;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        dfs2(to,x);
        if (cnt[to]>mm) {
            mm=cnt[to];
            nxt1=ans[to];
        }
    }
    ans[x]=x;
    if (nxt1) {
        while (nxt1!=x) {
            if (mx[nxt1]<=(cnt[x])/2 && cnt[x]-cnt[nxt1]<=(cnt[x])/2) break;
            nxt1=pred[nxt1];
        }
        ans[x]=nxt1;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=2;i<=n;++i) {
        int x;
        cin>>x;
        v[x].push_back(i);
    }
    dfs1(1,-1);
    dfs2(1,-1);
    while (m--) {
        int x;
        cin>>x;
        cout<<ans[x]<<'\n';
    }
}