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
#define ls ((x)<<1)
#define rs (((x)<<1)|1)
#define mid (((l)+(r))>>1)
#define pb push_back
#define w1 first
#define w2 second
#define dg(...) fprintf(stderr,__VA_ARGS__);
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
int cnt[maxn],sum[maxn],a[maxn],n,q,sz,bl[maxn];i64 ans[maxn];
struct info{
	int l,r,pr;
	friend inline bool operator < (const info &a,const info &b){
		return (bl[a.l]<bl[b.l]||(bl[a.l]==bl[b.l]&&a.r<b.r));
	}
	inline void in(){read(l);read(r);}
}Q[maxn];
multiset<int> bg;
inline void add(int x){
	if(sum[a[x]]==sz){
		bg.insert(sz+1);
		cnt[sz]--;sum[a[x]]++;return;
	}
	if(sum[a[x]]<sz){
		cnt[sum[a[x]]]--;cnt[++sum[a[x]]]++;return;
	}else{
		bg.erase(bg.find(sum[a[x]]));bg.insert(++sum[a[x]]);
	}
}
inline void del(int x){
	if(sum[a[x]]==sz+1){
		bg.erase(bg.find(sz+1));cnt[--sum[a[x]]]++;return;
	}if(sum[a[x]]<=sz){
		cnt[sum[a[x]]]--;cnt[--sum[a[x]]]++;return;
	}else{
		bg.erase(bg.find(sum[a[x]]));bg.insert(--sum[a[x]]);
	}
}int nowl,nowr;
int tmp[maxn];
priority_queue<int,vector<int>,greater<int> > heap;
int main(){
	//judge();
	read(n);rep(i,1,n)read(a[i]);
	read(q);sz=1000;rep(i,1,n)bl[i]=i/sz+1;
	rep(i,1,q)Q[i].in(),Q[i].pr=i;
	sort(Q+1,Q+1+q);nowl=1,nowr=0;
	rep(i,1,q){
		while(nowr<Q[i].r)add(++nowr);
		while(nowr>Q[i].r)del(nowr--);
		while(nowl>Q[i].l)add(--nowl);
		while(nowl<Q[i].l)del(nowl++);
		while(!heap.empty())heap.pop();
		int lst=0;
		for(auto it:bg)
			heap.push(it);
		i64 res=0;
		rep(i,0,sz)tmp[i]=cnt[i];
		rep(i,1,sz){
			if(!cnt[i])continue;
			if(lst){
				res+=i+lst;
				if(i+lst<=sz)cnt[i+lst]++;else heap.push(i+lst);
				cnt[i]--;lst=0;
			}res+=(i+i)*(cnt[i]/2);
			if(i+i<=sz)
				cnt[i+i]+=cnt[i]/2;
			else rep(k,1,cnt[i]/2)heap.push(i+i);
			if(cnt[i]&1)lst=i;
		}if(lst)heap.push(lst);
		while(heap.size()!=1&&heap.size()!=0){
			int x=heap.top();heap.pop();
			int y=heap.top();heap.pop();
			heap.push(x+y);
			res+=x+y;
		}
		ans[Q[i].pr]=res;
		rep(i,0,sz)cnt[i]=tmp[i];
	}
	rep(i,1,q)printf("%I64d\n",ans[i]);
	dg("ok\n");
	return 0;
}