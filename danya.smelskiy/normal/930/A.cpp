#include <bits/stdc++.h>
using namespace std;


int n;
vector<int> v[100005];
int cnt[100005];
int ans;


void dfs(int x,int y=1) {
    ++cnt[y];
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        dfs(to,y+1);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>n;
    for (int i=2;i<=n;++i) {
        int x;
        cin>>x;
        v[x].push_back(i);
    }
    dfs(1);
    for (int i=1;i<=n;++i) {
        cnt[i]%=2;
        ans+=cnt[i];
    }
    cout<<ans;

}