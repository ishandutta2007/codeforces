#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define forE(i,x) for(int i=head[x];i!=-1;i=ne[i])
using namespace std;
typedef long long i64;
typedef unsigned long long u64;
typedef unsigned u32;
typedef pair<int,int> pin;
#define mk(a,b) make_pair(a,b)
#define lowbit(x) ((x)&(-(x)))
#define sqr(a) ((a)*(a))
#define clr(a) (memset((a),0,sizeof(a)))
#define ls(x) ((x)<<1)
#define rs(x) (((x)<<1)|1)
#define mid (((l)+(r))>>1)
#define pb push_back
#define w1 first
#define w2 second
inline void read(int &x){
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
inline void judge(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
}
/*******************************head*******************************/
const int maxn=200005;
int u[maxn],h,w,n,l[maxn],r[maxn],s[maxn];
pair<pin,pin> tmp[maxn];
vector<pin> rub;
typedef multiset<pin>::iterator It;
const int inf=2e9;
const int mod=1e9+7;
namespace seg{
	multiset<pin> a[maxn<<2];
	int l[maxn<<2],r[maxn<<2],mini[maxn<<2];
	inline void update(int x){
		mini[x]=min(mini[ls(x)],mini[rs(x)]);
	}
	inline void build(int x,int lq,int rq){
		int md=(lq+rq)>>1;
		l[x]=lq;r[x]=rq;
		if(lq==rq){
			a[x].insert(mk(h+1,1));
			mini[x]=h+1;
			return;
		}build(ls(x),lq,md);build(rs(x),md+1,rq);
		update(x);
	}
	inline int get(int x,int lq,int rq,int h){
		if(mini[x]>h)return 0;
		if(l[x]==r[x]){
			int res=0;
			for(pin v:a[x]){
				if(v.w1<=h){
					res=(res+v.w2)%mod;
					rub.pb(v);
				}else{
					break;
				}
			}
			for(pin v:rub)a[x].erase(v);rub.clear();
			mini[x]=a[x].empty()?inf:a[x].begin()->w1;
			return res;
		}
		int res=0,md=(l[x]+r[x])>>1;
		if(lq<=md)res+=get(ls(x),lq,rq,h);
		if(rq> md)res+=get(rs(x),lq,rq,h);
		update(x);
		return res%mod;
	}
	inline void add(int x,int place,int va,int vb){
		if(l[x]==r[x]){
			a[x].insert(mk(va,vb));
			mini[x]=min(mini[x],va);
			return;
		}
		int md=(l[x]+r[x])>>1;
		if (place<=md)
			add(ls(x),place,va,vb);
		else
			add(rs(x),place,va,vb);
		update(x);
	}
	inline int getans(int x){
		if(l[x]==r[x]){
			int res=0;
			for(pin v:a[x])
				res=(res+v.w2)%mod;
			//printf("%d ",res);
			return res;
		}
		int md=(l[x]+r[x])>>1,res=0;
		res+=getans(ls(x));
		res+=getans(rs(x));
		return res%mod;
	}
}
int main(){
    read(h);read(w);read(n);
    rep(i,1,n)read(tmp[i].w1.w1),read(tmp[i].w1.w2),read(tmp[i].w2.w1),read(tmp[i].w2.w2);
    sort(tmp+1,tmp+1+n);reverse(tmp+1,tmp+1+n);
    rep(i,1,n)u[i]=tmp[i].w1.w1,l[i]=tmp[i].w1.w2,r[i]=tmp[i].w2.w1,s[i]=tmp[i].w2.w2;
    seg::build(1,1,w);
    rep(i,1,n){
    	int num=seg::get(1,l[i],r[i],u[i]+s[i]);
    	int a=l[i]-1,b=r[i]+1;
    	if(a==0)a=b;
    	if(b==w+1)b=a;
    	seg::add(1,a,u[i],num);
    	seg::add(1,b,u[i],num);
    }cout<<seg::getans(1);
    return 0;
}