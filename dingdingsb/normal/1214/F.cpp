// Problem: CF1214F Employment
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1214F
// Memory Limit: 500 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
template<typename T>
inline void read(T &x){x=0;char c=getchar();bool f=false;for(;!isdigit(c);c=getchar())f|=c=='-';for(;isdigit(c);c=getchar())x=x*10+c-'0';if(f)x=-x;}
template<typename T ,typename ...Arg>inline void read(T &x,Arg &...args){read(x);read(args...);}
template<typename T>inline void write(T x){if(x<0)putchar('-'),x=-x;if(x>=10)write(x/10);putchar(x%10+'0');}
const int N=6e5+100;
typedef long long ll;
int n;ll m;pair<int,int> x[N],y[N];
int a[N],b[N];
ll delta[N];int ans[N];
void add(int l,int r,int k){
	delta[l]+=k,delta[r+1]-=k;
}
signed main(){
	read(m,n);
	for(int i=1;i<=n;i++)//
		read(x[i].fi),x[i].se=i;
	sort(x+1,x+n+1);
	for(int i=1;i<=n;i++)//
		read(y[i].fi),y[i].se=i;
	sort(y+1,y+n+1);
	for(int i=1;i<=n;i++)b[i]=x[i].fi-m;
	for(int i=1;i<=n;i++)b[i+n]=x[i].fi;
	for(int i=1;i<=n;i++)b[i+n+n]=x[i].fi+m;
	for(int i=1;i<=n;i++)a[i]=y[i].fi,delta[0]+=a[i];
	for(int i=1;i<=n;i++){
		int j=upper_bound(b+1,b+1+3*n,a[i])-b;
		if(j>i&&j<=i+2*n)delta[j-i]-=2*a[i];
	}
	for(int i=1;i<=3*n;i++){
		if(i<=n){
			add(0,i-1,-b[i]);
			continue;
		}
		if(i>n*2){
			add(i-n,n*2,b[i]);
			continue;
		}
		int j=lower_bound(a+1,a+1+n,b[i])-a;
		add(i-j+1,i-1,b[i]);
		add(i-n,i-j,-b[i]);
	}
	pair<ll,int>_={delta[0],0};
	for(int i=1;i<=2*n;i++){
		delta[i]+=delta[i-1];
		_=min(_,make_pair(delta[i],i));
	}
	write(_.fi);putchar('\n');
	int id=_.se;
	for(int i=1;i<=n;i++)ans[x[(i+id-1)%n+1].se]=y[i].se;
	for(int i=1;i<=n;i++)write(ans[i]),putchar(' ');
}