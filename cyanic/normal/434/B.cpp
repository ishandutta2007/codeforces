#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
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

const int N=1005;
struct rect{
	int a[N][N],U[N][N],D[N][N],n,m;
	void flip(int x,int y,int flag=1){
		a[x][y]^=1;
		if(!flag) return;
		rep(i,x,n) if(a[i][y]){
			if(a[i-1][y]) U[i][y]=U[i-1][y];
			else U[i][y]=i;
		}
		per(i,x,1) if(a[i][y]){
			if(a[i+1][y]) D[i][y]=D[i+1][y];
			else D[i][y]=i;
		}
	}
	void doit(int y){
		rep(i,1,n) if(a[i][y]){
			if(a[i-1][y]) U[i][y]=U[i-1][y];
			else U[i][y]=i;
		}
		per(i,n,1) if(a[i][y]){
			if(a[i+1][y]) D[i][y]=D[i+1][y];
			else D[i][y]=i;
		}
	}
	int qry(int x,int y){
		int ans=0,uu=U[x][y],dd=D[x][y];
		per(i,y,1){
			if(!a[x][i]) break;
			uu=max(uu,U[x][i]);
			dd=min(dd,D[x][i]);
			ans=max(ans,(y-i+1)*(dd-uu+1));
		}
		return ans;
	}
} A,B,C,D;
int a[N][N],n,m,Q,op,x,y;

int main(){
	read(n),read(m),read(Q);
	A.n=n,A.m=m,B.n=n,B.m=m;
	C.n=m,C.m=n,D.n=m,D.m=n;
	rep(i,1,n) rep(j,1,m){
		read(a[i][j]);
		if(a[i][j]==1){
			A.flip(i,j,0);
			B.flip(i,m+1-j,0);
			C.flip(j,i,0);
			D.flip(j,n+1-i,0);
		}
	}
	rep(i,1,m){
		A.doit(i);
		B.doit(i);
	}
	rep(i,1,n){
		C.doit(i);
		D.doit(i);
	}
	while(Q--){
		read(op),read(x),read(y);
		if(op==1){
			A.flip(x,y);
			B.flip(x,m+1-y);
			C.flip(y,x);
			D.flip(y,n+1-x);
		}
		else{
			int ans=A.qry(x,y);
			ans=max(ans,B.qry(x,m+1-y));
			ans=max(ans,C.qry(y,x));
			ans=max(ans,D.qry(y,n+1-x));
			printf("%d\n",ans);
		}
	}
	return 0;
}