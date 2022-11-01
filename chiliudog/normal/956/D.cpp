#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<cstring>
#include<vector>
#include<map>
#include<cassert>
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
#define ls ((x)<<1)
#define rs (((x)<<1)|1)
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
const int maxn=100005;
struct frac{
	i64 x,y;
	inline frac(){}
	inline frac(int _x,int _y){x=_x;y=_y;}
	inline void print(){
	}
};
inline bool operator < (const frac &a,const frac &b){
	return a.x*b.y<a.y*b.x;
}
inline bool operator == (const frac &a,const frac &b){
	return a.x*b.y==a.y*b.x;
}
inline bool operator > (const frac &a,const frac &b){
	return a.x*b.y>a.y*b.x;
}
struct info{
	frac t,rt;
	int tp,nd,pr;
	inline info(){}
	inline info(frac _t,int _tp,int _nd,int _pr,frac _rt){t=_t;tp=_tp;nd=_nd;pr=_pr;rt=_rt;}
}a[maxn<<1];
inline bool operator < (const info &a,const info &b){
	if(a.t==b.t){
		if(a.tp!=b.tp)
			return a.tp>b.tp;
		return a.rt>b.rt;
	}
	return a.t<b.t;
}
int tot=0;
struct bit{
	int sum[maxn<<1];
	inline void add(int x,int v){
		while(x<=tot){
			sum[x]+=v;x+=lowbit(x);
		}
	}
	inline int query(int x){
		int res=0;
		while(x){
			res+=sum[x];x-=lowbit(x);
		}return res;
	}
}sz1,sz0;
int n,w,x[maxn],v[maxn],pos[maxn];
int main(){
	read(n);read(w);
	rep(i,1,n){
		read(x[i]);read(v[i]);
		frac t1=frac(abs(x[i]),abs(v[i]+w));
		frac t2=frac(abs(x[i]),abs(v[i]-w));
		if(t1>t2)swap(t1,t2);
		a[++tot]=info(t1,1,x[i]>0,i,t2);
		a[++tot]=info(t2,-1,x[i]>0,i,t1);
		// t1.print();t2.print();
	}
	// cerr<<(a[2]<a[4]);
	sort(a+1,a+1+tot);
	i64 ans=0;int cur1=0,cur0=0,pr1=0,pr0=0;int last_value=1;
	rep(i,1,tot){
		if(!(a[i].t==a[i-1].t))last_value++;
		// cerr<<a[i].pr<<' '<<last_value<<endl;
		if(a[i].tp==1){
			if(a[i].nd){
				ans+=cur0;
				pos[a[i].pr]=last_value;
			}
			else{
				ans+=cur1;
				pos[a[i].pr]=last_value;
			}
			if(a[i].nd)
				cur1++;
			else
				cur0++;
		}else{
			if(a[i].nd){
				cur1--;
				// cerr<<""<<pos[a[i].pr]<<endl;
				ans+=pr1-sz1.query(pos[a[i].pr]-1);
				sz1.add(pos[a[i].pr],1);pr1++;
			}
			else{
				cur0--;
				ans+=pr0-sz0.query(pos[a[i].pr]-1);
				sz0.add(pos[a[i].pr],1);pr0++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}