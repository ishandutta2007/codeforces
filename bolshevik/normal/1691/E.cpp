#include<cstdio>
#include<algorithm>
#include<utility>
#include<set>
using namespace std;
const int o=1e5+10;
int T,n,R0[o],R1[o];pair<pair<int,int>,int> p[o];set<pair<int,int> > r[2];set<pair<int,int> >::iterator iter;
int main(){
	for(scanf("%d",&T);T--;printf("%llu\n",r[0].size()),r[0].clear(),r[1].clear()){
		scanf("%d",&n);
		for(int i=1;i<=n;++i) scanf("%d%d%d",&p[i].second,&p[i].first.first,&p[i].first.second);
		sort(p+1,p+n+1);
		for(int i=1,r0,r1;i<=n;++i){
			if(p[i].second) r1=p[i].first.second,r0=-1;
			else r0=p[i].first.second,r1=-1;
			for(int id;(iter=r[!p[i].second].lower_bound(make_pair(p[i].first.first,0)))!=r[!p[i].second].end();)
				r0=max(r0,R0[id=(*iter).second]),r1=max(r1,R1[id]),r[0].erase(make_pair(R0[id],id)),r[1].erase(make_pair(R1[id],id));
			r[0].insert(make_pair(R0[i]=r0,i));r[1].insert(make_pair(R1[i]=r1,i));
		}
	}
	return 0;
}