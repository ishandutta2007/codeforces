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
const int N = 666666;
int n,ans,ans1,ans2,id[N],qz[N],a[N];char S[N];
void ini(int *a, int p){
	static int b[N];int l=0;
	rep(i,p,n)b[++l]=a[i];
	rep(i,1,p-1)b[++l]=a[i];
	rep(i,1,n)a[i]=b[i];
}
void upd(int l, int r, int a){
	if(a>ans){
		ans=a;ans1=l;ans2=r+1<=n?r+1:1;
	}
}
int main() {
	read(n);scanf("%s",S+1);rep(i,1,n)id[i]=i,a[i]=S[i]=='('?1:-1;
	rep(i,1,n)qz[i]=qz[i-1]+a[i];
	ans1=1;ans2=1;int p=1;rep(i,2,n)if(qz[i]<qz[p])p=i;
	if(qz[n]){printf("%d\n%d %d\n",ans,ans1,ans2);return 0;}
	rep(i,1,n)ans+=qz[p]==qz[i];
	ini(a,p+1<=n?p+1:1);ini(id,p+1<=n?p+1:1);rep(i,1,n)qz[i]=qz[i-1]+a[i],assert(qz[i]>=0);
	rep(i,1,n)if(qz[i]==1){
		int cnt=0,j=i;while(j+1<=n&&qz[j+1]>=1)j++;
		rep(k,i,j)cnt+=qz[k]==1;
		//[i,j]
		upd(id[i],id[j],cnt);
		i=j;
	}
	int ori=0;rep(i,1,n)ori+=qz[i]==0;
	rep(i,1,n)if(qz[i]==2){
		int cnt=0,j=i;while(j+1<=n&&qz[j+1]>=2)j++;
		rep(k,i,j)cnt+=qz[k]==2;
		//[i,j]
		upd(id[i],id[j],cnt+ori);
		i=j;
	}
	printf("%d\n%d %d\n",ans,ans1,ans2);
	return 0;
}