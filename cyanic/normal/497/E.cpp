#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define SZ(x) ((int)x.size())
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

const int N=32,mod=1e9+7;
int K;
struct mat{
	int a[N][N];
	mat(){
		memset(a,0,sizeof a);
	}
	void unit(){
		rep(i,0,K) a[i][i]=1;
	}
	friend mat mul(mat a,mat b){
		mat res;
		rep(i,0,K) rep(j,0,K) rep(k,0,K){
			res.a[i][k]=(res.a[i][k]+(ll)a.a[i][j]*b.a[j][k])%mod;
		}
		return res;
	}
} f[65][N],pre[N],suf[N],ans;
int num[65],n,res;
ll nn;

int main(){
	read(nn),read(K);
	while(nn){
		num[++n]=nn%K;
		nn/=K;
	}
	REP(i,K){
		rep(j,0,K){
			f[0][i].a[i][j]=1;
			f[0][i].a[j][j]=1;
		}
	}
	rep(i,1,n){
		rep(j,0,K-1){
			if(j==0) pre[j]=f[i-1][j];
			else pre[j]=mul(pre[j-1],f[i-1][j]);
		}
		per(j,K-1,0){
			if(j==K-1) suf[j]=f[i-1][j];
			else suf[j]=mul(f[i-1][j],suf[j+1]);
		}
		rep(j,0,K-1){
			f[i][j]=suf[j];
			if(j) f[i][j]=mul(f[i][j],pre[j-1]);
		}
	}
	ans.unit();
	int bas=0;
	per(i,n,1){
		rep(j,0,num[i]-1){
			ans=mul(ans,f[i-1][(bas+j)%K]);
		}
		bas=(bas+num[i])%K;
	}
	rep(i,0,K){
		res=(res+ans.a[i][K])%mod;
	}
	cout<<res<<endl;
	return 0;
}