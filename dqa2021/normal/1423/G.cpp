#include<cstdio>
#include<algorithm>
#include<cctype>
#include<map>
#include<set>
#include<assert.h>
using namespace std;
#define G getchar()
inline int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
typedef long long ll;

int n,q;

#define ls (x<<1)
#define rs (x<<1|1)
#define mid (l+r>>1)
struct Node{
	ll a,b;
}node[1<<18];
void update(int x,int l,int r,int ql,int qr,ll a,ll b){
	if (ql<=l&&r<=qr) return node[x].a+=a,node[x].b+=b,void();
	if (ql<=mid) update(ls,l,mid,ql,qr,a,b);
	if (mid<qr) update(rs,mid+1,r,ql,qr,a,b);
}
ll query(int x,int l,int r,int p){
	ll res=node[x].a*p+node[x].b;
	if (l==r) return res;
	if (p<=mid) return res+query(ls,l,mid,p);
	return res+query(rs,mid+1,r,p);
}
#undef ls
#undef rs
#undef mid

map<int,int> id; int idtot;
int getid(int x){
	map<int,int>::iterator it=id.find(x);
	if (it!=id.end()) return it->second;
	return id[x]=++idtot;
}
struct Rec{
	int l,r,c;
};
typedef set<Rec>::iterator It;
bool operator<(const Rec &x,const Rec &y){
	return x.l<y.l;
}
set<Rec> S[200010],T;

void getans(It it,int d){
	int l=it->l,r=it->r,c=it->c,len=r-l+1;
	int pre=0;
	if (it!=S[c].begin()){
		It t=it; --t;
		pre=t->r;
	}
	int lim=n-pre,lim1=l-pre,lim2=n-r+1;
	if (lim1>1) update(1,1,n,1,lim1-1,d,-d*l);
	assert(lim1<=lim);
	update(1,1,n,lim1,lim,0,-d*pre);
	if (lim2>1) update(1,1,n,1,lim2-1,0,d*r);
	assert(lim2<=lim);
	update(1,1,n,lim2,lim,-d,d*(n+1));
}

void ins(Rec x){
	int &l=x.l,&r=x.r,&c=x.c;
	T.insert(x);
	It suf=S[c].lower_bound(x);
	if (suf!=S[c].end()) getans(suf,-1);
	It it=S[c].insert(x).first;
	getans(it,1);
	if (suf!=S[c].end()) getans(suf,1);
}
void del(Rec x){
	int &l=x.l,&r=x.r,&c=x.c;
	//T.erase(x);
	It it=S[c].find(x);
	assert(it!=S[c].end());
	It suf=it; ++suf;
	getans(it,-1);
	if (suf!=S[c].end()) getans(suf,-1);
	S[c].erase(it);
	if (suf!=S[c].end()) getans(suf,1);
}

void cut(int p){
	It it=T.upper_bound((Rec){p,0,0}); --it;
	if (it->r==p) return;
	Rec z=*it;
	int l=it->l,r=it->r,c=it->c;
	Rec x=(Rec){it->l,p,it->c},y=(Rec){p+1,it->r,it->c};
	T.erase(it); T.insert(x),T.insert(y);
	S[c].erase(z); S[c].insert(x),S[c].insert(y);
}
int main()
{
	n=read(),q=read();
	for (int i=1;i<=n;i++){
		int x=getid(read());
		ins((Rec){i,i,x});
	}
	while (q--){
		if (read()&1){
			int l=read(),r=read(),c=getid(read());
			cut(r); if (l>1) cut(l-1);
			It pre=T.lower_bound((Rec){l,0,0}),suf=T.upper_bound((Rec){r,0,0});
			for (It it=pre;it!=suf;++it) del(*it);
			T.erase(pre,suf);
			Rec x=(Rec){l,r,c}; ins(x);
			continue;
		}
		printf("%I64d\n",query(1,1,n,read()));
	}
	return 0;
}