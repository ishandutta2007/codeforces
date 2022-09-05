#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 105,mo=1e9+7, inf =0x3f3f3f3f;
inline int power(ll a, ll n, int mo=1e9+7) {
	int res=1;a%=mo;
	while (n) {
		if (n&1) res=1LL*res*a%mo;
		a=1LL*a*a%mo; n>>=1;
	}
	return res;
}
int n,A[N],B[N],mi[N],g[N],ex[N];vector<Pii>pr[N],ans;
vector<Pii> operator *(vector<Pii> a, int b){rep(i,0,SZ(a)-1)a[i].se*=b;return a;}
vector<Pii> operator +(vector<Pii> a, vector<Pii> b){
	sort(a.begin(),a.end());sort(b.begin(),b.end());vector<Pii>c;
	int p1=0,p2=0;
	while(p1<SZ(a)||p2<SZ(b)){
		int x=min(p1<SZ(a)?a[p1].fi:inf,p2<SZ(b)?b[p2].fi:inf),y=0;
		if(p1<SZ(a)&&a[p1].fi==x)y+=a[p1++].se;
		if(p2<SZ(b)&&b[p2].fi==x)y+=b[p2++].se;
		c.pb(Pii(x,y));
	}
	return c;
}
vector<Pii>getfac(int n){
	vector<Pii>res;
	for(int i=2;i*i<=n;i++)if(n%i==0){
		int x=0;while(n%i==0)n/=i,x++;res.pb(Pii(i,x));
	}
	if(n>1)res.pb(Pii(n,1));
	return res;
}
bool ckans(){
//	rep(i,0,SZ(ans)-1)cerr<<ans[i].fi<<' '<<ans[i].se<<endl;
	rep(t,1,n){
		vector<Pii>need=ans,c=getfac(A[t]);//cerr<<SZ(c)<<endl;
		rep(i,0,SZ(c)-1){
			bool find=0;
			rep(j,0,SZ(need)-1)if(need[j].fi==c[i].fi){
				find=1;need[j].se-=c[i].se;if(need[j].se<0)return 0;
				break;
			}
			if(!find)return 0;
		}
		rep(i,0,SZ(need)-1)if(!need[i].se)need.erase(need.begin()+i),i--;
	//	cerr<<SZ(need)<<endl;
		if(need.empty())continue;if(SZ(need)!=SZ(pr[t]))return 0;
		int x=need[0].se/pr[t][0].se;
		rep(i,0,SZ(need)-1)if(need[i].fi!=pr[t][i].fi||need[i].se!=pr[t][i].se*x)return 0;
	}
	return 1;
}
int getcnt(int x, int y){int r=0;while(x%y==0)x/=y,r++;return r;}
int cons[33],isprime[33],phi[33];bool vis[33];
int AA[N],BB[N];
int main() {
	read(n);
	rep(i,1,n){
		read(A[i]);read(B[i]);pr[i]=getfac(B[i]);AA[i]=A[i];BB[i]=B[i];
		mi[i]=1;g[i]=B[i];
		per(j,30,2)if(power(pow(B[i],1.0/j)+1e-6,j)==B[i]){
			g[i]=pow(B[i],1.0/j)+1e-6;mi[i]=j;break;
		}
	//	cout<<g[i]<<' '<<mi[i]<<endl;
	}
	rep(i,1,n)if(B[i]==1){
		ans=getfac(A[i]);
		if(!ckans())puts("-1");
		else{int res=A[i];printf("%d\n",res);}
		return 0;
	}
	rep(i,1,n)rep(j,i+1,n)if(g[i]!=g[j]){
		static int a[N];int len=0;
		rep(k,0,SZ(pr[i])-1)a[++len]=pr[i][k].fi;
		rep(k,0,SZ(pr[j])-1)a[++len]=pr[j][k].fi;
		rep(k,1,len)rep(l,k+1,len)if(a[k]!=a[l]){
			ll A=getcnt(BB[i],a[k]),B=-getcnt(BB[j],a[k]),C=getcnt(BB[i],a[l]),D=-getcnt(BB[j],a[l]);
			if(1LL*A*D-1LL*C*B){
				ll E=getcnt(AA[j],a[k])-getcnt(AA[i],a[k]),F=getcnt(AA[j],a[l])-getcnt(AA[i],a[l]);
				ll x=(E*D-F*B)/(A*D-C*B),y=B?(E-A*x)/B:(F-C*x)/D;
			//	cerr<<x<<' '<<y<<endl;
				if(A*x+B*y!=E||C*x+D*y!=F||x<0||y<0){puts("-1");return 0;}
			//	cerr<<x<<' '<<y<<endl;
				ans=pr[i]*x+getfac(AA[i]);
				if(!ckans())puts("-1");
				else{int res=1;rep(i,0,SZ(ans)-1)res=1LL*res*power(ans[i].fi,ans[i].se)%mo;printf("%d\n",res);}
				return 0;
			}
		}
		return 0;
	}
	rep(i,1,n)while(A[i]%g[i]==0)A[i]/=g[i],ex[i]++;
	rep(i,1,n)if(A[1]!=A[i]){puts("-1");return 0;}
	memset(cons,-1,sizeof(cons));
	isprime[2]=isprime[3]=isprime[5]=isprime[7]=isprime[11]=isprime[13]=isprime[17]=isprime[19]=isprime[23]=isprime[29]=1;
	rep(i,1,n){//ex[i]+(?)*mi[i]
		rep(j,1,mi[i])if(isprime[j]&&mi[i]%j==0){
			int x=j;while(x<=mi[i]&&mi[i]%x==0){
				if(cons[x]>=0&&cons[x]!=ex[i]%x){puts("-1");return 0;}cons[x]=ex[i]%x,x*=j;
			}
		}
	}
	rep(j,1,30)if(isprime[j]&&cons[j]>=0){
		int x=j;while(j*x<=30&&cons[j*x]>=0)x*=j;vis[x]=1;phi[x]=x/j*(j-1);
	}
	ll MO=1,res=0;rep(j,1,30)if(vis[j])MO*=j;
	rep(j,1,30)if(vis[j]){
	//    assert(power(MO/j,phi[j],j)==1);
	//    assert((MO/j)*power(MO/j,phi[j]-1,j)%j==1);
		res=(res+cons[j]*(MO/j)*power(MO/j,phi[j]-1,j))%MO;
	}
	while(1){
		bool gg=0;rep(i,1,n)if(res<ex[i])gg=1;
		if(gg)res+=MO;else break;
	}
//	cout<<MO<<' '<<res<<endl;
	rep(i,1,n)assert(res>=ex[i]&&(res-ex[i])%mi[i]==0);
	printf("%lld\n",1LL*power(g[1],res,mo)*A[1]%mo);
	return 0;
}