#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
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
 
const int M=1000005,N=1005,mod=998244353;
int f[N][N],a[M],mx[N][N],p[N][N];
vi pos[N];
int n,m;
 
int del(int a[],int n){
	int cnt=1;
	rep(i,2,n)if(a[i]!=a[cnt])a[++cnt]=a[i];
	return cnt;
}
 
int main(){
	read(n),read(m);
	rep(i,1,m)read(a[i]);
	m=del(a,m);
	if(m>2*n+1){
		puts("0");
		return 0;
	}
	rep(i,1,m){
		pos[a[i]].pb(i);
	}
	rep(l,1,m){
		mx[l][l]=a[l],p[l][l]=l;
		rep(r,l+1,m)
			if(a[r]<mx[l][r-1]){
				mx[l][r]=a[r];
				p[l][r]=r;
			}
			else{
				mx[l][r]=mx[l][r-1];
				p[l][r]=p[l][r-1];
			}
	}
	rep(i,1,m+1)f[i][i-1]=1;
	per(l,m,1){
		rep(r,l,m){
			int x=p[l][r],v=a[x];
			if(pos[v].front()<l||r<pos[v].back())
				continue;
			int L=0,R=0;
			f[l][r]=1;
			for(int i=0;i+1<pos[v].size();i++)
				f[l][r]=(ll)f[l][r]*f[pos[v][i]+1][pos[v][i+1]-1]%mod;
			x=pos[v].front();
			rep(i,l,x)
				L=(L+(ll)f[l][i-1]*f[i][x-1])%mod;
			x=pos[v].back();
			rep(i,x,r)
				R=(R+(ll)f[i+1][r]*f[x+1][i])%mod;
			f[l][r]=(ll)f[l][r]*L%mod*R%mod;
		}
	}
	cout<<f[1][m]<<endl;
	return 0;
}