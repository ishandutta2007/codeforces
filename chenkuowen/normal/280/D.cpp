#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5+1e5;
const ll INF=1e18;
pair<ll,pair<int,int> > merge1(pair<ll,int> x,pair<ll,int> y){
	return make_pair(x.first+y.first,make_pair(x.second,y.second));
}
pair<ll,int> operator+(pair<ll,int> x,ll k){
	x.first+=k; return x;
}
pair<ll,int> operator-(pair<ll,int> x,ll k){
	x.first-=k; return x;
}
struct K{
	pair<ll,int> ls0,ls1,rs0,rs1;
	pair<ll,pair<int,int> > ans;
	ll sum; int flag;
	K(){}
	K(int edge_type,ll ke,ll k0,ll k1,int pos){
		flag=edge_type;
		sum=ke;
		ls0=make_pair(edge_type==1?k0-ke:INF,pos);
		ls1=make_pair(edge_type==0?k1+ke:INF,pos);
		rs0=make_pair(k0,pos);
		rs1=make_pair(k1,pos);
		ans=merge1(rs0,rs1);
	}
};
K merge(K x,K y){
	K z;
	z.ans=min({x.ans,y.ans,merge1(x.rs0,y.ls1),merge1(y.ls0,x.rs1)});
	z.ls0=x.ls0; z.ls1=x.ls1; z.rs0=y.rs0; z.rs1=y.rs1;
	if(x.flag==1) z.ls0=min(z.ls0,y.ls0-x.sum);
	if(x.flag==0) z.ls1=min(z.ls1,y.ls1+x.sum);
	if(y.flag==0) z.rs0=min(z.rs0,x.rs0+y.sum);
	if(y.flag==1) z.rs1=min(z.rs1,x.rs1-y.sum);
	z.sum=x.sum+y.sum;
	if(x.flag==y.flag) z.flag=x.flag;
	else z.flag=-1;
	return z;
}
struct SEG{
	struct Node{
		K key[2]; bool tag;
	}t[N<<2];
	int L,R;

	void up(int p){
		for(int d=0;d<2;++d)
			t[p].key[d]=merge(t[p+p].key[d],t[p+p+1].key[d]);
	}
	void put_tag(int p,bool tag){
		if(tag){
			swap(t[p].key[0],t[p].key[1]);
			t[p].tag^=1;
		}
	}
	inline void down(int p){
		put_tag(p+p,t[p].tag);
		put_tag(p+p+1,t[p].tag);
		t[p].tag=0;
	}
	void build(int p,int l,int r,int k){
		t[p].tag=0;
		if(l==r){
			t[p].key[0]=K(k,0,INF,INF,l);
			t[p].key[1]=K(k^1,0,INF,INF,l);
			return;
		}
		int m=l+r>>1; 
		build(p+p,l,m,k);
		build(p+p+1,m+1,r,k);
		up(p);
	}
	void init(int _L,int _R,int k){L=_L,R=_R,build(1,L,R,k); }
	void modify(int p,int l,int r,int x,int y,bool tag){
		if(y<l||r<x) return;
		if(x<=l&&r<=y) return put_tag(p,tag);
		int m=l+r>>1; down(p);
		modify(p+p,l,m,x,y,tag);
		modify(p+p+1,m+1,r,x,y,tag);
		up(p);
	}
	void modify(int x,int y,bool tag){ modify(1,L,R,x,y,tag); }
	void change(int p,int l,int r,int x,int edge_type,ll ke,ll k0,ll k1){
		if(x<l||r<x) return;
		if(l==r){
			t[p].key[0]=K(edge_type,ke,k0,k1,l);
			t[p].key[1]=K(edge_type^1,ke,k0,k1,l);
			return;
		}
		int m=l+r>>1; down(p);
		change(p+p,l,m,x,edge_type,ke,k0,k1);
		change(p+p+1,m+1,r,x,edge_type,ke,k0,k1);
		up(p);
	}
	void change(int x,int edge_type,ll ke,ll k0,ll k1){ 
		change(1,L,R,x,edge_type,ke,k0,k1);
	}
	K query(int p,int l,int r,int x,int y){
		if(y<l||r<x) assert(0);
		if(x==l&&r==y) return t[p].key[0];
		int m=l+r>>1; down(p);
		if(y<=m) return query(p+p,l,m,x,y);
		else if(x>m) return query(p+p+1,m+1,r,x,y);
		else return merge(query(p+p,l,m,x,m),query(p+p+1,m+1,r,m+1,y));
	}
	K query(int x,int y){ return query(1,L,R,x,y); }
}seg_S_to_T,seg_T_to_S;
int a[N],cnt0[N],cnt1[N],cnt2[N],cnt3[N];
void update(int x){
	seg_S_to_T.change(x,seg_S_to_T.query(x,x).flag,a[x],cnt0[x]+cnt2[x]>0?0:INF,cnt1[x]+cnt3[x]>0?0:INF);
	seg_T_to_S.change(x,seg_T_to_S.query(x,x).flag,a[x],cnt2[x]>0?0:INF,cnt3[x]>0?0:INF);
}
pair<ll,int> check_spread(int& x,int& y,int l,int r,int type){
	pair<ll,pair<int,int> > kk;
	if(type==1) kk=seg_S_to_T.query(l,r).ans;
	else kk=seg_T_to_S.query(l,r).ans;
	pair<ll,int> ret(kk.first,0);
	x=kk.second.first,y=kk.second.second;
	if(cnt2[x]>0) ret.second--;
	else ret.second++;
	if(cnt3[y]>0) ret.second--;
	else ret.second++;
	ret.second/=2;
	return ret;
}
void spread(int x,int y){
	if(cnt2[x]>0) cnt2[x]--,cnt1[x]++;
	else cnt0[x]--,cnt3[x]++;
	if(cnt3[y]>0) cnt3[y]--,cnt0[y]++;
	else cnt1[y]--,cnt2[y]++;
	if(x<y){
		seg_S_to_T.modify(x+1,y,1);
		seg_T_to_S.modify(x+1,y,1);
	}else{
		seg_S_to_T.modify(y+1,x,1);
		seg_T_to_S.modify(y+1,x,1);
	}
	update(x); update(y);
}
void solve(int l,int r,int k){
	ll ret=0; int exflow=0;
	while(exflow<k){
		int x,y;
		pair<ll,int> key=check_spread(x,y,l,r,1);
		if(key.first<0){
			ret+=key.first; exflow+=key.second;
			spread(x,y);
		}else break;
	}
	printf("%lld\n",-ret);
	while(exflow>0){
		int x,y;
		pair<ll,int> key=check_spread(x,y,l,r,0);
		ret+=key.first; exflow+=key.second;
		spread(x,y);
//		cerr<<key.first<<" "<<key.second<<endl;
	}
}
int main(){
	int n; scanf("%d",&n);
	seg_S_to_T.init(0,n,0);
	seg_T_to_S.init(0,n,0);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]),a[i]=-a[i];
	}
	for(int i=0;i<=n;++i){
		cnt0[i]=cnt1[i]=1;
		cnt2[i]=cnt3[i]=0;
		update(i);
	}
	int q; scanf("%d",&q);
	while(q--){
		int op,x,y; scanf("%d%d%d",&op,&x,&y);
		if(op==0){
			a[x]=-y;
			update(x);
		}else{
			int k; scanf("%d",&k);
			solve(x-1,y,k);
		}
	}
	/*
	ll ret=0;
	int exflow=0;
	while(exflow<k){
		int x,y;
		pair<ll,int> key=check_spread(x,y,0,n,1);
		cerr<<key.first<<" "<<key.second<<endl;
		if(key.first<0){
			ret+=key.first,exflow+=key.second;
			spread(x,y);
		}else break;
	}
	printf("%lld\n",-ret);
	int q; scanf("%d",&q);
	while(q--){
		int x,y; scanf("%d%d",&x,&y); y=-y;
		int f=seg_S_to_T.query(x,x).flag;
		if(f==1) ret+=y-a[x];
		a[x]=y;
		update(x);
		while(1){
			int x,y;
			pair<ll,int> key=check_spread(x,y,0,n,0);
			if(key.first<0){
				ret+=key.first,exflow+=key.second;
				spread(x,y);
			}else break;
		}
		while(exflow<k){
			int x,y;
			pair<ll,int> key=check_spread(x,y,0,n,1);
			if(key.first<0){
				ret+=key.first,exflow+=key.second;
				spread(x,y);
			}else break;
		}
		printf("%lld\n",-ret);
	}*/
	return 0;
}