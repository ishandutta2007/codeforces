#include<bits/stdc++.h> 
using namespace std;

#define reg register
typedef long long ll;
typedef unsigned int ui;
#define rep(i,a,b) for(int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(int i=a,i##end=b;i>=i##end;--i)

#define pb push_back
template <class T> inline void cmin(T &a,T b){ if(a>b) a=b; }
template <class T> inline void cmax(T &a,T b){ if(a<b) a=b; }

char IO;
int rd(){
	int s=0;
	int f=0;
	while(!isdigit(IO=getchar())) if(IO=='-') f=1;
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}

const int N=2e5+10,P=998244353;

int n,m,L,R;
struct Mat{
	ll a[2][2];
	void clear(){ memset(a,0,sizeof a); }
	Mat operator * (const Mat x) const {
		Mat res; res.clear();
		rep(i,0,1) rep(j,0,1) rep(k,0,1) res.a[i][k]=(res.a[i][k]+a[i][j]*x.a[j][k])%P;
		return res;
	}
} x,res;



int main(){
	n=rd(),m=rd(),L=rd()-1,R=rd();
	int a=(R+1)/2-(L+1)/2,b=R/2-L/2;
	rep(i,0,1) rep(j,0,1) x.a[i][j]=(i^j)?a:b;
	rep(i,0,1) res.a[i][i]=1;
	ll k=1ll*n*m;
	for(;k;k>>=1,x=x*x) if(k&1) res=res*x;
	ll ans=0;
	//cout<<"#"<<res.a[0][0]<<' '<<res.a[0][1]<<endl;
	if((1ll*n*m)&1) ans=(res.a[0][0]+res.a[0][1])%P;
	else ans=res.a[0][0];
	printf("%lld\n",ans);
}