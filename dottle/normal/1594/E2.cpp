#include <bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7,N=700005;
map<string,int>mp;
vector<int>id,sn[N];
string st;
int color[6][4]={{1,2,4,5},{0,2,3,5},{0,1,3,4},{1,2,4,5},{0,2,3,5},{0,1,3,4}};
int n,k,S,x,c[N],dp[N][6],cnt;
map<int,int>vis,col;

int gsc(int x,int y){
    int ans=1;
    for(int i=1;i<=y;i<<=1,x=x*x%mod)
        if(y&i)
            ans=ans*x%mod;
    return ans;
}int inv(int k){return gsc(k,mod-2);}
int solve(int i,int j){
    if(c[i]!=-1&&c[i]!=j)return 0;
    if(~dp[i][j])return dp[i][j];
    int ans=0,sum[2]={};
    for(auto x:color[j])
        for(int j=0;j<sn[i].size();j++)
            sum[j]+=solve(sn[i][j],x);
    if(sn[i].empty())sum[0]=sum[1]=1;
    if(sn[i].size()==1)sum[1]=1;
    return dp[i][j]=(sum[0]%mod*(sum[1]%mod))%mod;
}
main(){
    ios::sync_with_stdio(0);
    mp["white"]=0,mp["blue"]=1,mp["red"]=2,mp["yellow"]=3,mp["green"]=4,mp["orange"]=5;
    memset(dp,-1,sizeof(dp));
    memset(c,-1,sizeof(c));
    cin>>k>>n;
    int S=(1ll<<k)-1;
    int s=0;
    for(int i=1;i<=n;i++){
        cin>>x>>st;
        col[x]=mp[st]+1;
        int nw=x;
        while(nw>=1&&!vis[nw])
            vis[nw]=++cnt,--S,++s,id.push_back(nw),nw>>=1;
    }
    sort(id.begin(),id.end());
    for(int i=0;i<id.size();i++)
    	vis[id[i]]=i+1;
    for(int i=0;i<id.size();i++){
    	if(col[id[i]])
			c[i+1]=col[id[i]]-1;
    	if(vis[id[i]<<1])
			sn[i+1].push_back(vis[id[i]<<1]);
    	if(vis[id[i]<<1|1])
			sn[i+1].push_back(vis[id[i]<<1|1]);
	}
	int ans=0;
    for(int i=0;i<6;i++)
        ans+=solve(1,i);
    cout<<ans%mod*gsc(4,S)%mod<<endl;
}