#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll MOD=998244353;
const int MAX_N=5+1e6;
ll fast_pow(ll x,ll p){
	ll ret=1;
	for(ll pow=1;pow<=p;pow<<=1,x=(x*x)%MOD)
		if(p&pow) ret=(ret*x)%MOD;
	return ret;
}
ll inv(ll x){
	return fast_pow(x,MOD-2);
}
vector<int> data;
vector<pair<int,int> > a[MAX_N];
int g[1005][1005];
ll qsumx=0,sumx=0,sz=0,qsumy=0,sumy=0;
ll d[1005][1005],anssum=0;
int main(){
	int n,m; scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j){
			scanf("%d",&g[i][j]);
			data.push_back(g[i][j]);
		}
	sort(data.begin(),data.end());
	data.erase(unique(data.begin(),data.end()),data.end());
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j){
			g[i][j]=lower_bound(data.begin(),data.end(),g[i][j])-data.begin()+1;
			a[g[i][j]].push_back(make_pair(i,j));
		}
	for(int i=1;i<=(int)data.size();++i){
		ll key=inv(sz);
		for(int j=0;j<(int)a[i].size();++j){
			d[a[i][j].first][a[i][j].second]=(a[i][j].first*a[i][j].first%MOD*sz+qsumx-2*a[i][j].first*sumx+a[i][j].second*a[i][j].second%MOD*sz+qsumy-2*a[i][j].second*sumy+anssum)%MOD*key%MOD;
		}
		sz+=a[i].size();
		for(int j=0;j<(int)a[i].size();++j){
			sumx=(sumx+a[i][j].first)%MOD;
			qsumx=(qsumx+a[i][j].first*a[i][j].first)%MOD;
			sumy=(sumy+a[i][j].second)%MOD;
			qsumy=(qsumy+a[i][j].second*a[i][j].second)%MOD;
			anssum=(anssum+d[a[i][j].first][a[i][j].second])%MOD;
		}
	}
	int x,y; scanf("%d%d",&x,&y);
	printf("%lld",(d[x][y]+MOD)%MOD);
	return 0;
}