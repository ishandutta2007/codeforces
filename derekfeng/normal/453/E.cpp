#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define fi first
#define se second
#define IT set<Node>::iterator
pll operator +(const pll &A,const pll &B){return {A.fi+B.fi,A.se+B.se};}
int n,q,s[100004],m[100004],c[100004];
struct segmentree{
	vector<int>all;
	pll dat[2000004];
	int tot,rt[100004],son[2][2000004];
	int built(int l,int r){
		int id=++tot;
		if(l==r)dat[id]={s[l],c[l]};
		else{
			int mid=(l+r)>>1;
			son[0][id]=built(l,mid);
			son[1][id]=built(mid+1,r);
			dat[id]=dat[son[0][id]]+dat[son[1][id]];
		}
		return id;
	}
	int ins(int id,int l,int r,int p,pll x){
		int idd=++tot;
		dat[idd]=dat[id]+x;
		if(l!=r){
			int mid=(l+r)>>1;
			son[0][idd]=son[0][id],son[1][idd]=son[1][id];
			if(p<=mid)son[0][idd]=ins(son[0][id],l,mid,p,x);
			else son[1][idd]=ins(son[1][id],mid+1,r,p,x);
		}
		return idd;
	}
	pll qry(int id,int l,int r,int a,int b){
		if(r<a||b<l)return {0,0};
		if(a<=l&&r<=b)return dat[id];
		int mid=(l+r)>>1;
		return qry(son[0][id],l,mid,a,b)+qry(son[1][id],mid+1,r,a,b);
	}
	void init(){
		vector<pii>qr;
		tot=0;
		all.clear();all.push_back(0),all.push_back(1e9);
		for(int i=1;i<=n;i++)
			if(c[i]!=0){
				int tms=(m[i]-s[i]+c[i]-1)/c[i];
				all.push_back(tms),qr.push_back({tms,i});
			}
		sort(all.begin(),all.end()),all.erase(unique(all.begin(),all.end()),all.end());
		sort(qr.begin(),qr.end());
		rt[0]=built(1,n);
		for(int i=0,j=0;i<all.size()-1;i++){
			if(i)rt[i]=rt[i-1];
			while(j<qr.size()&&qr[j].fi<all[i+1]){
				int id=qr[j].se;
				rt[i]=ins(rt[i],1,n,id,{m[id]-s[id],-c[id]});
				j++;
			}
		}
	}
	ll ask(int t,int l,int r){
		int ver=lower_bound(all.begin(),all.end(),t+1)-all.begin()-1;
		pll tmp=qry(rt[ver],1,n,l,r);
		return tmp.fi+tmp.se*t;
	}
}T0,T1;
struct Node{
	int l,r;
	mutable int v;
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
void assignnode(int l,int r,int x){
	IT it1=split(l),it2=split(r+1);
	st.erase(it1,it2);
	st.insert(Node(l,r,x));
}
ll sum(int l,int r,int t){
	IT it2=split(r+1),it1=split(l);
	ll ret=0;
	for(;it1!=it2;it1++){
		int L=it1->l,R=it1->r,T=it1->v;
		if(T<0)ret+=T0.ask(t,L,R);
		else ret+=T1.ask(t-T,L,R);
	}
	return ret;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d%d",&s[i],&m[i],&c[i]);
	T0.init();
	memset(s,0,sizeof(s));
	T1.init();
	st.insert(Node(1,n,-1));
	scanf("%d",&q);
	while(q--){
		int t,l,r;scanf("%d%d%d",&t,&l,&r);
		printf("%I64d\n",sum(l,r,t));
		assignnode(l,r,t);
	}
}