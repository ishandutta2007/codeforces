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

const int N=1005,mod=998244353;
namespace {
	inline void add(int &x,int y){
		x=(x+y>=mod?x+y-mod:x+y);
	}
	inline int fix(int x){
		return x>=mod?x-mod:x;
	}
}
int f[N][N],s[N][N],a[N],mx,n,K,ans;

int solve(int T){
	rep(i,0,n){
		memset(f[i],0,(sizeof f[i][0])*(K+2));
		memset(s[i],0,(sizeof s[i][0])*(K+2));
	}
	f[0][0]=s[0][0]=1;
	int p=0;
	//printf("# %d\n",T);
	rep(i,1,n){
		for(;a[i]-a[p+1]>=T;p++);
		rep(j,1,K){
			f[i][j]=s[p][j-1];
			s[i][j]=fix(s[i-1][j]+f[i][j]);
			//if(T==1)printf("%d %d  %d\n",i,j,f[i][j]);
		}
		s[i][0]=s[i-1][0];
	}
	//printf("%d\n",s[n][K]);
	return s[n][K];
}

int main(){
	read(n),read(K);
	rep(i,1,n){
		read(a[i]);
		mx=max(mx,a[i]);
	}
	sort(a+1,a+n+1);
	rep(T,1,mx/(K-1)+2)
		add(ans,solve(T));
	cout<<ans<<endl;
	
	return 0;
}