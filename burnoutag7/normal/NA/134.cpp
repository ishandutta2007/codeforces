#include<bits/stdc++.h>
using namespace std;

int n;
vector<pair<int,int> > g[200005];
int cnt,num,mnv;
vector<int> ansv;

void mksz(int x,int p){
    for(int i=0;i<g[x].size();i++){
        int &y=g[x][i].first,&z=g[x][i].second;
        if(y!=p){
            cnt+=z;
            mksz(y,x);
        }
    }
}

void dfs(int x,int p,int ori,int rev){
    int mx=cnt-ori+rev;
    for(int i=0;i<g[x].size();i++){
        int y=g[x][i].first,z=g[x][i].second;
        if(y!=p){
            dfs(y,x,ori+z,rev+(z^1));
        }
    }
    if(mx<mnv){
        ansv.clear();
        ansv.push_back(x);
        mnv=mx;
        num=1;
    }else{
        if(mx==mnv){
            ansv.push_back(x);
            num++;
        }
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n;
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(make_pair(b,0));
        g[b].push_back(make_pair(a,1));
    }
    mksz(1,-1);
    mnv=1e9;
    dfs(1,-1,0,0);
    cout<<mnv<<endl;
    sort(ansv.begin(),ansv.end());
    for(int i=0;i<num;i++){
        cout<<ansv[i]<<' ';
    }
    cout<<endl;

    return 0;
}