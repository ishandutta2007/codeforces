#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int mo = 1e9+7;
inline void add(int &x, int y){x=x+y<mo?x+y:x+y-mo;}
inline int power(int a, int n) {
	int res=1;
	while (n) {
		if (n&1) res=1LL*res*a%mo;
		a=1LL*a*a%mo; n>>=1;
	}
	return res;
}
int n,bh[131],a[9][9],cnt[131],sz[9];Vi sta[9];
map<ll,int>Map;
int main() {
	read(n);
	rep(i,1,n)rep(j,1,n)
		read(a[i][j]),a[i][j]=1LL*a[i][j]*power(100,mo-2)%mo;
	rep(s,0,(1<<n)-1){
		rep(i,0,n-1)cnt[s]+=s>>i&1;
		bh[s]=sz[cnt[s]]++;sta[cnt[s]].pb(s);
	}
	rep(s,0,(1<<n)-1){
		int tmp=1;
		rep(i,1,n)if(s>>i-1&1)tmp=1LL*tmp*a[i][1]%mo;
		else tmp=1LL*tmp*(1-a[i][1]+mo)%mo;
		Map[s]=tmp;
	}
	rep(j,2,n){
		map<ll,int>Map1;
		for(map<ll,int>::iterator it=Map.begin();it!=Map.end();it++){
			int xs=(*it).se;ll ori=(*it).fi;
			rep(s,0,(1<<n)-1){
				int tmp=xs;
				rep(i,1,n)if(s>>i-1&1)tmp=1LL*tmp*a[i][j]%mo;
				else tmp=1LL*tmp*(1-a[i][j]+mo)%mo;
				//*tmp
				ll x=0;
				rep(i,0,SZ(sta[j-1])-1)if(ori>>i&1){
					rep(k,1,n)if((s>>k-1&1)&&!(sta[j-1][i]>>k-1&1))
						x|=1ll<<bh[sta[j-1][i]|(1<<k-1)];
				}
				add(Map1[x],tmp);
			}
		}
		Map=Map1;Map1.clear();
	}
	printf("%d\n",Map[1]);
	return 0;
}