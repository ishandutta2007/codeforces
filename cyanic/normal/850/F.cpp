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

const int N=100005,mod=1e9+7;
int a[N],f[N],n,sum,mx,ans;

int power(int x,int p){
	int res=1;
	for(;p;p>>=1,x=(ll)x*x%mod)
		if(p&1)res=(ll)res*x%mod;
	return res;
}
int mul(int x,int y){
	return (ll)x*y%mod;
}
int fix(int x){
	return x>=mod?x-mod:x;
}

int main(){
	read(n);
	rep(i,1,n){
		read(a[i]);
		mx=max(mx,a[i]);
		sum+=a[i];
	}
	f[1]=mul(mul(sum-1,sum-1),power(sum,mod-2));
	rep(i,1,mx-1){
		int t=mul(sum-1,power(sum-i,mod-2));
		f[i+1]=fix(fix(f[i]+f[i])+mod-fix(f[i-1]+t));
	}
	rep(i,1,n) ans=fix(ans+f[a[i]]);
	cout<<ans<<endl;
	return 0;
}