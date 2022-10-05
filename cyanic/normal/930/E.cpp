#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

namespace{
	const int mod=1e9+7;
	const int inv2=(mod+1)>>1;
	int power(int x,int p){
		int res=1;
		for(;p;p>>=1,x=(ll)x*x%mod)
			if(p&1)res=(ll)res*x%mod;
		return res;
	}
	int fix(int x){
		return x>=mod?x-mod:x;
	}
	int mul(int x,int y){
		return (ll)x*y%mod;
	}
	void add(int &x,int y){
		x=(x+y>=mod?x+y-mod:x+y);
	}
	void sub(int &x,int y){
		x=(x-y<0?x+mod-y:x-y);
	}
}

const int N=500005;
struct node{
	int l,r;
	friend bool operator < (node a,node b){
		return a.l<b.l||a.l==b.l&&a.r>b.r;
	}
}a[N],b[N];
int xx[N],F[N],G[N],f[N],g[N],s[N];
int len,n,m,cnt;

void init(){
	read(len),read(n),read(m);
	rep(i,1,n) read(a[i].l),read(a[i].r);
	rep(i,1,m) read(b[i].l),read(b[i].r);
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	int nn=0,mm=0;
	rep(i,1,n){
		while(nn&&a[nn].r>=a[i].r) nn--;
		a[++nn]=a[i];
	}
	rep(i,1,m){
		while(mm&&b[mm].r>=b[i].r) mm--;
		b[++mm]=b[i];
	}
	n=nn,m=mm;
	xx[++cnt]=0,xx[++cnt]=len;
	rep(i,1,n){
		xx[++cnt]=a[i].l-1;
		xx[++cnt]=a[i].r;
	}
	rep(i,1,m){
		xx[++cnt]=b[i].l-1;
		xx[++cnt]=b[i].r;
	}
	sort(xx+1,xx+cnt+1);
	cnt=unique(xx+1,xx+cnt+1)-xx-1;
	rep(i,1,n){
		a[i].l=lower_bound(xx+1,xx+cnt+1,a[i].l-1)-xx+1;
		a[i].r=lower_bound(xx+1,xx+cnt+1,a[i].r)-xx;
	}
	rep(i,1,m){
		b[i].l=lower_bound(xx+1,xx+cnt+1,b[i].l-1)-xx+1;
		b[i].r=lower_bound(xx+1,xx+cnt+1,b[i].r)-xx;
	}
}

int main(){
	init(); s[1]=1;
	for(int i=2,p=0,q=0;i<=cnt;i++){
		for(;p<n&&a[p+1].r<=i;p++);
		for(;q<m&&b[q+1].r<=i;q++);
		s[i]=mul(s[i-1],power(2,xx[i]-xx[i-1]));
		F[i]=F[i-1],G[i]=G[i-1];
		if(a[p].r==i){
			sub(f[i],fix(F[i-1]+mod-F[a[p].l-1]));
			sub(f[i],s[a[p].l-1]);
			add(F[i],f[i]);
			add(s[i],f[i]);
		}
		if(b[q].r==i){
			sub(g[i],fix(G[i-1]+mod-G[b[q].l-1]));
			sub(g[i],s[b[q].l-1]);
			add(G[i],g[i]);
			add(s[i],g[i]);
		}
	}
	cout<<s[cnt]<<endl;
	return 0;
}