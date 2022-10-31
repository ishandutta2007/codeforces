#include<bits/stdc++.h>
#define int long long
const int N=1000005;
using namespace std;

#define _to e[i].to
#define fore(k) for(int i=hd[k];i;i=e[i].nx)
struct edge{
    int to,nx;
}e[N];int hd[N],S,in[N];
void add(int fr,int to){
    e[++S]=(edge){to,hd[fr]},hd[fr]=S,in[to]++;
}

int n;
int dp[N];

void dfs(int k,int fa){
	dp[k]=dp[fa]+1;
	fore(k)if(_to!=fa)
		dfs(_to,k);
}

void solve(){
	cin>>n;
	for(int i=1;i<=n;i++)hd[i]=in[i]=0;S=0;
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		add(x,y),add(y,x);
	}
	dfs(1,0);
	cout<<in[1]<<' ';
	for(int i=2;i<=n;i++)
		if(dp[i]&1)cout<<in[i]<<' ';
		else cout<<-in[i]<<' ';cout<<endl;
}

main(){
	int _T=1;cin>>_T;
	while(_T--)solve();
}