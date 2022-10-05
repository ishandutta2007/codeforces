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

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=1005,mod=1e9+7;
int C[N][N],coef[N],f[N],a[N],n,ans;
char s[N];

int power(int x,int p){
	int res=1;
	for(;p;p>>=1,x=(ll)x*x%mod)
		if(p&1)res=(ll)res*x%mod;
	return res;
}

int solve(int k){
	int res=0,bas=0;
	fill(f+1,f+n+1,0);
	per(i,n,1){
		int A=min(k,a[i]),B=a[i]-A;
		rep(j,0,i-1){
			int tmp=(ll)power(k,i-1-j)*power(10-k,j)%mod;
			f[bas+j]=(f[bas+j]+(ll)C[i-1][j]*A*tmp)%mod;
			f[bas+j+1]=(f[bas+j+1]+(ll)C[i-1][j]*B*tmp)%mod;
		}
		bas+=(a[i]>=k);
	}
	rep(i,1,n) res=(res+(ll)f[i]*coef[i])%mod;
	return res;
}

int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	rep(i,1,n) a[i]=s[n+1-i]-'0';
	a[1]++;
	int k=1;
	while(a[k]>=10) a[k]=0,a[k+1]++,k++;
	n=max(n,k);
	C[0][0]=1;
	rep(i,1,n){
		C[i][0]=1;
		rep(j,1,i) C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	coef[1]=1;
	rep(i,1,n) coef[i]=(10ll*coef[i-1]+1)%mod;
	rep(k,1,9) ans=(ans+solve(k))%mod;
	cout<<ans<<endl;
	return 0;
}