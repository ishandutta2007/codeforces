//#pragma optimize(2)
#include<bits/stdc++.h>
using namespace std;
template<typename T>
inline void read(T &x){
	x=0;char c=getchar();bool f=false;
	for(;!isdigit(c);c=getchar())f!=c=='-';
	for(;isdigit(c);c=getchar())x=x*10+c-'0';
	if(f)x=-x;
}
template<typename T ,typename ...Arg>
inline void read(T &x,Arg &...args){
	read(x);read(args...);
}
template<typename T>
inline void write(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>=10)write(x/10);
	putchar(x%10+'0');
}
const int maxn=1e5+100;
template<class T>struct Discrete{
	set<T>num;unordered_map<T,int>rk;vector<T>n;int cnt;
	void operator+=(const T b){
		num.insert(b);
	}void init(){
		cnt=0;n.clear();
		for(auto N:num)
			rk[N]=++cnt,n.push_back(N);
	}T operator[](const int b){return n[b-1];}
	int get(T x){return rk[x];}
};
Discrete<int>D;
struct node{
	int l,r,lc,rc;int len,llen,rlen,mlen;
	template<class T>node(T val){
		if(val==1)llen=rlen=mlen=1;
		else llen=rlen=mlen=0;
		len=1;
	}
	node(){llen=rlen=mlen=len=0;}
	node operator+(const node b)const{
		node c;c.len=len+b.len;
		if(r-l+1==mlen)c.llen=mlen+b.llen;
		else c.llen=llen;
		if(b.r-b.l+1==b.mlen)c.rlen=b.mlen+rlen;
		else c.rlen=b.rlen;
		c.mlen=max(rlen+b.llen,max(mlen,b.mlen));
		return c;
	}
	void cpy(node from){
		llen=from.llen;
		rlen=from.rlen;
		mlen=from.mlen;
		len=from.len;
	}
};
template<class A,class B>
struct HJT_Tree{
	A t[maxn*20];B a[maxn];
	B *operator[](const int x){return &a[x];}
	int cnt;HJT_Tree(){cnt=0;}
	int build(int l,int r){
		int x=++cnt;
		t[x].l=l,t[x].r=r;
		if(l==r){
			t[x].cpy(A(a[l]));
			return x;
		}
		int mid=l+r>>1;
		t[x].lc=build(l,mid);
		t[x].rc=build(mid+1,r);
		t[x].cpy(t[t[x].lc]+t[t[x].rc]);
		return x;
	}
	int upd(int lst,int pos,B val){
		int x=++cnt;t[x]=t[lst];
		if(t[x].l==t[x].r){t[x].cpy(A(val));return x;}
		int mid=t[x].l+t[x].r>>1;
		if(pos<=mid)t[x].lc=upd(t[lst].lc,pos,val);
		else t[x].rc=upd(t[lst].rc,pos,val);
		t[x].cpy(t[t[x].lc]+t[t[x].rc]);
		return x;
	}
	A qry(int x,int lq,int rq){
		if(lq<=t[x].l&&t[x].r<=rq)return t[x];
		int mid=t[x].l+t[x].r>>1;
		if(rq<=mid)return qry(t[x].lc,lq,rq);
		if(lq>mid)return qry(t[x].rc,lq,rq);
		return qry(t[x].lc,lq,rq)+qry(t[x].rc,lq,rq);
	}
};
HJT_Tree<node,int>Tree;
int rt[maxn],n,a,q,x,y,k;
pair<int,int>p[maxn];
signed main(){
	//freopen("1.in","r",stdin);
	read(n);
	for(int i=1;i<=n;i++)read(a),p[i]=make_pair(a,i),D+=a;
	sort(p+1,p+1+n);D.init();
	rt[maxn-1]=Tree.build(1,n);p[n+1].first=maxn-1;
	for(int i=1;i<=n;i++)p[i].first=D.get(p[i].first);
	for(int i=n;i>=1;i--)
		rt[p[i].first]=Tree.upd(rt[p[i+1].first],p[i].second,1);
	for(int i=maxn-2;i>=0;i--)if(!rt[i])rt[i]=rt[i+1];
	read(q);while(q--){
		read(x,y,k);
 		int l=0,r=maxn-1,ans;
		while(l<=r){
			int mid=l+r>>1;
			if(Tree.qry(rt[mid],x,y).mlen>=k)ans=mid,l=mid+1;
			else r=mid-1;
		}write(D[ans]);putchar('\n');
	}
	return 0;
}