#include<bits/stdc++.h>
using namespace std;

int n,cnt[2];
vector<int> g[200005];

void dfs(int x,int p,int c){
    cnt[c]++;
    for(int &y:g[x])if(y!=p){
        dfs(y,x,c^1);
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    while(--n){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,-1,0);
    cout<<min(cnt[0],cnt[1])-1<<endl;

    return 0;
}