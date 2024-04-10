#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int N=200000;
int n,root;
int sz[N+5];
vector<int>v[N+5];

void dfs1(int nod) {
    int ans=0;
    for(auto nou:v[nod]) {
        dfs1(nou);
        ans+=sz[nou];
    }
    sz[nod]=ans+1;
}

void dfs(int nod) {
    for(auto nou:v[nod])
        if(sz[nou]%2==0)
            dfs(nou);
    cout<<nod<<"\n";
    for(auto nou:v[nod])
        if(sz[nou]%2==1)
            dfs(nou);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int nod=1;nod<=n;nod++) {
        int t;
        cin>>t;
        if(t==0)
            root=nod;
        else
            v[t].push_back(nod);
    }
    if(n%2==0) {
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    dfs1(root);
    dfs(root);
    return 0;
}
/**

**/