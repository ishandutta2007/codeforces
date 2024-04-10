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

const int N=513;
int x[N],y[N],K,n,m,ans;
ll a[N][N],b[N][N];

int main(){
	read(K),n=1<<K;
	REP(i,n) REP(j,n) read(a[i][j]);
	read(m);
	rep(i,1,m) read(x[i]),read(y[i]);
	REP(k,K){
		swap(a,b),memset(a,0,sizeof a);
		rep(c,1,m) REP(i,n) REP(j,n)
			a[(i+x[c])&(n-1)][(j+y[c])&(n-1)]^=b[i][j];
		rep(c,1,m) x[c]=(x[c]<<1)&(n-1),y[c]=(y[c]<<1)&(n-1);
	}
	REP(i,n) REP(j,n) ans+=(a[i][j]>0);
	cout<<ans<<endl;
	return 0;
}