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
const int N = 1020000;
int n,m,a[N],ID[N];
Vi ans[N];
bool cmp(int x, int y){return a[x]<a[y];}
int main() {
	read(n);read(m);
	ll s=0;rep(i,1,m)read(a[i]),s+=a[i];s%=n;
	if(s)a[1]+=n-s;
	s=0;rep(i,1,m)s+=a[i];s/=n;
	rep(i,0,s)ans[i].resize(m+1);
	int *id=ID;
	int sz=m;rep(i,1,m)id[i]=i;sort(id+1,id+sz+1,cmp);
	int cur=m;
	for(int j=s;j>=1&&cur;){
		if(a[id[sz]]>=n){
			int p=id[sz];rep(i,1,cur)ans[j][i]=p;a[p]-=n;j--;
			if(!a[p])sz--;sort(id+1,id+sz+1,cmp);
			continue;
		}
		assert(sz<=cur&&j<=sz);
		if(sz<cur){rep(i,1,j)ans[i][cur]=1;cur--;continue;}
		ans[0][cur]=a[id[1]];rep(i,1,j)ans[i][cur]=id[i],a[id[i]]-=ans[0][cur];
		int q=1;while(q<=sz&&!a[id[q]])q++;sz=sz-q+1;id=id+q-1;
		n-=ans[0][cur];cur--;
	}
	ans[0][cur]=n;
	printf("%d\n",s);
	rep(i,0,s){rep(j,1,SZ(ans[i])-1)printf("%d ",ans[i][j]);puts("");}
	return 0;
}