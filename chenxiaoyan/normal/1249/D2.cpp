/*




D P 




 l l
*/
#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define X first
#define Y second
#define pb push_back
const int L_I=200000;
int n,m;
struct segtree{
	struct node{int l,r,lz;}nd[L_I<<2];
	#define l(p) nd[p].l
	#define r(p) nd[p].r
	#define lz(p) nd[p].lz
	void bld(int l=1,int r=200000,int p=1){
		l(p)=l;r(p)=r;lz(p)=0;
		if(l==r)return;
		int mid=l+r>>1;
		bld(l,mid,p<<1);bld(mid+1,r,p<<1|1);
	}
	void init(){bld();}
	void sprdwn(int p){
		if(lz(p)){
			lz(p<<1)+=lz(p);lz(p<<1|1)+=lz(p);
			lz(p)=0;
		}
	}
	void add(int l,int r,int v,int p=1){
		if(l<=l(p)&&r>=r(p)){lz(p)+=v;return;}
		sprdwn(p);
		int mid=l(p)+r(p)>>1;
		if(l<=mid)add(l,r,v,p<<1);
		if(r>mid)add(l,r,v,p<<1|1);
	}
	int cnt(int x,int p=1){
		if(l(p)==r(p))return lz(p);
		sprdwn(p);
		int mid=l(p)+r(p)>>1;
		return cnt(x,p<<1|(x>mid));
	}
}segt;
multiset<pair<pair<int,int>,int> > p,p0;
int main(){
	cin>>n>>m;
	segt.init();
	for(int i=1;i<=n;i++){
		int l,r;
		cin>>l>>r;
		segt.add(l,r,1);
		p.insert(mp(mp(l,r),i));
	}
	set<pair<pair<int,int>,int> >::iterator it=p.begin();
	vector<int> ans;
	for(int i=1;i<=200000;i++){
		while(it!=p.end()&&it->X.X<=i)p0.insert(mp(mp(it->X.Y,it->X.X),it->Y)),it++;
		while(segt.cnt(i)>m){
			set<pair<pair<int,int>,int> >::iterator fd=--p0.end();
			segt.add(fd->X.Y,fd->X.X,-1);
			ans.pb(fd->Y);
			p0.erase(fd);
		}
	}
	cout<<ans.size()<<"\n";
	for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
	return 0;
}