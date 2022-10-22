#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mkp make_pair
typedef long long ll;
vector<int>all;
vector<pii>qry;
int n,m,N,a[200004];
ll f[200004][2];
vector<pii>z[200004];
bool flg;
void sol(){
	scanf("%d%d",&n,&m);
	all.clear(),qry.clear();
	for(int i=0;i<n;i++){
		int x;scanf("%d",&x);
		all.push_back(x);
	}
	sort(all.begin(),all.end());
	for(auto x:all)qry.push_back(mkp(x,1e9+1));
	for(int i=0;i<m;i++){
		int l,r;scanf("%d%d",&l,&r);
		int p=lower_bound(all.begin(),all.end(),l)-all.begin();
		if(p<all.size()&&all[p]<=r)continue;
		qry.push_back(mkp(l,r));
	}
	sort(qry.begin(),qry.end());
	flg=0;for(int i=0;i<N;i++)z[i].clear();N=0;
	for(int i=0,j;i<qry.size();){
		j=i;
		while(j<qry.size()&&qry[j].se<=1e9){
			z[N].push_back(qry[j]);
			j++;
		}
		if(j==qry.size())flg=1;
		else a[N]=qry[j].fi;
		N++;
		i=j+1;
	}
	if(z[0].empty())f[0][0]=f[0][1]=0;
	else{
		vector<int>r;
		for(auto x:z[0])r.push_back(x.se);
		sort(r.begin(),r.end());
		f[0][0]=a[0]-r[0],f[0][1]=f[0][0]*2;
	}
	for(int i=1;i<N-flg;i++){
		if(z[i].empty()){
			f[i][0]=f[i][1]=min(f[i-1][0],f[i-1][1]);
			continue;
		}
		vector<int>l,d;d.resize(z[i].size()+1,a[i]);
		for(auto x:z[i])l.push_back(x.fi);
		sort(l.begin(),l.end());
		for(auto x:z[i]){
			int p=lower_bound(l.begin(),l.end(),x.fi)-l.begin();
			d[p]=min(d[p],x.se);
		}
		for(int j=z[i].size()-1;j>=0;j--)d[j]=min(d[j],d[j+1]);
		f[i][0]=f[i][1]=1e18;
		for(int j=0;j<=z[i].size();j++){
			ll tmp;
			if(j>0)tmp=l[j-1]-a[i-1];
			else tmp=0;
			ll tmp1=min(f[i-1][1]+tmp,f[i-1][0]+tmp*2);
			ll pmt;
			if(j<z[i].size())pmt=a[i]-d[j];
			else pmt=0;
			f[i][0]=min(f[i][0],tmp1+pmt),f[i][1]=min(f[i][1],tmp1+pmt*2);
		}
	}
	ll ans=1e18;
	if(flg){
		vector<int>l;
		for(auto x:z[N-1])l.push_back(x.fi);
		sort(l.begin(),l.end());
		ll tmp=l.back()-a[N-2];
		ans=min(f[N-2][0]+tmp*2,f[N-2][1]+tmp);
	}else ans=min(f[N-1][0],f[N-1][1]);
	printf("%lld\n",ans);
}
int main(){
	int TC;scanf("%d",&TC);
	while(TC--)sol();
}