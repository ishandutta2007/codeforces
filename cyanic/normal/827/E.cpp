#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
typedef vi poly;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=(1<<20)+5,mod=998244353;
int power(int x,int p){
	int res=1;
	for(;p;p>>=1,x=(ll)x*x%mod)
		if(p&1)res=(ll)res*x%mod;
	return res;
}
void add(int &x,int y){
	x=(x+y>=mod?x+y-mod:x+y);
}
namespace Poly{
	void dft(poly &A,int n){
		static ull w[N<<1],*W=w,*H[30],mx=0;
		for(;mx<n;mx++){
			H[mx]=W; ull w=1,wn=power(3,(mod-1)>>(mx+1));
			REP(i,1<<mx) *W++=w,w=w*wn%mod;
		}
		static ull a[N]; A.resize(1<<n);
		for(int i=0,j=0;i<(1<<n);i++){
			a[i]=A[j];
			for(int k=1<<(n-1);(j^=k)<k;k>>=1);
		}
		for(int k=0,d=1;k<n;k++,d<<=1)
			for(int i=0;i<(1<<n);i+=d<<1){
				ull *l=a+i,*r=a+i+d,*w=H[k];
				for(int j=0;j<d;j++,l++,r++){
					ull t=*r*(*w++)%mod;
					*r=*l+mod-t,*l+=t;
				}
			}
		REP(i,1<<n) A[i]=a[i]%mod;
	}
	void idft(poly &a,int n){
		a.resize(1<<n);
		reverse(a.begin()+1,a.end());
		dft(a,n);
		ull inv=power(1<<n,mod-2);
		REP(i,1<<n) a[i]=a[i]*inv%mod;
	}
	poly mul(poly a,poly b){
		int aim=a.size()+b.size();
		int n=0; while((1<<n)<aim) n++;
		dft(a,n),dft(b,n);
		REP(i,1<<n) a[i]=(ll)a[i]*b[i]%mod;
		idft(a,n),a.resize(aim-1);
		return a;		
	}
}

int ans[N],n;
poly A,B,C;
char s[N];

void rmain(){
	read(n),scanf("%s",s+1);
	A.resize(n+1),B.resize(n+1);
	rep(i,1,n) A[i]=(s[i]=='V');
	rep(i,1,n) B[i]=(s[n+1-i]=='K');
	C=Poly::mul(A,B),ans[n]=0;
	rep(i,1,n-1) ans[i]=C[n+i+1]+C[n-i+1];
	rep(i,1,n){
		for(int j=i+i;j<=n;j+=i) add(ans[i],ans[j]);
	}
	vi res;
	rep(i,1,n) if(!ans[i]) res.pb(i);
	printf("%d\n",(int)res.size());
	for(auto x:res) printf("%d ",x);
	puts("");
}

int main(){
	int T; read(T);
	while(T--) rmain();
	return 0;
}