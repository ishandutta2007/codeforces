#pragma GCC optimize("Ofast")
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<ctime>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define fi first
#define se second
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
typedef long long ll;
using namespace std;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
const int N = 55;
/*ll p[N],len;
struct supy {
	int k,c[N];
	int v[N][N],I[N][N],ans[N][N],C[N][N];
	inline void mul(int a[N][N], int b[N][N]) {
		rep(i,1,k) rep(j,1,k) C[i][j]=0;
		rep(i,1,k) rep(j,1,k) rep(p,1,k)
			C[i][j]^=a[i][p]*b[p][j];
		rep(i,1,k) rep(j,1,k) a[i][j]=C[i][j];
	}
	inline bool hefa(ll n) {
		memset(v,0,sizeof(v));memset(ans,0,sizeof(ans));memset(I,0,sizeof(I));
		rep(i,1,k) v[1][i]=c[i]; rep(i,2,k) v[i][i-1]=1;
		rep(i,1,k) I[i][1]=1;
		rep(i,1,k) ans[i][i]=1;
		while (n) {
			if (n&1) mul(ans,v);
			mul(v,v);
			n>>=1;
		}
		mul(ans,I);
		rep(i,1,k) if (ans[i][1]==0) return 0;
		rep(i,1,k) rep(j,2,k) if (ans[i][1]) return 1;
		return 1;
	}
	bool judge(int K) {
		k=K;
		if (!hefa((1LL<<k)-1)) return 0;
		rep(i,1,len) if (hefa(((1LL<<k)-1)/p[i])) return 0;
		return 1;
	}
} yzr;*/
ll c[N];
int main() {
	/*srand(time(0));
	rep(k,2,50) {
		int n=k; len=0; ll x=(1LL<<k)-1;
		for (int i=2; 1LL*i*i<=x; i++) if (x%i==0) {
			p[++len]=i; while (x%i==0) x/=i;
		}
		if (x>1) p[++len]=x;
		
		rep(i,1,n) yzr.c[i]=rand()%2;
		while (!yzr.judge(k)) {rep(i,1,n) yzr.c[i]=rand()%2;}
		int ans=0;
		rep(V,1,(1<<n)-1) {rep(i,1,k) yzr.c[i]=(V>>i-1)&1; ans+=yzr.judge(k);}
		cout<<1.0*ans/(1<<n);
	
		ll v=0; rep(i,1,n) v=2*v+yzr.c[i];
		printf("c[%d]=%lld;\n",k,v);
	}*/
c[2]=3;
c[3]=5;
c[4]=3;
c[5]=15;
c[6]=39;
c[7]=17;
c[8]=135;
c[9]=33;
c[10]=215;
c[11]=1743;
c[12]=3609;
c[13]=5185;
c[14]=2067;
c[15]=22253;
c[16]=56345;
c[17]=75961;
c[18]=93753;
c[19]=133289;
c[20]=1040967;
c[21]=1224705;
c[22]=4112075;
c[23]=3068581;
c[24]=12925371;
c[25]=26596291;
c[26]=15736115;
c[27]=7687009;
c[28]=228132903;
c[29]=114168825;
c[30]=92779633;
c[31]=242174617;
c[32]=828903829;
c[33]=2264549521;
c[34]=14305182863;
c[35]=28805342927;
c[36]=29592674933;
c[37]=4841103015;
c[38]=130181420021;
c[39]=97208531165;
c[40]=328409805899;
c[41]=1922589474177;
c[42]=3905780989735;
c[43]=8701297909831;
c[44]=10168172394119;
c[45]=7154050292065;
c[46]=36142454897133;
c[47]=77211859212769;
c[48]=148259268235377;
c[49]=83200397388683;
c[50]=1093184365771277;
	int k;read(k);
	per(i,k-1,0) printf("%d ",(c[k]>>i)&1); puts("");
	rep(i,1,k) printf("1 "); puts("");
	return 0;
}