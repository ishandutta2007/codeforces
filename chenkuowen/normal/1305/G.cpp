//by chenkuowen01
/*-------------------Intialize Module--------------------*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
/*-------------------Basis Functions----------------------*/
template<class T> inline void dmin(T& x,T y){ y<x?x=y:T(); }
template<class T> inline void dmax(T& x,T y){ x<y?x=y:T(); }
template<class T> inline void dmin(T& x,vector<T> y){ 
	for(auto t:y) t<x?x=t:0;
}
template<class T> inline void dmax(T& x,vector<T> y){
	for(auto t:y) t>x?x=t:0;
}
/*-------------------Coding-----------------------------*/
const int MAX_N=1<<18|5;
int a[MAX_N],type[MAX_N],n,top=1<<18;
bool vis[MAX_N],flag[MAX_N];
int merge(int x,int y){ return a[x]>a[y]?x:y; }
pair<int,int> merge(pair<int,int> x,pair<int,int> y){
	pair<int,int> ret;
	if(a[x.first]<a[y.first]) swap(x,y);
	if(a[y.first]<a[x.second]) ret=x;
	else{
		if(type[x.first]==type[y.first])
			ret=make_pair(x.first,merge(x.second,y.second));
		else
			ret=make_pair(x.first,y.first);
	}
	return ret;
}
struct Ot{
	pair<int,int> f[20][MAX_N];
	void init(){
		for(int i=0;i<top;++i)
			f[0][i]=make_pair(0,0);
		for(int i=1;i<=n;++i)
			if(!vis[i])
				f[0][a[i]]=merge(f[0][a[i]],make_pair(i,0));
		for(int p=1;p<=18;++p){
			memcpy(f[p],f[p-1],sizeof(f[p-1]));
			for(int i=0;i<top;++i){
				if(i&(1<<p-1))
					f[p][i]=merge(f[p][i],f[p-1][i^(1<<p-1)]);
			}
		}
	}
	int query(int x){
		int pos=~a[x]&(top-1);
//		printf("|%d %d|",x,pos);
		pair<int,int> k=f[18][pos];
//		printf("(%d %d)",type[k.first],type[k.second]);
		if(type[k.first]==type[x]) return k.second;
		else return k.first;
	}
}ot;
ll ans=0;
struct Cont{
	ll ans;
	vector<int> x;
	void clear(){ ans=0; x.clear(); }
	Cont(){clear();}
	void finish(){
		int mx=0;
//		printf("|%lld|",ans);
		for(auto t:x){
//			 dmax(mx,a[t]);
			 ans-=a[t];
			 vis[t]=1;
		}
		ans+=mx;
		dmax(::ans,ans);
		clear();
	}
	void merge(Cont& b,int key){
//		printf("<%lld %lld %d>",ans,b.ans,key);
		ans+=b.ans+key;
		for(auto t:b.x) x.push_back(t);
		b.clear();
	}
};
int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	scanf("%d",&n); 
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	a[++n]=0;
	vector<Cont> h; h.resize(n);
	for(int i=0;i<n;++i) h[i].x.push_back(i+1);
	a[0]=-1; type[0]=-1;
	while(!h.empty()){
		for(int i=0;i<h.size();++i){
			for(auto x:h[i].x)
				type[x]=i;
			flag[i]=0;
		}
		ot.init();
		for(int i=0;i<h.size();++i){
			if(flag[i]) continue;
			pair<int,int> mx(0,0);
			for(auto x:h[i].x){
				int pos=ot.query(x);
				if(pos!=0){
					if(a[pos]+a[x]>a[mx.first]+a[mx.second])
						mx=make_pair(pos,x);
				}
			}
//			printf("[%d %d %d]",i,mx.first,mx.second);
			if(mx.first==0) h[i].finish();
			else{
//				printf("[%d %d]",i,type[mx.first]);
				Cont& b=h[type[mx.first]];
				if(b.x.size()<h[i].x.size()){
					for(auto y:b.x) type[y]=i;
					h[i].merge(b,a[mx.first]+a[mx.second]);
				}else{
					for(auto y:h[i].x) type[y]=type[mx.first];
					b.merge(h[i],a[mx.first]+a[mx.second]);
				}
				flag[type[mx.first]]=1;
				flag[i]=1;
			}
//			if(i%1000==0) cerr<<i<<endl;
		}
//		cerr<<"B";
		int tp=0;
		for(int i=0;i<h.size();++i)
			if(!h[i].x.empty())
				swap(h[tp++],h[i]);
		h.resize(tp);
/*		for(auto x:h){
			printf("(");
			for(auto y:x.x)
				printf("|%d|",y);
			printf(")");
		}
		puts("");
		puts("----------------");
*/	}
	printf("%lld\n",ans);
	return 0;
}