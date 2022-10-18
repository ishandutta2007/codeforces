#include<bits/stdc++.h>

using namespace std;

const int MX=2005;
int n,m,ans[MX],h[MX];
bitset<MX>A[MX];
vector<int>G[MX];

bool ck1(){
	for(int i=1;i<=n;i++)if(G[i].size()&1)return false;
	return true;
}
void solve(){
	int it=1;
	for(int i=1;i<=n;i++){
		int j;
		for(j=it;j<=n;j++){if(A[j][i])break;}
		if(j>n)continue;
		if(j>it)swap(A[j],A[it]);
		h[it]=i;
		for(j=it+1;j<=n;j++)if(A[j][i])A[j]^=A[it];
		it++;
	}
	int lst=n+1;
	for(int i=it-1;i;i--){
		for(int j=h[i]+1;j<lst;j++)ans[j]=0;
		ans[h[i]]=A[i][0];
		for(int j=1;j<i;j++)if(A[j][h[i]])A[j]^=A[i];
		lst=h[i];
	}
	for(int i=1;i<lst;i++)ans[i]=0;
}
int main(){
	ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++)G[i].clear();
		for(int i=1;i<=m;i++){
			int x,y;
			cin>>x>>y;
			G[x].push_back(y),G[y].push_back(x);
		}
		if(ck1()){cout<<1<<endl;for(int i=1;i<=n;i++)cout<<"1 ";cout<<endl;continue;}
		for(int i=1;i<=n;i++){
			A[i]=0;
			for(auto j:G[i]){
				A[i].set(j);
			}
			if(G[i].size()&1){
				A[i].set(i);
				A[i].set(0);
			}
		}
		memset(ans+1,0,sizeof(int)*n);
		solve();
		cout<<2<<endl;
		for(int i=1;i<=n;i++)cout<<(ans[i]+1)<<' ';cout<<endl;
	}
	return 0;
}