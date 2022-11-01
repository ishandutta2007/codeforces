#include<bits/stdc++.h>
using namespace std;

int n,m,x,h[100005],fa[100005];

void mian(){
    cin>>n>>m>>x;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    for(int i=1;i<=m;i++){
        q.emplace(0,i);
    }
    for(int i=1;i<=n;i++){
        cin>>h[i];
        int c=q.top().first,id=q.top().second;
        fa[i]=id;
        q.pop();
        q.emplace(c+h[i],id);
    }
    cout<<"YES\n";
    for(int i=1;i<=n;i++){
        cout<<fa[i]<<' ';
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