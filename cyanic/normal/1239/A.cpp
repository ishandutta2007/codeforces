#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=(0);i<(n);i++)
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

const int N=200005,mod=1e9+7;
int f[N],n,m,ans;

int power(int x,int p){
	int res=1;
	for(;p;p>>=1,x=(ll)x*x%mod)
		if(p&1)res=(ll)res*x%mod;
	return res;
}

int main(){
	read(n),read(m);
	f[1]=1,f[2]=2;
	rep(i,3,100000)
		f[i]=(f[i-1]+f[i-2])%mod;
	ans=(f[n]+f[m])%mod;
	ans=2*ans%mod;
	ans=(ans+mod-2)%mod;
	cout<<ans<<endl;

	return 0;
}