// Problem: CF678F Lena and Queries
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF678F
// Memory Limit: 250 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define int long long
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
const int N=3e5+100;
int n;typedef long long ll;
const ll inf=0x3f3f3f3f3f3f3f3f;
struct node{
	int x,y;
	node(int x=0,int y=0):x(x),y(y){};
	bool operator<(const node rhs)const{
		if(x==rhs.x)return y<rhs.y;
		return x<rhs.x;
	}
};
ll chk(node a1,node a2,node b1,node b2){
	return 1ll*(a2.x-a1.x)*(b2.y-b1.y)-1ll*(a2.y-a1.y)*(b2.x-b1.x);
}
struct line{
	int k;
	bool operator<(const line&rhs)const{return k<rhs.k;}
	ll operator()(const node a){return a.x*k+a.y;}
};
struct Convex_Hull{
	vector<node>p,s;int now;
	void add(node a){p.push_back(a);}
	void work(){
		if(!p.size())return;
		now=0;
		s.push_back(p[0]);
		if(p.size()==1)return;
		s.push_back(p[1]);
		for(int i=2;i<p.size();i++){
			while(s.size()>1&&chk(s[s.size()-2],s.back(),s.back(),p[i])<0)s.pop_back();
			s.push_back(p[i]);
		}
		int cnt=s.size();s.push_back(p[p.size()-2]);
		for(int i=(int)p.size()-3;~i;i--){
			while(s.size()>cnt&&chk(s[s.size()-2],s.back(),s.back(),p[i])<0)s.pop_back();
			s.push_back(p[i]);
		}
		s.pop_back();
	}
	#define nxt(x) ((x+1)%s.size())
	#define lst(x) ((x-1+s.size())%s.size())
	ll getmx(line f){
		if(!s.size())return -inf;
		while(f(s[lst(now)])>f(s[now]))now=lst(now);
		while(f(s[nxt(now)])>f(s[now]))now=nxt(now);
		return f(s[now]);
	}
	void print(){
		puts("Start");
		for(auto p:s)
			printf("%d %d\n",p.x,p.y);
		puts("");
	}
}T[N<<2];
struct Point{
	int l,r;node p;
	bool operator<(const Point rhs)const{
		return p<rhs.p;
	}
}P[N];
int pcnt=0;
struct Query{
	int time;line f;
	bool operator<(const Query rhs)const{
		return f<rhs.f;
	}
}Q[N];
int qcnt=0;
int id[N];
ll ans[N];
#define lc (x<<1)
#define rc (x<<1|1)
#define mid ((l+r)>>1)
void upd(int x,int l,int r,int ql,int qr,node a){
	if(ql<=l&&r<=qr)return T[x].add(a),void();
	if(r<ql||qr<l)return;
	upd(lc,l,mid,ql,qr,a);
	upd(rc,mid+1,r,ql,qr,a);
}
void build(int x,int l,int r){
	T[x].work();
	//printf("%d\n",x);
	//T[x].print();
	if(l==r)return;
	build(lc,l,mid);
	build(rc,mid+1,r);
}
ll qry(int x,int l,int r,int pos,line f){
	if(l==r)return T[x].getmx(f);
	if(pos<=mid)return max(T[x].getmx(f),qry(lc,l,mid,pos,f));
	else return max(T[x].getmx(f),qry(rc,mid+1,r,pos,f));
}
signed main(){
	read(n);
	for(int i=1;i<=n;i++){
		int op;
		read(op);
		if(op==1){
			++pcnt;
			P[pcnt].l=i;
			id[i]=pcnt;
			P[pcnt].r=n;
			read(P[pcnt].p.x,P[pcnt].p.y);
		}else if(op==2){
			int k;read(k);
			P[id[k]].r=i;id[i]=-1;
		}else{
			++qcnt;
			Q[qcnt].time=i;
			read(Q[qcnt].f.k);
		}
	}
	sort(P+1,P+pcnt+1);
	sort(Q+1,Q+qcnt+1);
	for(int i=1;i<=pcnt;i++)
		upd(1,1,n,P[i].l,P[i].r,P[i].p);
	build(1,1,n);
	for(int i=1;i<=qcnt;i++)
		ans[Q[i].time]=qry(1,1,n,Q[i].time,Q[i].f);
	for(int i=1;i<=n;i++)
		if(!id[i]){
			if(ans[i]==-inf)puts("EMPTY SET");
			else write(ans[i]),putchar('\n');
		}
}