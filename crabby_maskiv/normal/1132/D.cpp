#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=200005;
const ll inf=0x3f3f3f3fll;
int n,m;
struct node{
	int id;ll ti,k;
	bool operator <(const node &b)const
	{
		return ti==b.ti?k>b.k:ti>b.ti;
	}
};
ll a[N],b[N];
vector<pair<ll,int> > v[N];
bool check(ll key){
	int i;
	for(i=0;i<m;i++) v[i].clear();
	for(i=1;i<=n;i++){
		if(a[i]/b[i]>=m) continue;
		v[a[i]/b[i]].push_back({a[i]%b[i],i});
	}
	int pos=0;
	for(i=0;i<m;i++){
		while(!v[pos].size()&&pos<m) pos++;
		if(pos==m) return 1;
		if(pos<i) return 0;
		pair<ll,int> p=v[pos].back();
		p.first+=key;
		ll ti=pos+p.first/b[p.second];
		p.first%=b[p.second];
		v[pos].pop_back();
		if(ti<m) v[ti].push_back(p);
	}
	return 1;
}
int main(){
	int i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(i=1;i<=n;i++) scanf("%lld",&b[i]);
	ll l=0,r=2e12;
	if(!check(r)){
		cout<<-1;
		return 0;
	}
	while(r>l){
		ll mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	cout<<l;
	return 0;
}