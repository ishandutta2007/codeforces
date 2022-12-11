#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
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
#define all(x) (x).begin(),(x).end()
//typedef pair<int,int> P;
const int mod=1e9+7;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}
#define rep(i,l,r) for (int i(l);i<=int(r);i++)
#define per(i,l,r) for (int i(r);i>=int(l);i--)

int n,m;

int t[5000010],a[5000010],b[5000010];

int sd,bs;

inline int rnd(){
	int z=sd;
	sd=(sd*1LL*bs+233)%mod;
	return z;
}

void solve(){
	n=read(),m=read();
	int lst=0;
	rep(i,1,m){
		int lim=read();
		const int k=read();
		sd=read(),bs=read();
		rep(j,lst+1,lim){
			t[j]=rnd()&1;
			a[j]=rnd()%k+1;
		}
		lst=lim;
	}
	ll C[2]={0,0};
	rep(j,1,n) C[t[j]]+=a[j];
	/*if (!min(C[0],C[1])){
		int ans=1;
		rep(i,1,n) ans=(1LL*i*i+1)%mod*ans%mod;
		printf("%d\n",ans);
		return;
	}*/
	bool f; ll S=0;
	if (C[t[1]]>C[t[1]^1]){
		f=t[1]^1;
		--a[1],++b[1];
		int p=1;
		while (p<=n&&t[p]^f) ++p;
		rep(i,p,n){
			if (t[i]==f) S+=a[i],b[i]+=a[i],a[i]=0;
			else{
				const int T=min(S,0LL+a[i]);
				a[i]-=T,S-=T,b[i]+=T;
			}
		}
		rep(i,1,n){
			if (t[i]==f) S+=a[i],b[i]+=a[i],a[i]=0;
			else{
				const int T=min(S,0LL+a[i]);
				a[i]-=T,S-=T,b[i]+=T;
			}
		}
	}
	else{
		f=t[1];
		rep(i,1,n){
			if (t[i]==f) S+=a[i],b[i]+=a[i],a[i]=0;
			else{
				const int T=min(S,0LL+a[i]);
				a[i]-=T,S-=T,b[i]+=T;
			}
		}
		rep(i,1,n){
			if (t[i]==f) S+=a[i],b[i]+=a[i],a[i]=0;
			else{
				const int T=min(S,0LL+a[i]);
				a[i]-=T,S-=T,b[i]+=T;
			}
		}
	}
	int ans=1;
	rep(i,1,n){
		ans=(((1LL*i*i)^b[i])+1)%mod*ans%mod;
	}
	printf("%d\n",ans);
}
int main()
{
	for (int T=1;T--;) solve();
	return 0;
}