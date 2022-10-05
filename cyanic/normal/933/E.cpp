#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<int(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
typedef double ld;

template<class T> inline void read(T &x){
	int f=0;x=0;char ch=getchar();
	for(;!isdigit(ch);ch=getchar())f|=(ch=='-');
	for(;isdigit(ch);ch=getchar())x=x*10+ch-'0';
	if(f)x=-x;
}

const int N=300005;
int p[N],g[N],n;
ll f[N],res;
vi ans;

void doit(int k){
	int x=min(p[k],p[k+1]);
	if(!x) return;
	ans.pb(k),p[k]-=x,p[k+1]-=x;
}

int main(){
	read(n);
	rep(i,1,n) read(p[i]);
	memset(f,0x3f,sizeof f);
	f[0]=0;
	rep(i,1,n){
		ll A=f[max(i-2,0)]+p[i];
		ll B=f[max(i-3,0)]+max(p[i],p[i-1]);
		if(A<B) f[i]=A;
		else f[i]=B,g[i]=1;
	}
	res=min(f[n],f[n-1]);
	for(int i=n-(res==f[n-1]);i>0;i=i-2-g[i]){
		doit(i-1);
		if(g[i]) doit(i-2);
		doit(i);
	}
	cout<<ans.size()<<endl;
	for(auto x:ans) printf("%d\n",x);
	return 0;
}