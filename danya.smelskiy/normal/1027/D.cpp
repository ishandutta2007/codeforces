#include <bits/stdc++.h>
using namespace std;



int n;
int x;
vector<int> v[200005];
int a[200005];
int ans;
int used[200005];
int pred[200005];
vector<int> q;

void dfs(int x,int y=0) {
    used[x]=1;
    pred[x]=y;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (used[to]==0) dfs(to,x);
        else if (used[to]==1) {
            int z=x;
            while (true) {
                q.push_back(z);
                if (z==to) break;
                z=pred[z];
            }
        }
    }
    used[x]=2;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<=n;++i) {
        cin>>x;
        v[i].push_back(x);
    }
    int res=0;
    for (int i=1;i<=n;++i)
    if (used[i]==0) {
        q.clear();
        dfs(i);
        if (q.size()==0) continue;
        int mn=1e9;
        for (int j=0;j<q.size();++j)
            mn=min(mn,a[q[j]]);
        res+=mn;
    }
    cout<<res;
}