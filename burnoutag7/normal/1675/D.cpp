#include<bits/stdc++.h>
using namespace std;

int n,rt;
vector<int> g[200005];
vector<stack<int>> ans;

int dfs(int x){
    if(g[x].empty()){
        ans.emplace_back();
        ans.back().emplace(x);
        return ans.size()-1;
    }else{
        bool f=1;
        int res=0;
        for(int y:g[x])if(f){
            ans[res=dfs(y)].emplace(x);
            f=0;
        }else{
            dfs(y);
        }
        return res;
    }
}

void mian(){
    for(int i=1;i<=n;i++)g[i].clear();
    ans.clear();
    cin>>n;
    for(int i=1;i<=n;i++){
        int fa;
        cin>>fa;
        if(fa==i)rt=i;
        else g[fa].emplace_back(i);
    }
    dfs(rt);
    cout<<ans.size()<<'\n';
    for(auto &s:ans){
        cout<<s.size()<<'\n';
        while(!s.empty()){
            cout<<s.top()<<' ';
            s.pop();
        }
        cout<<'\n';
    }
    cout<<'\n';
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    while(T--)mian();

    return 0;
}