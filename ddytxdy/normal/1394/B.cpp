#include<bits/stdc++.h>
#define LL long long
#define pii pair<int,int>
#define pb push_back
#define mp make_pair
using namespace std;
const int N=2e5+50,K=12;
int n,m,k,ans,tp,a[K];bool ban[K][K][K][K],in[N][K][K],B[K][K];
vector<pii>bban[K][K];
vector<pii>v[N],v2[N];
pii st[N];
void dfs(int x){
	int tt=tp;
	if(x>k){ans++;return;}
	for(int i=1;i<=x;i++){
		if(!B[x][i]&&!ban[x][i][x][i]){
			a[x]=i;
			for(int j=0;j<bban[x][i].size();j++){
				int xx=bban[x][i][j].first,yy=bban[x][i][j].second;
				if(!B[xx][yy])st[++tp]=mp(xx,yy),B[xx][yy]=1;
			}
			dfs(x+1);
			while(tp>tt){
				int xx=st[tp].first,yy=st[tp].second;
				B[xx][yy]=0;tp--;
			}
		}
	}
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,x,y,z;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		v[x].pb(mp(z,y));
		// v2[y].pb(mp(z,x));
	}
	for(int i=1;i<=n;i++)sort(v[i].begin(),v[i].end());
	for(int i=1;i<=n;i++){
		int sz=v[i].size();
		for(int j=0;j<sz;j++){
			int y=v[i][j].second,p=j+1;//cout<<1;
			if(in[y][sz][p]){ban[sz][p][sz][p]=1;continue;}//cout<<y<<" ";
			for(int k=0;k<v2[y].size();k++){//cout<<y<<" "<<k<<" "<<v2[y].size()<<endl;
				int x=v2[y][k].first,z=v2[y][k].second;//cout<<x<<" "<<y<<endl;
				if(!ban[sz][p][x][z])ban[sz][p][x][z]=1,bban[sz][p].pb(mp(x,z));
				if(!ban[x][z][sz][p])ban[x][z][sz][p]=1,bban[x][z].pb(mp(sz,p));
			}
			v2[y].pb(mp(sz,p)),in[y][sz][p]=1;
		}
	}//cout<<1;
	dfs(1);cout<<ans;
	return 0;
}
// 5 2 11
// 8 10 11 11 5