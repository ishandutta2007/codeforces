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
ll n,a[N],c[N],ans,id[N],maxn;

inline bool cmp(int x,int y){
	return a[x]<a[y];
}

// ----------  ---------- //

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	rd(n);
	for(re i=1;i<=n;++i) rd(a[i]),rd(c[i]),id[i]=i,ans+=c[i];
	sort(id+1,id+n+1,cmp);
	maxn=a[id[1]]+c[id[1]];
	for(re i=2;i<=n;++i){
		ans+=max(0ll,a[id[i]]-maxn);
		maxn=max(maxn,a[id[i]]+c[id[i]]);
	}
	wr(ans);puts("");
	return 0;
}

// ---------- Main ---------- //