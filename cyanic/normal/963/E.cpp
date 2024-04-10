#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<int(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
typedef double ld;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

namespace{
	const int mod=1e9+7;
	int fix(int x){
		return x>=mod?x-mod:x;
	}
	int mul(int x,int y){
		return (ll)x*y%mod;
	}
	int power(int x,int p){
		int res=1;
		for(;p;p>>=1,x=(ll)x*x%mod)
			if(p&1)res=(ll)res*x%mod;
		return res;
	}
	int Div(int x,int y){
		return mul(x,power(y,mod-2));
	}
	void add(int &x,int y){
		x=(x+y>=mod?x+y-mod:x+y);
	}
	void sub(int &x,int y){
		x=(x-y<0?x-y+mod:x-y);
	}
}

vi operator + (vi a,vi b){
	if(b.size()>a.size()) a.resize(b.size());
	REP(i,b.size()) add(a[i],b[i]);
	return a;
}
vi operator - (vi a,vi b){
	if(b.size()>a.size()) a.resize(b.size());
	REP(i,b.size()) sub(a[i],b[i]);
	return a;
}
vi operator * (vi a,int b){
	REP(i,a.size()) a[i]=mul(a[i],b);
	return a;
}

const int N=105;
int yes[N][N],l[N],r[N],a[N][N],x[N];
int R,p1,p2,p3,p4;
vi c[N][N];

void Gauss(int n){
	rep(i,1,n){
		int k=-1;
		rep(j,i,n) if(a[j][i]){ k=j; break; }
		assert(k!=-1);
		if(k!=i) rep(j,i,n+1) swap(a[k][j],a[i][j]);
		rep(j,i+1,n){
			if(!a[j][i]) continue;
			int t=Div(mod-a[j][i],a[i][i]);
			rep(k,i,n+1) add(a[j][k],mul(t,a[i][k]));
		}
	}
	per(i,n,1){
		x[i]=Div(a[i][n+1],a[i][i]);
		per(j,i-1,1) sub(a[j][n+1],mul(x[i],a[j][i]));
	}
}

int main(){
	read(R);
	read(p1),read(p2);
	read(p3),read(p4);
	int sum=p1+p2+p3+p4;
	p1=Div(p1,sum),p2=Div(p2,sum);
	p3=Div(p3,sum),p4=Div(p4,sum);
	rep(i,0,2*R+2) rep(j,0,2*R+2) c[i][j].resize(2*R+2);
	rep(i,1,2*R+1){
		int k=abs(R+1-i);
		l[i]=r[i]=R+1;
		for(int t=1;t*t+k*k<=R*R;t++) l[i]--,r[i]++;
		rep(j,l[i],r[i]+1) yes[j][i]=1;
		c[l[i]][i][i]=1;
		yes[l[i]][i]=2;
	}
	int inv=Div(1,p3); vi one(2*R+2); one[0]=1;
	rep(x,2,2*R+2) rep(y,1,2*R+1)
		if(yes[x][y]==1){
			c[x][y]=(c[x-1][y]-c[x-2][y]*p1-c[x-1][y-1]*p2
					-c[x-1][y+1]*p4-one)*inv;
		}
	rep(i,1,2*R+1){
		rep(j,1,2*R+1) a[i][j]=c[r[i]+1][i][j];
		a[i][2*R+2]=fix(mod-c[r[i]+1][i][0]);
	}
	Gauss(2*R+1);
	int ans=c[R+1][R+1][0];
	rep(i,1,2*R+1) add(ans,mul(c[R+1][R+1][i],x[i]));
	cout<<ans<<endl;
	return 0;
}