#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
#define ALL(x) (x).begin(),(x).end()
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

const int N=55;
const ll inf=2e18;
ll f[N][N][N][2][2][2][2],g[2][N][N][2][2][2][2];
ll l[N],r[N],c[N];
int n,K,kk;

int calc(int k,int i,int a,int b){
	if(i<1||n<i) return -1;
	if(!b){
		if(!a) return l[i]>>k&1;
		return r[i]>>k&1;
	}
	if((l[i]>>(k+1))==(r[i]>>(k+1))) return -2;
	if(!a){
		if((l[i]>>k&1)==1) return -2;
		return 1;
	}
	if((r[i]>>k&1)==0) return -2;
	return 0;
}

ll cost(int k,int a,int b){
	if(a==-1||b==-1) return 0;
	return (a^b)*c[k];
}

ll F(int k,int l,int m,int r,int la,int lb,int ra,int rb);

ll G(int k,int l,int r,int la,int lb,int ra,int rb){
	if(k!=kk) return g[0][l][r][la][lb][ra][rb];
	ll &res=g[1][l][r][la][lb][ra][rb];
	if(res<=inf) return res; else res=inf;
	int U=calc(k,l-1,la,lb),D=calc(k,r+1,ra,rb);
	if(U==-2||D==-2) return res;
	res=G(k+1,l,r,la,0,ra,0)+cost(k,U,D);
	rep(m,l,r){
		res=min(res,F(k,l,m,r,la,lb,ra,rb));
	}
	return res;
}

ll F(int k,int l,int m,int r,int la,int lb,int ra,int rb){
	ll &res=f[l][m][r][la][lb][ra][rb];
	if(res<=inf) return res; else res=inf;
	REP(t,2){
		res=min(res,G(k,l,m-1,la,lb,t,1)+G(k,m+1,r,t,1,ra,rb));
		if(!k){
			res=min(res,G(k,l,m-1,la,lb,t,0)+G(k,m+1,r,t,0,ra,rb));
		}
	}
	return res;
}

int main(){
	read(n),read(K);
	rep(i,1,n){
		read(l[i]),read(r[i]);
	}
	REP(i,K){
		read(c[i]);
	}
	memset(g[0],0x3f,sizeof g[0]);
	rep(l,1,n+1){
		REP(la,2) REP(ra,2) g[0][l][l-1][la][0][ra][0]=0;
	}
	per(k,K-1,0){
		kk=k;
		memset(f,0x3f,sizeof f);
		memset(g[1],0x3f,sizeof g[1]);
		rep(l,1,n+1) rep(r,l-1,n){
			REP(la,2) REP(lb,2){
				REP(ra,2) REP(rb,2){
					G(k,l,r,la,lb,ra,rb);
				}
			}
		}
		swap(g[0],g[1]);
	}
	cout<<g[0][1][n][0][0][0][0]<<endl;
	return 0;
}