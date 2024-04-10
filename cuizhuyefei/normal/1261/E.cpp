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
const int N = 1066;
int n,a[N],id[N];
bitset<N>ans[N];int sz;
bool cmp(int x, int y){return a[x]<a[y];}
int main() {
	read(n);rep(i,1,n)read(a[i]),id[i]=i;
	sort(id+1,id+n+1,cmp);
	per(i,n,1){//a[id[i]]
		int need=min(a[id[i]],n-i+1)-1;
		++sz;ans[sz][id[i]]=1;rep(j,i+1,n)if(a[id[j]]>=n-i+1)ans[sz][id[j]]=1;
		rep(j,1,sz-1)if(need){
			ans[j][id[i]]=1;need--;
			if(ans[j]==ans[sz]){need++;ans[j][id[i]]=0;}
		}
		if(need){
			assert(min(a[id[i]],n-i+1)==n-i+1&&need==1);
			ans[++sz][id[i]]=1;
		}
	}
	printf("%d\n",sz);
	rep(i,1,sz){rep(j,1,n)printf("%d",(int)ans[i][j]);puts("");}
	return 0;
}