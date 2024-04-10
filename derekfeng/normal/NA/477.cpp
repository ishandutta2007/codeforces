#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define IT set<Node>::iterator
#define fi first
#define se second
const int MOD=1e9+7;
struct Node{
	int l,r;
	mutable ll v;
	Node(int l,int r=-1,ll v=0):l(l),r(r),v(v){} 
	bool operator < (const Node& o) const{return l<o.l;}
};
set<Node>st;
IT split(int pos){
	IT it=st.lower_bound(Node(pos));
	if(it!=st.end()&&it->l==pos)return it;
	--it;
	if(it->r<pos)return st.end();
	int L=it->l,R=it->r;
	ll V=it->v;
	st.erase(it);
	st.insert(Node(L,pos-1,V));
	return st.insert(Node(pos,R,V)).fi;
}
void add(int l,int r,int x){
	IT it1=split(l),it2=split(r+1);
	for(;it1!=it2;it1++)it1->v+=x;
}
void assignnode(int l,int r,int x){
	IT it1=split(l),it2=split(r+1);
	st.erase(it1,it2);
	st.insert(Node(l,r,x));
}
ll kth(int l,int r,int k){
	vector<pair<ll,int> >num;
	IT it1=split(l),it2=split(r+1);
	for(;it1!=it2;it1++)num.push_back(make_pair(it1->v,it1->r-it1->l+1));
	sort(num.begin(),num.end());
	for(int i=0;i<num.size();i++){
		k-=num[i].se;
		if(k<=0)return num[i].fi;
	}
}
ll mypow(ll x,int t,int y){
	x%=y;
	ll ans=1,ret=x;
	while(t){
		if(t&1)ans=ans*ret%y;
		t>>=1,ret=ret*ret%y;
	}
	return ans;
}
ll sum(int l,int r,int x,ll y){
	IT it1=split(l),it2=split(r+1);
	ll ret=0;
	for(;it1!=it2;it1++)
		ret=(ret+mypow(it1->v,x,y)*(it1->r-it1->l+1))%y;
	return ret;
}
int n,m,seed,vmax,opt,l,r,x,y;
inline int rnd(){int ret=seed;seed=(1ll*seed*7+13)%MOD;return ret;}
int main(){
	scanf("%d%d%d%d",&n,&m,&seed,&vmax);
	for(int i=0;i<n;i++)st.insert(Node(i,i,rnd()%vmax+1));
	while(m--){
		opt=rnd()%4,l=rnd()%n,r=rnd()%n;
		if(r<l)swap(l,r);
		if(opt<1){
			x=rnd()%vmax+1;
			add(l,r,x);
		}else if(opt<2){
			x=rnd()%vmax+1;
			assignnode(l,r,x);
		}else if(opt<3){
			x=rnd()%(r-l+1)+1;
			printf("%I64d\n",kth(l,r,x));
		}else{
			x=rnd()%vmax+1,y=rnd()%vmax+1;
			printf("%d\n",sum(l,r,x,y));
		}
	}
}