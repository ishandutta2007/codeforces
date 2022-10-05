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

const int N=405;
int mod;
struct Tr{
	int a[N][N],n;
	void add(int x,int y){
		a[x][x]++,a[y][y]++;
		a[x][y]=(a[x][y]+mod-1)%mod;
		a[y][x]=(a[y][x]+mod-1)%mod;
	}
	int power(int x,int p){
		int res=1;
		for(;p;p>>=1,x=(ll)x*x%mod)
			if(p&1)res=(ll)res*x%mod;
		return res;
	}
	int solve(){
		int res=1;n--;
		rep(i,1,n){
			int k=0;
			rep(j,i,n)if(a[j][i])k=j;
			if(!k)return 0;
			if(k!=i){
				res=mod-res;
				rep(j,i,n+1)swap(a[k][j],a[i][j]);
			}
			rep(j,i+1,n){
				int t=mod-(ll)a[j][i]*power(a[i][i],mod-2)%mod;
				rep(k,i,n+1)
					a[j][k]=(a[j][k]+(ll)a[i][k]*t)%mod;
			}
		}
		rep(i,1,n)res=(ll)res*a[i][i]%mod;
		return res;
	}
}T[2];
int id[N][N],pa[N*N],cur[N*N],n,m,cnt;
char s[N][N];

int getpa(int x){
	return pa[x]==x?x:pa[x]=getpa(pa[x]);
}

int main(){
	read(n),read(m),read(mod);
	rep(i,1,n)scanf("%s",s[i]+1);
	rep(i,0,n)rep(j,0,m)
		id[i][j]=++cnt,pa[cnt]=cnt;
	rep(i,1,n)rep(j,1,m)
		if(s[i][j]=='\\')pa[getpa(id[i-1][j-1])]=getpa(id[i][j]);
		else if(s[i][j]=='/')pa[getpa(id[i-1][j])]=getpa(id[i][j-1]);
	rep(i,0,n)rep(j,0,m)
		if(pa[id[i][j]]==id[i][j])
			cur[id[i][j]]=++T[(i+j)&1].n;
	rep(i,1,n)rep(j,1,m)
		if(s[i][j]=='*'){
			T[(i+j)&1].add(cur[getpa(id[i-1][j-1])],cur[getpa(id[i][j])]);
			T[~(i+j)&1].add(cur[getpa(id[i-1][j])],cur[getpa(id[i][j-1])]);
		}
	printf("%d\n",(T[0].solve()+T[1].solve())%mod);
	return 0;
}