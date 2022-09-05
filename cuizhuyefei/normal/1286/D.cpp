#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 666666,mo=998244353,inf=0x3f3f3f3f;
inline void add(int &x, int y){x=x+y<mo?x+y:x+y-mo;}
inline void sub(int &x, int y){x=x-y>=0?x-y:x-y+mo;}
inline int power(int a, int n) {
	int res=1;
	while (n) {
		if (n&1) res=1LL*res*a%mo;
		a=1LL*a*a%mo; n>>=1;
	}
	return res;
}
int n,x[N],v[N],p[N],len,zhi[N];bool zuo[N],you[N];set<Pii>Set;
struct node{
	int pos,tp,a,b;
}s[N];
bool cmp(node x, node y){return 1ll*x.a*y.b<1ll*y.a*x.b;}
namespace yzr{
	struct node{
		int ans,zuo,you;
	}tree[N<<2];
	node merge(node a, node b){
		node c;c.zuo=1ll*a.zuo*b.zuo%mo;c.you=1ll*a.you*b.you%mo;
		c.ans=((1ll*a.ans*b.you+1ll*a.zuo*b.ans-1ll*a.zuo*b.you)%mo+mo)%mo;
		return c;
	}
	void build(int k, int l, int r){
		if(l==r){
			tree[k].ans=1;tree[k].zuo=1+mo-p[l];tree[k].you=p[l];return;
		}
		int mid=(l+r)>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);
		tree[k]=merge(tree[k<<1],tree[k<<1|1]);
	}
	node qry(int k, int l,int r, int L, int R){
		if(l==L&&r==R)return tree[k];
		int mid=(L+R)>>1;
		if(r<=mid)return qry(k<<1,l,r,L,mid);
		if(l>mid)return qry(k<<1|1,l,r,mid+1,R);
		return merge(qry(k<<1,l,mid,L,mid),qry(k<<1|1,mid+1,r,mid+1,R));
	}
	int qry(int l,int r){
		if(you[l]&&zuo[r])return 0;
		if(you[l])return qry(1,l,r,1,n).you;
		if(zuo[r])return qry(1,l,r,1,n).zuo;
		return qry(1,l,r,1,n).ans;
	}
}
int main() {
//	cout<<1ll*power(4,mo-2)%mo<<endl;
//	cout<<3ll*power(4,mo-2)%mo<<endl;
	
	read(n);
	rep(i,1,n)read(x[i]),read(v[i]),read(p[i]),p[i]=1ll*p[i]*power(100,mo-2)%mo;
	rep(i,1,n-1){
		s[++len]=(node){i,0,x[i+1]-x[i],v[i]+v[i+1]};
		if(v[i]>v[i+1])s[++len]=(node){i,1,x[i+1]-x[i],v[i]-v[i+1]};
		if(v[i]<v[i+1])s[++len]=(node){i,2,x[i+1]-x[i],-v[i]+v[i+1]};
	}
	sort(s+1,s+len+1,cmp);
	rep(i,1,len)zhi[i]=1ll*s[i].a*power(s[i].b,mo-2)%mo;
	int res=zhi[1],cur=1;rep(i,1,n)Set.insert(Pii(i,i));
	yzr::build(1,1,n);
	rep(j,1,len){
		if(s[j].tp==0){
			set<Pii>::iterator it=Set.lower_bound(Pii(s[j].pos+1,-inf)),it1;
			it1=it;it1--;
			cur=1ll*cur*power(1ll*yzr::qry((*it1).fi,(*it1).se)*yzr::qry((*it).fi,(*it).se)%mo,mo-2)%mo;
			int L=(*it1).fi,R=(*it).se;
			Set.erase(it);Set.erase(it1);Set.insert(Pii(L,R));
			cur=1ll*cur*yzr::qry(L,R)%mo;
		}
		else if(s[j].tp==1){
			if(you[s[j].pos])cur=0;
			else if(!zuo[s[j].pos]){
				set<Pii>::iterator it=Set.lower_bound(Pii(s[j].pos,inf));it--;
				int L=(*it).fi,R=(*it).se;
				cur=1ll*cur*power(yzr::qry((*it).fi,(*it).se)%mo,mo-2)%mo;
				zuo[s[j].pos]=1;
				Set.erase(it);Set.insert(Pii(L,s[j].pos));Set.insert(Pii(s[j].pos+1,R));
				cur=1ll*cur*yzr::qry(L,s[j].pos)%mo*yzr::qry(s[j].pos+1,R)%mo;
			}
		}
		else{
			if(zuo[s[j].pos+1])cur=0;
			else if(!you[s[j].pos+1]){
				set<Pii>::iterator it=Set.lower_bound(Pii(s[j].pos+1,inf));it--;
				int L=(*it).fi,R=(*it).se;
				cur=1ll*cur*power(yzr::qry((*it).fi,(*it).se)%mo,mo-2)%mo;
				you[s[j].pos+1]=1;
				Set.erase(it);Set.insert(Pii(L,s[j].pos));Set.insert(Pii(s[j].pos+1,R));
				cur=1ll*cur*yzr::qry(L,s[j].pos)%mo*yzr::qry(s[j].pos+1,R)%mo;
			}
		}
	//	printf("%d:%d\n",s[j].pos,cur);
		if(j<len)res=(res+1ll*cur*(zhi[j+1]-zhi[j]+mo))%mo;
		else res=(res-1ll*cur*zhi[j])%mo;
	}
	cout<<(res%mo+mo)%mo;
	return 0;
}