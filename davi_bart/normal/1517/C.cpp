#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define fi first
#define se second
#define ld long double
#define pb push_back
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int k[600][600];
int N;
int dfs(int x,int y,int rim,int val){
    if(rim==0)return 0;
    if(x<0 || y<0 || x>=N || y>=N || k[x][y]!=-1)return 0;
    int tolti=0;
    tolti++;
    k[x][y]=val;
    tolti+=dfs(x,y-1,rim-1,val);
    if(tolti==rim)return tolti;
    tolti+=dfs(x+1,y,rim-1,val);
    return tolti;
}
void solve(){
    for(int i=0;i<550;i++){
        for(int j=0;j<550;j++)k[i][j]=-1;
    }
    cin>>N;
    vector<int> v(N);
    //for(int i=0;i<N;i++)v[i]=i+1;
    //shuffle(v.begin(),v.end(),rng);
    for(int &i:v)cin>>i;
    for(int i=0;i<N;i++){
        int rim=v[i];
        dfs(i,i,rim,v[i]);
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<=i;j++)cout<<k[i][j]<<" ";
        cout<<'\n';
    }

}
signed main() {
	ios::sync_with_stdio(false);cin.tie(0);
    int T=1;
    //cin>>T;
    while(T--)solve();
}