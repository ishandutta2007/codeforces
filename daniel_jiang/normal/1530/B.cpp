// wish to get better qwq

#include<bits/stdc++.h>
#define re register int
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define dec(x) fixed<<setprecision(x)

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template<class T> inline void rd(T &x){
	int fl=1;x=0;char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') fl=-fl;
	for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
	x*=fl;
}
template<class T> inline void wr(T x){
	if(x<0) x=-x,putchar('-');
	if(x<10){putchar(x+'0');return ;}
	int tmp[30]={0},cnt=0;
	while(x) tmp[cnt++]=x%10,x/=10;
	for(re i=cnt-1;i>=0;--i) putchar(tmp[i]+'0');
}

// ---------- IO ---------- //

const int N=30;
int T,n,m,ans[N][N];

// ----------  ---------- //

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	rd(T);
	while(T--){
		memset(ans,0,sizeof(ans));
		rd(n);rd(m);
		for(re i=1;i<=n;i+=2) ans[i][1]=1;
		for(re i=1;i<=m;i+=2) ans[1][i]=1;
		for(re i=3;i<=n;i+=2) ans[i][m]=1;
		for(re j=3;j<=m-2;j+=2) ans[n][j]=1;
		for(re i=1;i<=n;++i,puts(""))
			for(re j=1;j<=m;++j) wr(ans[i][j]);puts("");
	}
	return 0;
}

// ---------- Main ---------- //