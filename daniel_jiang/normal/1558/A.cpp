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
	int tmp[40]={0},cnt=0;
	while(x) tmp[cnt++]=x%10,x/=10;
	for(re i=cnt-1;i>=0;--i) putchar(tmp[i]+'0');
}

// ---------- IO ---------- //

const int N=2e5+5;
int T,n,ans[N],a,b,cnt;

// ----------  ---------- //

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	rd(T);
	while(T--){
		rd(a);rd(b);n=a+b;cnt=0;
		for(int i=0;i<=n;++i) ans[i]=0;
		if(a>b) a^=b^=a^=b;
		for(int i=0;i<=a;++i) ans[i+((n+1)/2-(a-i))]=ans[i+(n/2-(a-i))]=1;
		for(int i=0;i<=n;++i)
			if(ans[i]) ++cnt;
		wr(cnt);puts("");
		for(int i=0;i<=n;++i)
			if(ans[i]) wr(i),putchar(' ');puts("");
	}
	return 0;
}

// ---------- Main ---------- //