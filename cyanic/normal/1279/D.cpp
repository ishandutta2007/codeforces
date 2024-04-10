#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi frist
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

const int N=1000005,mod=998244353;
int c[N],inv[N],n,x,y,ans;
vi a[N];

int main(){
	read(n);
	rep(i,1,n){
		read(x);
		a[i].resize(x);
		REP(j,x){
			read(a[i][j]);
			c[a[i][j]]++;
		}
	}
	inv[1]=1;
	rep(i,2,1000000){
		inv[i]=(ll)(mod-mod/i)*inv[mod%i]%mod;
	}
	rep(i,1,n){
		REP(j,SZ(a[i])){
			ans=(ans+(ll)inv[n]*inv[SZ(a[i])]%mod
						*inv[n]%mod*c[a[i][j]])%mod;
		}
	}
	cout<<ans<<endl;
	return 0;
}