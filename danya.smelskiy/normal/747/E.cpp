#include <bits/stdc++.h>
using namespace std;


string s;
int ans;
vector<string > v[1000001];
int l;

pair<string,int> get_new(){
    pair<string,int> res;
    res.first=""; res.second=0;
    while (!(s[l]>='0' && s[l]<='9') && s[l]!=',') {
        res.first+=s[l];
        ++l;
    }
    ++l;
    while (l<s.size() && (s[l]>='0' && s[l]<='9')) {
        res.second=(res.second*10+(s[l]-'0'));
        ++l;
    }
    ++l;
    return res;
}

void dfs(int depth,pair<string,int> q){
    v[depth].push_back(q.first);
    if (depth>ans) ans=depth;
    while (q.second) {
        --q.second;
        dfs(depth+1,get_new());
    }
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin>>s;
    while (l<s.size()) {
        pair<string,int> t=get_new();
        dfs(1,t);
    }
    cout<<ans<<'\n';
    for (int i=1;i<=ans;++i) {
        for (int j=0;j<v[i].size();++j)
            cout<<v[i][j]<<" ";
        cout<<'\n';
    }
}