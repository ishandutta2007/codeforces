#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
const int N=100000;
int n,m;
vector<int> nei[N+1];
const int hbase1=1000000007,hmod1=998244353,hbase2=1000000009,hmod2=1000000007;
pair<int,int> mkhsh(int x){
	int now1=1,now2=1,res1=0,res2=0;
	for(int i=0;i<nei[x].size();i++)(res1+=1ll*nei[x][i]*now1%hmod1)%=hmod1,now1=1ll*now1*hbase1%hmod1;
	for(int i=0;i<nei[x].size();i++)(res2+=1ll*nei[x][i]*now2%hmod2)%=hmod2,now2=1ll*now2*hbase2%hmod2;
	return mp(res1,res2);
}
vector<pair<int,int> > hshs;
vector<int> part[3];
int belong[N+1];
int main(){
	cin>>n>>m;
	while(m--){
		int x,y;
		cin>>x>>y;
		nei[x].pb(y);nei[y].pb(x);
	}
	for(int i=1;i<=n;i++){
		sort(nei[i].begin(),nei[i].end());
		hshs.pb(mkhsh(i));
	}
	sort(hshs.begin(),hshs.end());
	hshs.resize(unique(hshs.begin(),hshs.end())-hshs.begin());
	if(hshs.size()!=3)return puts("-1"),0;
	for(int i=1;i<=n;i++){
		pair<int,int> h=mkhsh(i);
		for(int j=0;j<3;j++)if(h==hshs[j])part[j].pb(i),belong[i]=j;
	}
	for(int i=0;i<3;i++){
		vector<int> v=nei[part[i][0]];
		for(int j=0;j<part[i].size();j++)v.pb(part[i][j]);
		sort(v.begin(),v.end());
		v.resize(unique(v.begin(),v.end())-v.begin());
		if(v.size()!=n)return puts("-1"),0;
	}
	for(int i=1;i<=n;i++)cout<<belong[i]+1<<" ";
	return 0;
}
/*1
6 11
1 2
1 3
1 4
1 5
1 6
2 4
2 5
2 6
3 4
3 5
3 6
*/
/*2
4 6
1 2
1 3
1 4
2 3
2 4
3 4
*/