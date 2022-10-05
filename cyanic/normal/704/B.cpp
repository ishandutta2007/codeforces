#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
#define fi first
#define se second
#define pb emplace_back
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

const int N=5005;
const ll inf=1e18;
int x[N],a[N],b[N],c[N],d[N],n,s,t,S,T;
ll f[N][N];

void up(ll &x,ll y){
	if(y<x)x=y;
}

int main(){
	read(n),read(s),read(t);
	rep(i,1,n)read(x[i]);
	rep(i,1,n)read(a[i]);
	rep(i,1,n)read(b[i]);
	rep(i,1,n)read(c[i]);
	rep(i,1,n)read(d[i]);
	memset(f,0x3f,sizeof f);
	f[0][0]=0,S=T=1;
	rep(i,1,n){
		rep(j,0,i-1)
			if(f[i-1][j]<=inf){
				if(i==s){
					if(j>=1)   up(f[i][j],f[i-1][j]+x[i]+c[i]);
					up(f[i][j+1],f[i-1][j]-x[i]+d[i]);
					continue;
				}
				if(i==t){
					if(j>=1)   up(f[i][j],f[i-1][j]+x[i]+a[i]);
					up(f[i][j+1],f[i-1][j]-x[i]+b[i]);
					continue;
				}
				if(j-1+S+T>=1) up(f[i][j+1],f[i-1][j]-x[i]-x[i]+d[i]+b[i]);
				if(j-1>=1)	   up(f[i][j-1],f[i-1][j]+x[i]+x[i]+a[i]+c[i]);
				if(j-1+S>=1)   up(f[i][j],f[i-1][j]+b[i]+c[i]);
				if(j-1+T>=1)   up(f[i][j],f[i-1][j]+d[i]+a[i]);
			}
		if(i==s)S=0;
		if(i==t)T=0;
	}
	cout<<f[n][1]<<endl;
	return 0;
}