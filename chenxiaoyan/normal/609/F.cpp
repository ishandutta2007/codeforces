#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define X first
#define Y second
const int inf=0x3f3f3f3f3f3f3f3fll;
set<pair<pair<int,int>,int> >::iterator operator-(set<pair<pair<int,int>,int> >::iterator x,int y){return --x;}
const int N=200000,M=200000;
int n,m;
int a[N+1],b[N+1],ans[N+1];
pair<pair<int,int>,int> p[N+1];
bool cmp(pair<pair<int,int>,int> x,pair<pair<int,int>,int> y){
	if(x.X.X!=y.X.X)return x.X.X<y.X.X;
	return x.X.Y>y.X.Y;
}
struct cmp0{
	bool operator()(pair<pair<int,int>,int> x,pair<pair<int,int>,int> y){
		if(x.X.Y!=y.X.Y)return x.X.Y<y.X.Y;
		return x.X.X>y.X.X;
	}
};
set<pair<pair<int,int>,int>,cmp0> st;
multiset<pair<int,int> > mos;
void eat(set<pair<pair<int,int>,int> >::iterator &fd,int d){
	ans[fd->Y]++;b[fd->Y]+=d;
	pair<pair<int,int>,int> nw=mp(mp(a[fd->Y],a[fd->Y]+b[fd->Y]),fd->Y);
	st.erase(fd);st.insert(nw);
	fd=st.find(nw);
	if(fd!=st.begin())
		for(set<pair<pair<int,int>,int> >::iterator i=fd-1;;)
			if(i==st.begin()){
				if(fd->X.X<i->X.X)st.erase(i);
				break;
			}
			else
				if(fd->X.X<i->X.X)st.erase(i--);
				else break;
}
signed main(){
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld%lld",a+i,b+i),p[i]=mp(mp(a[i],a[i]+b[i]),i);
	sort(p+1,p+n+1,cmp);
	vector<int> v;
	for(int i=1;i<=n;i++)if(v.empty()||p[v.back()].X.Y<p[i].X.Y)v.pb(i);
	for(int i=0;i<v.size();i++)st.insert(p[v[i]]);
	while(m--){
		int c,d;
		scanf("%lld%lld",&c,&d);
		set<pair<pair<int,int>,int> >::iterator fd=st.lower_bound(mp(mp(inf,c),0));
		if(fd==st.end()||fd->X.X>c){mos.insert(mp(c,d));continue;}
		eat(fd,d);
		while(mos.size()){
			set<pair<int,int> >::iterator fd0=mos.lower_bound(mp(fd->X.X,0));
			if(fd0==mos.end()||fd0->X>fd->X.Y)break;
			eat(fd,fd0->Y);
			mos.erase(fd0);
		}
	}
	for(int i=1;i<=n;i++)printf("%lld %lld\n",ans[i],b[i]);
	return 0;
}
/*1
4 6
10 2
15 0
6 1
0 1
110 10
1 1
6 0
15 10
14 100
12 2
*/
/*2
1 2
10 2
20 2
12 1
*/