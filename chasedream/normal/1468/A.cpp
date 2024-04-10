// author: xay5421
// created: Fri Dec 25 19:36:22 2020
#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define int long long
#define LL long long
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define X first
#define Y second
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
typedef pair<int,int>PII;
typedef vector<int>VI;
typedef vector<PII>VII;
template<typename T>void umin(T&x,const T&y){if(y<x)x=y;}
template<typename T>void umax(T&x,const T&y){if(x<y)x=y;}
template<typename T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<typename T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
const int N=500005,INF=0X3F3F3F3F;
int T,n,a[N],t[N],f[N],st[N],top,L[N];
vector<int>ask[N];
void upd(int k1,int k2){
	++k1;
	for(int i=k1;i<=n+1;i+=i&-i)t[i]=max(t[i],k2);
}
int qry(int k1){
	++k1;
	int k2=~INF;
	for(int i=k1;i;i&=i-1)k2=max(k2,t[i]);
	return k2;
}
signed main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(T);
	while(T--){
		rd(n);
		rep(i,1,n)rd(a[i]);
		rep(i,0,n+1)t[i]=~INF,f[i]=0,ask[i].clear();
		top=0;
		per(i,n,1){
			while(top&&a[i]>=a[st[top]])L[st[top]]=i,--top;
			st[++top]=i;
		}
		rep(i,1,top)L[st[i]]=0;
		rep(i,1,n){
			if(L[i])ask[L[i]-1].push_back(i);
		}
		int ans=0;
		rep(i,0,n){
			if(i){
				f[i]=max(f[i],qry(a[i])+1);
			}
			upd(a[i],f[i]);
			for(auto&x:ask[i]){
				f[x]=max(f[x],qry(a[x])+2);
			}
			ans=max(ans,f[i]);
			//D("f[%lld]=%lld\n",i,f[i]);
		}
		pt(ans,'\n');
	}
	return 0;
}