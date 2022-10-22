#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mkp make_pair
int n,m,s,d,a[200004];
int f[200004];
set<pii>stone,edge;
void solve(int L,int R,int val){
	while(1){
		auto it=stone.lower_bound(mkp(L,0));
		if(it==stone.end()||(*it).fi>R)break;
		pii x=*it;stone.erase(it);
		f[x.se]=val,edge.insert(mkp(val,x.se));
	}
}
int getnxt(int L,int R,int x){
	int res=1e6;
	auto it=stone.lower_bound(mkp(L,0));
	if(it!=stone.begin()){
		it--,res=min(res,abs(abs((*it).fi-x)-d));
		++it;
	}
	if(it!=stone.end())res=min(res,abs(abs((*it).fi-x)-d));
	return res;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&s,&d);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)stone.insert(mkp(a[i],i));stone.erase(mkp(a[s],s));
	edge.insert(mkp(0,s));
	while(!stone.empty()){
		pii st=*edge.begin();edge.erase(edge.begin());
		int L=d-st.fi,R=d+st.fi;
		solve(a[st.se]-R,a[st.se]-L,st.fi),solve(a[st.se]+L,a[st.se]+R,st.fi);
		int val=min(getnxt(a[st.se]-R,a[st.se]-L,a[st.se]),getnxt(a[st.se]+L,a[st.se]+R,a[st.se]));
		edge.insert(mkp(val,st.se));
	}
	while(m--){
		int x,i;scanf("%d%d",&i,&x);
		if(x>=f[i])puts("YES");
		else puts("NO");
	}
}