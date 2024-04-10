#include <bits/stdc++.h>
using namespace std;



int n,x,y;
int depth[1000005];
int num[1000005];
vector<int> v[1000005];
int dp1[1000005];
int dp2[1000005];
map<int,int> cnt[1000005];

inline void add(int x,int y,int z) {
    cnt[num[x]][y]+=z;
    int cur=cnt[num[x]][y];
    if (cur>dp1[x] || (cur==dp1[x] && y<dp2[x])) {
        dp1[x]=cur;
        dp2[x]=y;
    }
}

void solve(int x,int y=0) {
    depth[x]=depth[y]+1;
    dp1[x]=1;
    dp2[x]=depth[x];
    num[x]=x;
    int mx=0;
    int nxt=x;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (to==y) continue;
        solve(to,x);
        if (cnt[num[to]].size()>mx) {
            mx=cnt[num[to]].size();
            nxt=num[to];
        }
    }
    num[x]=nxt;
    add(x,depth[x],1);
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (to==y) continue;
        if (num[to]==nxt) {
            if (dp1[to]>dp1[x] || (dp1[to]==dp1[x] && dp2[to]<dp2[x])) {
                dp1[x]=dp1[to];
                dp2[x]=dp2[to];
            }
            continue;
        }
        for (auto it : cnt[num[to]]) {
            add(x,it.first,it.second);
       //     cout<<"<"<<x<<" "<<it.first<<" "<<it.second<<'\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<n;++i) {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    solve(1);
    for (int i=1;i<=n;++i)
        cout<<dp2[i]-depth[i]<<'\n';
}