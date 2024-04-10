#include<bits/stdc++.h>
using namespace std;
const int N=5+2e5;
typedef long long ll;
struct K{ int a,b; };
bool cmpa(K x,K y){ return x.a<y.a; }
bool cmpb(K x,K y){ return x.b<y.b; }
ll solve1(vector<K> x,vector<K> y){
	sort(x.begin(),x.end(),cmpa);
	sort(y.begin(),y.end(),cmpb);
	int j=0,ret=0; multiset<int> s;
	for(int i=0;i<x.size();++i){
		for(;j<y.size()&&y[j].b<=x[i].a;++j) s.insert(y[j].a);
		if(s.lower_bound(x[i].b)!=s.end()) ret=max(ret,2*(x[i].b-x[i].a));
		auto it=s.upper_bound(x[i].b);
		if(it!=s.begin()&&*prev(it)>=x[i].a)
			ret=max(ret,2*(*prev(it)-x[i].a));
	}
	return ret;
}
int main(){
	int n; scanf("%d",&n);
	ll ans=0,ret=0;
	vector<K> x,y,z(n);
	for(int i=0;i<n;++i) scanf("%d",&z[i].a);
	for(int i=0;i<n;++i) scanf("%d",&z[i].b);
	for(int i=0;i<n;++i){
		if(z[i].a<z[i].b) x.push_back(z[i]);
		else if(z[i].a>z[i].b) y.push_back(z[i]);
		ans+=abs(z[i].a-z[i].b);
	}
	ret=max(ret,solve1(x,y));
	swap(x,y);
	for(int i=0;i<x.size();++i) swap(x[i].a,x[i].b);
	for(int i=0;i<y.size();++i) swap(y[i].a,y[i].b);
	ret=max(ret,solve1(x,y));
	printf("%lld\n",ans-ret);
	return 0;
}