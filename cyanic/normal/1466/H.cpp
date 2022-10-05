#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
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

const int mod=1e9+7,N=45;
int fac[N],rev[N],p[N],vis[N],n;
vi c;

int power(int x,int p){
	int res=1;
	for(;p;p>>=1,x=(ll)x*x%mod){
		if(p&1) res=(ll)res*x%mod;
	}
	return res;
}

int C(int n,int m){
	return m<0||m>n?0:(ll)fac[n]*rev[m]%mod*rev[n-m]%mod;
}

void init(){
	fac[0]=1;
	rep(i,1,n){
		fac[i]=(ll)fac[i-1]*i%mod;
	}
	rev[n]=power(fac[n],mod-2);
	per(i,n,1){
		rev[i-1]=(ll)rev[i]*i%mod;
	}
}

map<vi,int> f;

int solve(vi c);

int dfs(int k,vi now,vi &c,int coef){
//	printf("dfs %d  %d\n",k,coef);
//	for(auto x:now) printf("%d ",x); puts("");
//	for(auto x:c) printf("%d ",x); puts("");
	if(k==n){
		vi rem(n);
		int cnt=0,tot=0;
		REP(i,n){
			rem[i]=c[i]-now[i];
			cnt+=now[i]*(i+1);
			tot+=rem[i]*(i+1);
		}
		if(!cnt) return 0;
		int val,sum=0;
		rep(i,0,tot){
			val=(ll)fac[i]*fac[n-1-i]%mod*C(tot,i)%mod;
			sum=(sum+val)%mod;
		}
		coef=(ll)coef*power(sum,cnt)%mod;
		return (ll)solve(rem)*coef%mod;
	}
	int res=0;
	rep(i,0,c[k]){
		now.pb(i);
		int cc=coef;
		cc=(ll)cc*C(c[k],i)%mod;
		if(i&1) cc=mod-cc;
		res=(res+dfs(k+1,now,c,cc))%mod;
		now.pop_back();
	}
	return res;
}

int solve(vi c){
	if(f.count(c)) return f[c];
	vi owo;
	int res=dfs(0,owo,c,mod-1);
	f[c]=res;
	return res;
}

int main(){
	read(n),init();
	rep(i,1,n){
		read(p[i]);
	}
	c.resize(n);
	f[c]=1;
	rep(i,1,n){
		if(vis[i]) continue;
		int x=p[i],cnt=0;
		for(;x!=i;x=p[x]){
			vis[x]=1,cnt++;
		}
		vis[x]=1,cnt++;
//		cerr<<"#"<<cnt<<endl;
		c[cnt-1]++;
	}
	cout<<solve(c)<<endl;
	return 0;
}