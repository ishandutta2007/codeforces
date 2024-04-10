#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#define rep(i,n) for(int i=0;i<n;i++)
#define MP make_pair
using namespace std;
typedef pair<int,int> PII;
const int INF=1e9+7;
int num[100005];
vector<PII> qy[100005];
int ans[100005];
vector<PII> gcds;
map<int, vector<int> > occ;
int gcd(int u,int v){
	return v==0?u:gcd(v,u%v);
}
int main(){
	int n,q;
	scanf("%d",&n);
	rep(i,n)scanf("%d",&num[i]);
	scanf("%d",&q);
	rep(i,q){
		int l,r;
		scanf("%d%d",&l,&r);
		l--;r--;
		qy[r].push_back(MP(l,i));
	}
	rep(i,n){
		occ[num[i]].push_back(i);
		rep(j,gcds.size())gcds[j].second=gcd(gcds[j].second,num[i]);
		gcds.push_back(MP(i,num[i]));
		for(int j=1;j<gcds.size();j++)if(gcds[j].second==gcds[j-1].second)gcds[j]=gcds[j-1];
		gcds.resize(unique(gcds.begin(),gcds.end())-gcds.begin());
		rep(j,qy[i].size()){
			int cg=gcds[lower_bound(gcds.begin(),gcds.end(),MP(qy[i][j].first,INF))-gcds.begin()-1].second;
			ans[qy[i][j].second]=(i-qy[i][j].first+1)-(occ[cg].end()-lower_bound(occ[cg].begin(),occ[cg].end(),qy[i][j].first));
		}
	}
	rep(i,q)printf("%d\n",ans[i]);
	return 0;
}