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

const int N=1<<17,mod=998244353;
int f[N],A[N],B[N],C[N],n,K,a,b,c,bas;
ll x,y,z;

int power(ll x,int p){
	int res=1;
	if(p<0) p+=mod;
	for(x=(x+mod)%mod;p;p>>=1,x=(ll)x*x%mod)
		if(p&1) res=(ll)res*x%mod;
	return res;
}
int fix(int x){
	return x>=mod?x-mod:x;
}
void fwt(int a[],int n){
	for(int k=0,d=1;k<n;k++,d<<=1)
		for(int i=0;i<(1<<n);i+=d<<1){
			int *l=a+i,*r=a+i+d,x,y;
			REP(j,d) x=*l,y=*r,*l++=fix(x+y),*r++=fix(x+mod-y);
		}
}

int main(){
	read(n),read(K);
	read(x),read(y),read(z);
	rep(i,1,n){
		read(a),read(b),read(c);
		bas^=a,A[a^b]++,B[a^c]++,C[b^c]++;
	}
	fwt(A,K),fwt(B,K),fwt(C,K);
	int inv2=(mod+1)/2,inv4=(inv2+mod)/2;
	REP(i,1<<K){
		int a=((ll)n+A[i]+B[i]+C[i])*inv4%mod;
		int b=((ll)n+A[i]-B[i]-C[i])*inv4%mod;
		int c=((ll)n-A[i]+B[i]-C[i])*inv4%mod;
		int d=((ll)n-A[i]-B[i]+C[i])*inv4%mod;
		f[i]=(ll)power(x+y+z,a)*power(x+y-z,b)%mod
			*power(x-y+z,c)%mod*power(x-y-z,d)%mod;
	}
	int rev=power(1<<K,mod-2);
	fwt(f,K);
	REP(i,1<<K){
		int res=(ll)f[i^bas]*rev%mod;
		printf("%d ",res);
	}
	return 0;
}