#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef __uint128_t ull;
//typedef unsigned long long ull;
typedef double db;
typedef pair <int,int> Pii;
#define reg register
#define mp make_pair
#define pb push_back
#define Mod1(x) ((x>=P)&&(x-=P))
#define Mod2(x) ((x<0)&&(x+=P))
#define rep(i,a,b) for(int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(int i=a,i##end=b;i>=i##end;--i)
template <class T> inline void cmin(T &a,T b){ ((a>b)&&(a=b)); }
template <class T> inline void cmax(T &a,T b){ ((a<b)&&(a=b)); }

char IO;
template <class T=int> T rd(){
	T s=0; int f=0;
	while(!isdigit(IO=getchar())) f|=IO=='-';
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}

const int N=25,M=1<<20,INF=1e9+10;
const ull D=1000;

int n,m;
ll A[N],S[M];
int c[M],chk[M];
ull F[21][M],G[21][M];
ll X[1<<10],Y[1<<10];
int C;
ll B[N];

ll Fix(ll x,ll y){
	return floor((long double)x/y);
	//return x>0?x/y:(x-y+1)/y;
}
int Norm(ull &x){
	ull T=1,c=0;
	while(T*D<=x) T*=D,c++;
	return x=T,c;
}
void FMT(ull *F){
	for(int i=1;i<=m;i<<=1) {
		for(int l=0;l<=m;l+=i*2) {
			for(int j=l;j<l+i;++j) {
				F[j+i]+=F[j];
			}
		}
	}
}
void IFMT(ull *F){
	for(int i=1;i<=m;i<<=1) {
		for(int l=0;l<=m;l+=i*2) {
			for(int j=l;j<l+i;++j) {
				F[j+i]-=F[j];
			}
		}
	}
}

int main() {
	rep(i,1,rd()) {
		ll x=rd<ll>();
		if(x) A[n++]=x;
	}
	if(!n) return puts("0"),0;
	sort(A,A+n,greater<ll>()),m=(1<<n)-1;
	//rep(i,0,n-1) cout<<A[i]<<' ';
	//puts("");
	rep(i,1,m) S[i]=S[i&(i-1)]+A[__lg(i&-i)];
	rep(i,1,m) {
		c[i]=c[i&(i-1)]+1;
		rep(j,0,n-1) if(i&(1<<j)) chk[i]|=chk[i^(1<<j)];
		if(chk[i]) { chk[i]=2; continue; }
		if((S[i]&1)==(c[i]&1)) continue;
		if(c[i]>=10) {
			ll l1=Fix(S[i]-c[i]+2,2),r2=Fix(S[i]+c[i]-1,2);
			ll r1=Fix(S[i]-(~c[i]&1),2),l2=Fix(S[i]+(~c[i]&1)+1,2);
			
			C=0;
			rep(j,0,n-1) if(i&(1<<j)) B[C++]=A[j];
			int k=C/2;
			rep(j,1,(1<<k)-1) X[j]=X[j&(j-1)]+B[__lg(j&-j)];
			rep(j,1,(1<<(C-k))-1) Y[j]=Y[j&(j-1)]+B[__lg(j&-j)+k];
			sort(X,X+(1<<k)),sort(Y,Y+(1<<(C-k)));
			int p1=(1<<(C-k))-1,p2=p1;
			rep(j,0,(1<<k)-1) {
				while(~p1 && X[j]+Y[p1]>r1) p1--;
				while(~p2 && X[j]+Y[p2]>r2) p2--;
				if(~p1 && X[j]+Y[p1]>=l1) {
					//if(i==19) cout<<"$"<<X[j]+Y[p1]<<endl;
					chk[i]=1;
					break;
				}
				if(~p2 && X[j]+Y[p2]>=l2) {
					//if(i==19) cout<<"$"<<X[j]+Y[p1]<<endl;
					chk[i]=1;
					break;
				}
			}
		} else {
			for(int j=i&(i-1);j>=(j^i);j=(j-1)&i) {
				ll d=abs(S[i^j]-S[j]);
				if(d<c[i]) {
					//if(i==19) cout<<d<<endl;
					chk[i]=1;
					break;
				}
			}
		}
	}
	//rep(i,1,m) if(n==12 && chk[i]==1) cout<<"$"<<i<<' '<<chk[i]<<endl;
	rep(i,1,m) if(chk[i]==1) {
		G[c[i]][i]=D;
		//rep(j,0,n-1) if(i&(1<<j)) cout<<A[j]<<' ';
		//puts("");
	}
	int ans=0;
	F[0][0]=1;
	rep(i,2,n) FMT(G[i]);
	rep(i,0,n) {
		if(i) IFMT(F[i]);
		rep(j,(1<<i)-1,m-(1<<(n-i))+1) if(F[i][j]) {
			//cout<<"$"<<i<<' '<<j<<' '<<F[i][j]<<endl;
			if(c[j]!=i) F[i][j]=0;
			else cmax(ans,Norm(F[i][j]));
		}
		if(i+2<=n) {
			FMT(F[i]);
			rep(j,2,n-i) rep(S,0,m) F[i+j][S]+=F[i][S]*G[j][S];
		}
	}
	printf("%d\n",n-ans);
}