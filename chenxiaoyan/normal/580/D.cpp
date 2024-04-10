#include<bits/stdc++.h>
using namespace std;
#define int long long
#define X first
#define Y second
#define mp make_pair
#define pb push_back
int n,m,a[19],f[19][1<<20],mx;
bitset<1<<20> vis[19];
vector<pair<int,int> > add[19];
int dp(int fst,int stt){
	if(vis[fst][stt])return f[fst][stt];
	vis[fst].set(stt);
	int i;
	if(!fst){
		for(i=1;i<=n;i++)if(stt&(1<<i)){
			f[fst][stt]=max(f[fst][stt],dp(0,stt^(1<<i))+a[i]);
			if(add[i].size())
				for(int j=0;j<add[i].size();j++){
					int x=add[i][j].X;
					if(stt&(1<<x))
						f[fst][stt]=max(f[fst][stt],dp(x,stt^(1<<i))+a[i]+add[i][j].Y);
				}
		}
	}
	else{
		f[fst][stt]=max(f[fst][stt],dp(0,stt^(1<<fst))+a[fst]);
		if(add[fst].size())
			for(i=0;i<add[fst].size();i++){
				int x=add[fst][i].X;
				if(stt&(1<<x))
					f[fst][stt]=max(f[fst][stt],dp(x,stt^(1<<fst))+a[fst]+add[fst][i].Y);
			}
	}
	return f[fst][stt];
}
void dfs(int x=1,int now=0,int prv=0){
	if(x==m+1){mx=max(mx,dp(0,now));/*cout<<now<<" "<<dp(fst,now)<<"\n";*/return;}
	for(int i=prv+1;i<=n;i++)dfs(x+1,now|(1<<i),i);
}
signed main(){
	int K;scanf("%lld%lld%lld",&n,&m,&K);
	for(int i=1;i<=n;i++)scanf("%lld",a+i);
	while(K--){
		int x,y,z;scanf("%lld%lld%lld",&x,&y,&z);
		add[y].pb(mp(x,z));
	}
	dfs();
	printf("%lld",mx);
	return 0;
}
/*1
2 2 1
1 1
2 1 1
*/
/*2
4 3 2
1 2 3 4
2 1 5
3 4 2
*/
/*3
5 5 5
3 3 3 3 3
3 4 6
4 1 2
1 5 7
5 2 4
2 3 5
*/