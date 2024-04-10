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

const int N=2e5+5;
ll n,k,x,a[N],cnt,s[N],ans;

// ----------  ---------- //

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	rd(n);rd(k);rd(x);
	for(re i=1;i<=n;++i) rd(a[i]);
	sort(a+1,a+n+1);
	for(re i=2;i<=n;++i)
		if(a[i]-a[i-1]>x) s[++cnt]=a[i]-a[i-1];
	sort(s+1,s+cnt+1);ans=cnt+1;
	for(re i=1;i<=cnt;++i){
		k-=(s[i]-1)/x;ans--;
		if(k<0){ans++;break;}
	}
	wr(ans);puts("");
	return 0;
}

// ---------- Main ---------- //