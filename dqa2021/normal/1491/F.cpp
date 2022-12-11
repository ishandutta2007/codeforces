#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef unsigned long long ull;
typedef unsigned uint;
typedef long long ll;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
#define fi first
#define se second
/*
const int mod=;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}
*/
//typedef pair<int,int> P;
#define rep(i,l,r) for (int i(l);i<=int(r);i++)
#define per(i,l,r) for (int i(r);i>=int(l);i--)

int n;
void solve(){
	n=read();
	int p=-1,q=-1;
	rep(i,2,n){
		printf("? %d %d\n",i-1,1);
		rep(j,1,i-1) printf("%d ",j); puts("");
		printf("%d \n",i);
		fflush(stdout);
		if (read()){
			p=i; break;
		}
	}
	int l=1,r=p-1;
	while (l<r){
		int mid=l+r>>1;
		printf("? %d %d\n",mid-l+1,1);
		rep(i,l,mid) printf("%d ",i); puts("");
		printf("%d \n",p);
		fflush(stdout);
		if (read()) r=mid;
		else l=mid+1;
	}
	q=l;
	vector<int> S;
	rep(i,1,p-1) if (i^q) S.pb(i);
	rep(i,p+1,n){
		printf("? 1 1\n%d \n%d \n",p,i);
		fflush(stdout);
		if (!read()) S.pb(i);
	}
	printf("! %d",int(S.size()));
	for (int x: S) printf(" %d",x);
	puts("");
	fflush(stdout);
}
int main()
{
	for (int T=read();T--;) solve();
	return 0;
}