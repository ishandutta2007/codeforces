#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define fi first
#define se second
int n,n_=1,pos[524300],lst[200004];
int tot,s[2][10000000];
ll rsum[10000000],sum[10000000],dat[10000000],lastans;
pii tag[10000000];
int LD[200004],RD[200004],TM[200004];
set<pair<int,pii> >st[200004],ts[200004];
struct segtree1{
	void upd(int i,int x){
		i+=n_,pos[i]=x;
		while(i!=1)i>>=1,pos[i]=min(pos[i<<1],pos[i<<1|1]);
	}
	int bs(int l,int r,int i,int w){
		if(l==r)return l;
		int mid=(l+r)>>1;
		if(pos[i<<1]<w)return bs(l,mid,i<<1,w);
		return bs(mid+1,r,i<<1|1,w);
	}
}tr1;
struct segtree2{
	int rt,C;
	segtree2(){rt=0;}
	int ins(int l,int r,int i,int a,int b,int L,int R){
		if(r<a||b<l)return i;
		int id=i;if(!i)id=++tot;
		if(a<=l&&r<=b){
			int len=(r-l+1);
			dat[id]=len;
			sum[id]=(ll)(R-L+1)*len;
			rsum[id]=(ll)R*len;
			tag[id].fi=R-L+1,tag[id].se=R;
			return id;
		}
		int mid=(l+r)>>1;
		s[0][id]=ins(l,mid,s[0][id],a,b,L,R);
		s[1][id]=ins(mid+1,r,s[1][id],a,b,L,R);
		rsum[id]=rsum[s[0][id]]+rsum[s[1][id]];
		sum[id]=sum[s[0][id]]+sum[s[1][id]];
		dat[id]=dat[s[0][id]]+dat[s[1][id]];
		return id;
	}
	pair<int,pll>qry(int l,int r,int i,int a,int b,pii tg){
		if(r<a||b<l)return{0,{0,0}};
		if(tg.fi!=0){
			int L=max(l,a),R=min(b,r);
			if(L<=R){
				int len=R-L+1;
				return {len,{(ll)len*tg.fi,(ll)len*tg.se}};
			}
		}
		if(!i)return{0,{0,0}};
		if(a<=l&&r<=b)return{dat[i],{sum[i],rsum[i]}};
		int mid=(l+r)>>1;
		pair<int,pll>vl=qry(l,mid,s[0][i],a,b,tag[i]);
		pair<int,pll>vr=qry(mid+1,r,s[1][i],a,b,tag[i]);
		return {vl.fi+vr.fi,{vl.se.fi+vr.se.fi,vl.se.se+vr.se.se}};
	}
	void push(int t){
		if(LD[C]!=0){
			if(TM[C]<=t){
				rt=ins(1,n,rt,TM[C],t,LD[C],RD[C]);
				st[C].insert({LD[C],{TM[C],t}}),ts[C].insert({RD[C],{TM[C],t}});
				TM[C]=t+1;
			}
		}
	}
	void add(int L,int R,int t){
		LD[C]=L,RD[C]=R,TM[C]=t;
	}
	void erase(int L,int R,int a,int b){
		if(a<=b)rt=ins(1,n,rt,a,b,L,R),st[C].insert({L,{a,b}}),ts[C].insert({R,{a,b}});
		LD[C]=RD[C]=TM[C]=0;
	}
	pair<int,pll>ask(int a,int b){
		return qry(1,n,rt,a,b,{0,0});
	}
}tr2[200004];
set<pair<pii,int> >seg;
void upd(int p,int a){
	tr1.upd(a,p),lst[a]=p;
	if(LD[a]!=0){
		int l=LD[a],r=RD[a];
		seg.erase({{l,r},a});
		tr2[a].erase(l,r,TM[a],p-1);
		vector<pair<pii,int> >v;
		while(r>=l){
			int z=tr1.bs(0,n_-1,1,r);
			v.push_back({{max(lst[z]+1,l),r},z});
			r=lst[z];
		}
		reverse(v.begin(),v.end());
		auto it=seg.lower_bound(v[0]);
		if(it!=seg.begin()){
			--it;
			if((*it).se==v[0].se){
				pair<pii,int>tmp=(*it);seg.erase(it);
				tr2[tmp.se].erase(tmp.fi.fi,tmp.fi.se,TM[tmp.se],p-1); 
				v[0].fi.fi=tmp.fi.fi;
			}
		}
		it=seg.lower_bound(v.back());
		if(it!=seg.end()){
			if((*it).se==v.back().se){
				pair<pii,int>tmp=(*it);seg.erase(it);
				tr2[tmp.se].erase(tmp.fi.fi,tmp.fi.se,TM[tmp.se],p-1);
				v.back().se=tmp.fi.se;
			}
		}
		for(auto x:v)tr2[x.se].add(x.fi.fi,x.fi.se,p),seg.insert(x);
	}
	int val=(a==0?1:0),L=p,R=p;
	if(!seg.empty()){
		auto it=seg.end();--it;
		if((*it).se==val){
			pair<pii,int>tmp=(*it);seg.erase(it);
			tr2[tmp.se].erase(tmp.fi.fi,tmp.fi.se,TM[tmp.se],p-1);
			L=tmp.fi.fi;
		}
	}
	seg.insert({{L,R},val});
	tr2[val].add(L,R,p);
}
void calc(int L,int R,int k,int t){
	tr2[k].push(t);
	auto it=st[k].lower_bound({L,{0,0}});
	ll ans=0;
	if(it!=st[k].end()){
		int lev=(*it).se.fi;
		pair<int,pll>vr={0,{0,0}};
		if(lev<=R)vr=tr2[k].ask(lev,R),R=lev-1;
		ans=vr.se.fi;
	}
	if(L<=R){
		it=ts[k].lower_bound({L,{0,0}});
		if(it!=ts[k].end()){
			int lev=(*it).se.fi;
			pair<int,pll>vl={0,{0,0}};
			if(lev<=R)vl=tr2[k].ask(lev,R);
			ans+=vl.se.se-(ll)vl.fi*(L-1);
		}
	}
	lastans=ans;
	printf("%lld\n",ans);
}
int main(){
	scanf("%d",&n);while(n_<n+1)n_<<=1;
	for(int i=0;i<=n;i++)tr2[i].C=i;
	for(int i=1;i<=n;i++){
		int a,L,R,k;scanf("%d%d%d%d",&a,&L,&R,&k);
		a=(lastans+a)%(n+1),L=(lastans+L)%i+1,R=(lastans+R)%i+1,k=(lastans+k)%(n+1);if(L>R)swap(L,R);
		upd(i,a);
		calc(L,R,k,i);
	}
}