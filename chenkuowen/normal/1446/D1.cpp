#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
//const ld PI=acosl(-1),EPS=1e-10;
template<class T> inline void dmin(T& x,T y){ y<x?x=y:0; }
template<class T> inline void dmax(T& x,T y){ y>x?x=y:0; }
template<class T> inline void dmin(T& x,vector<T> y){for(auto t:y)t<x?x=t:0;}
template<class T> inline void dmax(T& x,vector<T> y){for(auto t:y)t>x?x=t:0;}
/*
const int N=5+1e5,MOD=998244353;
inline int fpow(int x,int n,int ret=1,int mod=MOD){
	for(;n;n>>=1,x=1ll*x*x%mod)
		n&1?ret=1ll*ret*x%mod:0;
	return ret;
}
inline void mo(int& x){ x>=MOD?x-=MOD:0; }
inline int mo1(int x){ return x>=MOD?x-MOD:x; }
int inv[N],fac[N],ifac[N];
struct IniterFacInv{
	IniterFacInv(){
		fac[0]=ifac[0]=inv[1]=1;
		for(int i=1;i<N;++i){
			fac[i]=1ll*fac[i-1]*i%MOD;
			if(i>1) inv[i]=1ll*(MOD-MOD/i)*inv[MOD%i]%MOD;
			ifac[i]=1ll*ifac[i-1]*inv[i]%MOD;
		}
	}
}__initer_comb;
inline int comb(int n,int m){
	if(n<0||m<0||n<m) return 0;
	return 1ll*fac[n]*ifac[m]%MOD*ifac[n-m]%MOD;
}
inline int rcomb(int n,int m){
	if(n<0||m<0||n<m) return 0;
	return 1ll*ifac[n]*fac[m]%MOD*fac[n-m]%MOD;
}
*/
const int N=5+2e5;
struct SEG{
	struct Node{
		ll tag,key;
	}t[N<<2];
	inline void up(int x){ t[x].key=min(t[x+x].key,t[x+x+1].key); }
	inline void put_tag(int x,ll tag){
		t[x].key+=tag;
		t[x].tag+=tag;
	}
	inline void down(int x){
		put_tag(x+x,t[x].tag);
		put_tag(x+x+1,t[x].tag);
		t[x].tag=0;
	}
	void build(int p,int l,int r){
		t[p]=(Node){0,0};
		if(l==r) return;
		int m=l+r>>1;
		build(p+p,l,m);
		build(p+p+1,m+1,r);
	}
	void change(int p,int l,int r,int x,int y,int tag){
		if(y<l||r<x) return;
		if(x<=l&&r<=y) return put_tag(p,tag);
		int m=l+r>>1; down(p);
		change(p+p,l,m,x,y,tag);
		change(p+p+1,m+1,r,x,y,tag);
		up(p);
	}
	int search(int p,int l,int r,int key){
		if(t[p].key>key) return -1;
		if(l==r) return l;
		int m=l+r>>1; down(p);
		int k=search(p+p+1,m+1,r,key);
		if(k==-1) return search(p+p,l,m,key);
		else return k;
	}
	ll query(int p,int l,int r,int x){
		if(l==r) return t[p].key;
		int m=l+r>>1; down(p);
		if(x<=m) return query(p+p,l,m,x);
		else return query(p+p+1,m+1,r,x);
	}
}seg;
vector<int> b[N],f;
int a[N];
int solve(vector<int> a){
	vector<pair<int,int> > s;
	vector<int> pos(a.size());
	int sum=0,poi;
	for(int i=0;i<a.size();++i){
		sum++;
		s.push_back(make_pair(a[i],1));
		poi=upper_bound(f.begin(),f.end(),a[i])-f.begin();
		while(poi+1<f.size()&&(i==(int)a.size()-1||f[poi]<a[i+1])){
			if(sum==-2) break;
			sum--;
			s.push_back(make_pair(f[poi],-1));
			++poi;
		}
		if(sum<0) sum=0;
	}
	sum=0; 
	for(int i=(int)a.size()-1;i>=0;--i){
		sum++;
		poi=upper_bound(f.begin(),f.end(),a[i])-f.begin()-1;
		while(poi>0&&(i==0||f[poi]>a[i-1])){
			if(sum==-2) break;
			sum--;
			s.push_back(make_pair(f[poi],-1));
			--poi;
		}
		if(sum<0) sum=0;
	}
/*	for(int i=0;i<a.size();++i)
		s.push_back(make_pair(a[i],1));
	for(int i=1;i+1<f.size();++i)
		s.push_back(make_pair(f[i],-1));
*/	s.push_back(make_pair(f[0],0));
//	exit(0);
	s.push_back(make_pair(f.back(),0));
	
//	exit(0);
	sort(s.begin(),s.end());
	s.erase(unique(s.begin(),s.end()),s.end());
//	for(auto x:s) printf("[%d %d]",x.first,x.second);
//	exit(0);
	seg.build(1,0,(int)s.size()-2);
	int ans=0;
	for(int i=(int)s.size()-2;i>0;--i){
		seg.change(1,0,(int)s.size()-2,i,(int)s.size()-2,-s[i].second);
		int k=seg.search(1,0,(int)s.size()-2,0);
//		if(a.size()==3)
//			printf("|%d %d|",k,s[k+1].first-s[i-1].first-1);
		if(k>=i) ans=max(ans,s[k+1].first-s[i-1].first-1);
	}
//	printf("<%d>\n",ans);
//	exit(0);
	return ans;
}
int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	int n,x=0; scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		b[a[i]].push_back(i);
	}
	for(int i=1;i<=n;++i)
		if(b[i].size()>b[x].size()) x=i;
	f=b[x];
	f.push_back(0);
	f.push_back(n+1);
	sort(f.begin(),f.end());
//	for(auto x:f) printf("[%d]",x); puts("");
	int ans=0;
	for(int i=0;i+1<f.size();++i) ans=max(ans,f[i+1]-f[i]-1);
	for(int i=1;i<=n;++i){
		if(i==x||b[i].empty()) continue;
		ans=max(ans,solve(b[i]));
	}
	printf("%d\n",ans);
	return 0;
}