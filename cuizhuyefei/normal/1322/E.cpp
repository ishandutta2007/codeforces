#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(),x.end()
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> T gcd(T a, T b){return !b?a:gcd(b,a%b);}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 505000;
int n,a[N],f[N],ans[N],sz;set<Pii>Set;Pii b[N];
struct Heap{
	int cnt[N];set<int>Set;
	inline void era(int x){cnt[x]--;if(!cnt[x])Set.erase(x);}
	inline void ins(int x){if(!cnt[x])Set.insert(x);cnt[x]++;}
	inline int qry(){return Set.empty()?0:*Set.rbegin();}
}heap;
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void updans(int l, int r, int x){//offset!
	for(l=find(l);l<=r;l=find(l))ans[l]=x,f[l]=l+1;
}
void era(set<Pii>::iterator it){
//	printf("era %d %d\n",(*it).fi,(*it).se);
	if(SZ(Set)==1){Set.erase(it);return;}
	if(it==Set.begin()){auto nxt=it;nxt++;heap.era((*nxt).fi-(*it).se-1);Set.erase(it);return;}
	if(it==(--Set.end())){auto pre=it;pre--;heap.era((*it).fi-(*pre).se-1);Set.erase(it);return;}
	auto nxt=it;nxt++;auto pre=it;pre--;
	heap.era((*nxt).fi-(*it).se-1);heap.era((*it).fi-(*pre).se-1);
	heap.ins((*nxt).fi-(*pre).se-1);
	Set.erase(it);
}
void ins(int l, int r){
//	printf("ins %d %d\n",l,r);
	auto it=Set.insert(mp(l,r)).fi;
	if(SZ(Set)==1)return;
	if(it==Set.begin()){auto nxt=it;nxt++;heap.ins((*nxt).fi-(*it).se-1);return;}
	if(it==(--Set.end())){auto pre=it;pre--;heap.ins((*it).fi-(*pre).se-1);return;}
	auto nxt=it;nxt++;auto pre=it;pre--;
	heap.ins((*nxt).fi-(*it).se-1);heap.ins((*it).fi-(*pre).se-1);
	heap.era((*nxt).fi-(*pre).se-1);
}
void mdy(int p){
	auto it=Set.lower_bound(mp(p+1,0));
	if(!Set.empty()&&it!=Set.begin()){
		--it;if((*it).fi<=p&&(*it).se>=p){
			int l=(*it).fi,r=(*it).se;era(it);//WA
			if(l<p-1)ins(l,p-1);
			if(p+1<r)ins(p+1,r);
		}
	}
	a[p]=1;int l=p,r=p;
	if(a[p+1]==1){
		auto it=Set.lower_bound(mp(p+1,0));
		if(!Set.empty()&&it!=Set.end()&&(*it).fi==p+1)r=(*it).se,era(it);
		else r=p+1;
	}
	if(a[p-1]==1){
		auto it=Set.lower_bound(mp(p,0));
		if(!Set.empty()&&it!=Set.end()&&(*(--it)).se==p-1)l=(*it).fi,era(it);
		else l=p-1;
	}
	if(l<r)ins(l,r);
}
int CUR;
void handle(set<Pii>::iterator it){
	auto nxt=it;nxt++;int mid=((*it).se+(*nxt).fi)/2;
	if((*it).se<mid&&a[(*it).se]==1)updans((*it).se+1,mid,CUR);
	if(mid+1<=(*nxt).fi-1&&a[(*nxt).se]==1)updans(mid+1,(*nxt).fi-1,CUR);
}
int main() {
	read(n);
	rep(i,1,n){
		int x;read(x);b[++sz]=mp(x,i+2);
		if(i==1||i==n)b[++sz]=mp(x,i==1?2:n+3);
	}
	a[1]=a[n+4]=2;Set.insert(mp(2,n+3));
	rep(i,1,n+5)f[i]=i;
	sort(b+1,b+sz+1);reverse(b+1,b+sz+1);
	int mx=0;
	rep(l,1,sz){
		int r=l;while(r+1<=sz&&b[r+1].fi==b[l].fi)r++;CUR=b[l].fi;
		rep(t,l,r)mdy(b[t].se);
		rep(t,l,r){
			int p=b[t].se;
			if(a[p]+a[p-1]+a[p+1]>=2){
				auto it=Set.lower_bound(mp(p+1,0));it--;
				updans((*it).fi,(*it).se,b[t].fi);
				if(it!=Set.end())handle(it);
				if(it!=Set.begin()){auto pre=it;handle(--pre);}
			}
			else{
				auto it=Set.lower_bound(mp(p+1,0));
				if(it!=Set.end()&&it!=Set.begin()){
					auto pre=it;handle(--pre);
				}
			}
		}
	//	printf("qaq %d\n",SZ(Set));
	//	for(auto x:Set)printf("[%d,%d]\n",x.fi,x.se);
		umax(mx,heap.qry());
		l=r;
	}
	printf("%d\n",mx+1>>1);
	rep(i,3,n+2)printf("%d ",ans[i]);
	return 0;
}