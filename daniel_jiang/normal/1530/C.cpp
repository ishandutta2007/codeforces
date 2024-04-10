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

const int N=1e5+5;
int T,n,a[N],b[N],ans,sum1,sum2;

inline bool ok(int k){
	sum1=sum2=0;
	for(re i=(k+n)/4+1;i<=k+n;++i)
		if(i<=n) sum1+=a[i];
		else sum1+=100;
	for(re i=(k+n)/4+1;i<=k+n;++i)
		if(i>k) sum2+=b[i-k];
//	cout<<k<<' '<<sum1<<' '<<sum2<<endl;
	if(sum1>=sum2) return 1;
	return 0;
}

// ----------  ---------- //

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	rd(T);
	while(T--){
		rd(n);ans=sum1=sum2=0;
		for(re i=1;i<=n;++i) rd(a[i]);
		for(re i=1;i<=n;++i) rd(b[i]);
		sort(a+1,a+n+1);sort(b+1,b+n+1);
		int l=0,r=n*2;
		while(l<=r){
			int mid=(l+r)/2;
			if(ok(mid)) r=mid-1,ans=mid;
			else l=mid+1;
		}
		wr(ans);puts("");
	}
	return 0;
}

// ---------- Main ---------- //