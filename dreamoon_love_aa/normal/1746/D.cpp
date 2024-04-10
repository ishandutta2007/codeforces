//#pragma GCC optimize("Ofast, no-stack-protector, unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define int long long
int ttt;
int n;int K;
int ar[200005];
vector<int>e[200005];
map<int,int>dp[200005];
map<int,int>vis[200005];
int dfs(int nw,int pa,int k){

if(k==0){return 0;}
if(vis[nw][k]){return dp[nw][k];}
int sz=e[nw].size();if(nw!=1){sz--;}
if(sz==0){return ar[nw]*k; }

vis[nw][k]=1;
vector<int>big;int bgv;
vector<int>small;int smv;
bgv=(k+(sz-1))/(sz);
smv=k/sz;
for(int i=0;i<e[nw].size();i++){
    int v=e[nw][i];
    if(v==pa){continue;}
    big.push_back(dfs(v,nw,bgv));
    small.push_back(dfs(v,nw,smv));
}
vector<int>vv;
for(int i=0;i<big.size();i++){
    vv.push_back(big[i]-small[i]);
    dp[nw][k]+=big[i];
}
sort(vv.begin(),vv.end());
int nd=(sz-(k%sz))%sz;
for(int i=0;i<nd;i++){
    dp[nw][k]-=vv[i];
}
dp[nw][k]+=k*ar[nw];
return dp[nw][k];
}

void CLR(){

for(int i=1;i<=n;i++){
    e[i].clear();dp[i].clear();vis[i].clear();
}

}

void solve(){
cin>>n>>K;
CLR();
for(int i=2;i<=n;i++){
    int v;
    scanf(" %lld",&v);
    e[v].push_back(i);
    e[i].push_back(v);
}
for(int i=1;i<=n;i++){
    scanf(" %lld",&ar[i]);
}

printf("%lld\n",dfs(1,0,K));

}


signed main()
{
    cin>>ttt;
    while(ttt--)solve();


}