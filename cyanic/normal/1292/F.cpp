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

template<class T> void read(T &x){
	int f=0; x=0; char ch=getchar();
	for(;!isdigit(ch);ch=getchar()) f|=(ch=='-');
	for(;isdigit(ch);ch=getchar()) x=x*10+ch-'0';
	if(f) x=-x;
}

const int N=65,M=1<<15,mod=1e9+7;
int pa[N],a[N],key[N],c[N],C[N][N];
int n,m,tot,res=1;
vi v[N];

int gp(int x){
	return pa[x]==x?x:pa[x]=gp(pa[x]);
}
void add(int &x,int y){
	x=(x+y>=mod?x+y-mod:x+y);
}

int f[N][M];
int solve(vi v){
	int n=v.size();
	REP(i,n) fill(f[i],f[i]+M,0);
	REP(i,n) add(f[0][c[v[i]]],1);
	REP(i,n-1) REP(s,1<<m){
		if(!f[i][s]) continue;
		int tot=0;
		REP(j,n){
			if(!(s&c[v[j]])) continue;
			if((s&c[v[j]])==c[v[j]]) tot++;
			else add(f[i+1][s|c[v[j]]],f[i][s]);
		}
		add(f[i+1][s],(ll)f[i][s]*(tot-i-1)%mod);
	}
	int res=0;
	REP(s,1<<m) add(res,f[n-1][s]);
	return res;
}

int main(){
	read(n);
	rep(i,1,n) read(a[i]),pa[i]=i;
	sort(a+1,a+n+1);
	per(i,n,1){
		int flag=1;
		rep(j,1,i-1) flag&=(a[i]%a[j]!=0);
		rep(j,i+1,n) flag|=(a[j]%a[i]==0)<<1;
		if(flag<3) continue;
		key[i]=++m;
		rep(j,i+1,n) if(a[j]%a[i]==0) c[j]|=1<<(m-1);
		rep(j,i+1,n) rep(k,j+1,n)
			if(a[j]%a[i]==0&&a[k]%a[i]==0) pa[gp(j)]=gp(k);
	}
	rep(i,1,n) v[gp(i)].pb(i);
	C[0][0]=1;
	rep(i,1,n){
		C[i][0]=1;
		rep(j,1,i) C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	rep(i,1,n) if(v[i].size()>=2){
		int ans=solve(v[i]);
		int sz=v[i].size();
		res=(ll)res*ans*C[tot+sz-1][sz-1]%mod;
		tot+=sz-1;
	}
	cout<<res<<endl;
	return 0;
}