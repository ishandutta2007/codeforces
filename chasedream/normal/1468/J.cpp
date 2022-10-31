// author: xay5421
// created: Fri Dec 25 20:04:48 2020
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
const int N=200005;
int T,n,m,K,fa[N];
int pp,lnk[N],nxt[N*2],to[N*2],we[N*2];
void ae(int k1,int k2,int k3){to[++pp]=k2,we[pp]=k3,nxt[pp]=lnk[k1],lnk[k1]=pp;}
int fd(int k1){return fa[k1]==k1?k1:fa[k1]=fd(fa[k1]);}
signed main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(T);
	while(T--){
		rd(n),rd(m),rd(K);
		vector<array<int,3> >e;
		rep(i,1,m){
			int k1,k2,k3;
			rd(k1),rd(k2),rd(k3);
			e.push_back({k3,k1,k2});
		}
		sort(e.begin(),e.end());
		int cnt=0;
		int sum=0;
		rep(i,1,n)fa[i]=i;
		int mx=0;
		rep(i,0,SZ(e)-1){
			if(fd(e[i][1])!=fd(e[i][2])){
				fa[fd(e[i][1])]=fd(e[i][2]);
				if(e[i][0]>=K)sum+=e[i][0]-K;
				if(++cnt==n-1){
					mx=e[i][0];
					break;
				}
			}
		}
		if(mx<=K){
			int res=0X3F3F3F3F;
			rep(i,0,SZ(e)-1)res=min(res,abs(K-e[i][0]));
			pt(res,'\n');
		}else{
			pt(sum,'\n');
		}
	}
	return 0;
}