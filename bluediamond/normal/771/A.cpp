#include <bits/stdc++.h>

using namespace std;

const int N=150000+5;
int n,m;
vector<int>v[N];
bool viz[N];

int nr_nod=0,nr_road=0;

void dfs(int nod) {
    viz[nod]=1;
    nr_nod++;
    nr_road+=v[nod].size();
    for(auto nou:v[nod]) {
        if(viz[nou]==0) {
            dfs(nou);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    while(m--) {
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=1;i<=n;i++) {
        if(viz[i]==0) {
            nr_nod=0;
            nr_road=0;
            dfs(i);
            if((long long)nr_road!=(long long)nr_nod*(nr_nod-1)) {
                cout<<"NO\n";
                return 0;
            }
        }
    }
    cout<<"YES\n";
    return 0;
}