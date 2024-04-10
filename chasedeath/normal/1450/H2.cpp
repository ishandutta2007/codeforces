#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef pair <int,int> Pii;
#define reg register
#define mp make_pair
#define pb push_back
#define Mod1(x) ((x>=P)&&(x-=P))
#define Mod2(x) ((x<0)&&(x+=P))
#define rep(i,a,b) for(int i=a,i##end=b;i<=i##end;++i)
#define drep(i,a,b) for(int i=a,i##end=b;i>=i##end;--i)
int cmax(int &a,int b){ return a<b?a=b,1:0; }
int cmin(int &a,int b){ return a>b?a=b,1:0; }

char IO;
template <class T=int> T rd(){
	T s=0; int f=0;
	while(!isdigit(IO=getchar())) f|=IO=='-';
	do s=(s<<1)+(s<<3)+(IO^'0');
	while(isdigit(IO=getchar()));
	return f?-s:s;
}

const int N=2e5+10,P=998244353;

int n,m;
int I[N],J[N];
int P1[N],P2[N];
ll qpow(ll x,ll k=P-2){
	ll res=1;
	for(;k;k>>=1,x=x*x%P) if(k&1) res=res*x%P;
	return res;
}

char s[N];
int d,x,y;

int Pow2(int x){ return x<0?P2[-x]:P1[x]; }
int C(int n,int m){ return n<0||m<0||n<m?0:1ll*J[n]*I[m]%P*I[n-m]%P; }

int p1,p2,cur=1;
int SC(int n,int m) {
	if(n<0||m<0) return 0;
	if(m==0) return 1;
	if(m>=n) return Pow2(n);
	if(m==n-1) return Pow2(n)-1;

	/* Brute Force
	int sum=0;
	rep(i,0,m) sum=(sum+C(n,i))%P; 
	return sum;
	*/

	/* assertions blows
	static int fl=1; 
	assert(fl || abs(p1-n)+abs(p2-m)<=10);
	fl=0;
	*/

	while(p2>m) cur=(cur-C(p1,p2--))%P;
	while(p2<m) cur=(cur+C(p1,++p2))%P;
	while(p1<n) cur=(cur*2ll-C(p1++,p2))%P;
	while(p1>n) cur=1ll*(cur+C(--p1,p2))*(P+1)/2%P;
	//cout<<"SC "<<n<<' '<<m<<' '<<cur<<endl;
	return cur;
}
int T(int n,int m,int k){ return k==1?(SC(n,m)-T(n,m,0))%P:(n==0?m>=0:SC(n-1,m-(m&1))); }
int T(int n,int l,int r,int k){ 
	
	/*Brute Force
	int sum=0;
	rep(i,l,r) if((i&1)==k) sum=(sum+C(n,i))%P;
	return sum;
	*/

	return l>r?0:(T(n,r,k)-T(n,l-1,k))%P; 
}
int S(int n,int m){ return 1ll*n*T(n-1,m-1,0)%P; }
int S(int n,int l,int r,int k=1){

	/*Brute Force
	int sum=0;
	rep(i,l,r) if((i&1)==k) sum=(sum+1ll*i*C(n,i))%P;
	return sum;
	*/

	if(l>r) return 0;
	if(k==0) return (1ll*n*(SC(n-1,r-1)-SC(n-1,l-2))-S(n,l,r))%P;
	return (S(n,r)-S(n,l-1))%P;
}

int Que(){
	int D=d-y,n=x+y,ans=0;
	/* Brute Force
	rep(i,0,n) if((i&1)==(D&1))  {
		ans=(ans+1ll*abs(D+i)*C(n,i))%P;
	}
	*/
	if(D<0) {
		int t=-D-1;
		ans=(ans-1ll*D*T(n,t,D&1))%P;
		ans=(ans-S(n,0,t,D&1))%P;
	}
	if(D+n>=0) {
		ans=(ans+1ll*D*T(n,max(0,-D),n,D&1))%P;
		ans=(ans+S(n,max(0,-D),n,D&1))%P;
	}
	ans=1ll*(ans+P)*Pow2(-n)%P;
	return ans;
}


int main(){
	rep(i,*P1=1,N-1) P1[i]=P1[i-1]*2,Mod1(P1[i]);
	rep(i,*P2=1,N-1) P2[i]=((P2[i-1]&1)?P2[i-1]+P:P2[i-1])/2;
	rep(i,*J=1,N-1) J[i]=1ll*J[i-1]*i%P;
	I[N-1]=qpow(J[N-1]);
	drep(i,N-1,1) I[i-1]=1ll*I[i]*i%P;
	n=rd(),m=rd(),scanf("%s",s+1);
	rep(i,1,n) {
		if(s[i]=='b') i&1?d++:d--;
		if(s[i]=='?') i&1?x++:y++;
	}
	printf("%d\n",Que());
	while(m--) {
		int i=rd(),c=getchar();
		if(s[i]=='b') i&1?d--:d++;
		if(s[i]=='?') i&1?x--:y--;
		s[i]=c;
		if(s[i]=='b') i&1?d++:d--;
		if(s[i]=='?') i&1?x++:y++;
		printf("%d\n",Que());
	}
}