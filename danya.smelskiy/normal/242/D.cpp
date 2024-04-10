#include <bits/stdc++.h>
using namespace std;

vector<int> ans;
vector<int> v[100001];
int n,m,x,y;
int a[100005];
int b[100005];
int q[100005];
int r;

int main(){
    //
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;++i) {
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<=n;++i)
    if (b[i]==a[i]) {
        ++r;
        q[r]=i;
    }
    int l=1;
    while (l<=r) {
        int x=q[l];
        ++l;
        if (b[x]!=a[x]) continue;
        ++b[x];
        ans.push_back(x);
        for (int i=0;i<v[x].size();++i) {
            int to=v[x][i];
            ++b[to];
            if (b[to]==a[to]) {
                ++r;
                q[r]=to;
            }
        }
    }
    cout<<ans.size()<<'\n';
    for (int i=0;i<ans.size();++i)
        cout<<ans[i]<<" ";
}