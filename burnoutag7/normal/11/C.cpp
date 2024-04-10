//
//
//
//
//
//
//
#include<bits/stdc++.h>
using namespace std;

int n,m,dx[]={-1,-1,0,1,1,1,0,-1},dy[]={0,1,1,1,0,-1,-1,-1};
char g[255][255];

void dfs(int x,int y,vector<pair<int,int>> &v){
    v.emplace_back(x,y);
    g[x][y]='0';
    for(int d=0;d<8;d++){
        int nx=x+dx[d],ny=y+dy[d];
        if(nx&&ny&&nx<=n&&ny<=m&&g[nx][ny]=='1'){
            dfs(nx,ny,v);
        }
    }
}

bool horizontal(vector<pair<int,int>> &v){
    int sz=v.size()>>2,x=v.front().first,y=v.front().second;
    vector<pair<int,int>> s;
    for(int i=0;i<sz;i++)s.emplace_back(x+i,y);
    for(int i=1;i<=sz;i++)s.emplace_back(x,y+i);
    for(int i=0;i<sz;i++)s.emplace_back(x+sz,y+i);
    for(int i=1;i<=sz;i++)s.emplace_back(x+i,y+sz);
    //12222
    //1   4
    //1   4
    //1   4
    //33334
    sort(s.begin(),s.end());
    return s==v;
}

bool diagonal(vector<pair<int,int>> &v){
    int sz=v.size()>>2,x=v.front().first,y=v.front().second,cx=x,cy=y;
    vector<pair<int,int>> s;
    for(int i=0;i<sz;i++)s.emplace_back(x+i,y-i);
    for(int i=1;i<=sz;i++)s.emplace_back(x+i,y+i);
    for(int i=0;i<sz;i++)s.emplace_back(x+sz+i,y-sz+i);
    for(int i=1;i<=sz;i++)s.emplace_back(x+sz+i,y+sz-i);
    //   1
    //  1 2
    // 1   2
    //3     2
    // 3   4
    //  3 4
    //   4
    sort(s.begin(),s.end());
    return s==v;
}

bool parse(vector<pair<int,int>> &v){
    if(v.size()&3)return false;
    sort(v.begin(),v.end());
    if(v.front().first==v[1].first)return horizontal(v);
    else return diagonal(v);
}

void mian(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>g[i]+1;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++)if(g[i][j]=='1'){
            vector<pair<int,int>> v;
            dfs(i,j,v);
            ans+=parse(v);
        }
    }
    cout<<ans<<'\n';
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