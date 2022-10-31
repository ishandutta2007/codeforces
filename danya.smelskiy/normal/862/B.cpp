#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v[100005];
long long c1,c2;


void dfs(int x,int y,int z=0) {
    if (z) ++c1;
    else ++c2;
    for (int i=0;i<v[x].size();++i) {
        int to=v[x][i];
        if (to!=y) dfs(to,x,1-z);
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
    dfs(1,-1);
    long long ans=c1*c2;
    cout<<ans-(n-1ll);
}