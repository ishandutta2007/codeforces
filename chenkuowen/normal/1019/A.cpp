#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll INF=1e18;
const int MAX_N=3005;
vector<int> a[MAX_N],b,p;
int main(){
	int n,m; scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i){
		int p,key; scanf("%d%d",&p,&key);
		a[p].push_back(key);
		if(p!=1) b.push_back(key);
	} 
	for(int i=1;i<=m;++i) sort(a[i].begin(),a[i].end());
	sort(b.begin(),b.end());
	ll ans=INF;
	for(int num=1;num<=n;++num){
		ll ret=0,cnt=a[1].size();
		p.clear();
		for(int i=2;i<=m;++i)
			if(a[i].size()>=num){
				for(int j=0;j<a[i].size()-num+1;++j)
					++cnt,ret+=a[i][j],p.push_back(a[i][j]);
			}
		sort(p.begin(),p.end());
		int poi=0;
		for(int i=0;cnt<num;++i)
			if(poi<p.size()&&p[poi]==b[i]) ++poi;
			else ++cnt,ret+=b[i];
		ans=min(ans,ret);
	}
	printf("%I64d\n",ans);
	return 0;
}