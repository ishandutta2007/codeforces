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
ll n,l,r,a[N],b[N],id[N],sum,ans;

inline bool cmp(int x,int y){
	return b[x]<b[y];
}

// ----------  ---------- //

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	rd(n);
	for(re i=1;i<=n;++i) rd(a[i]),rd(b[i]),id[i]=i;
	sort(id+1,id+n+1,cmp);
	l=1;r=n;
	while(l<=r){
		while(sum>=b[id[l]]&&l<=r) ans+=a[id[l]],sum+=a[id[l]],l++;
		while(sum<b[id[l]]&&l<=r){
			if(a[id[r]]>b[id[l]]-sum) ans+=(b[id[l]]-sum)*2,a[id[r]]-=b[id[l]]-sum,sum+=b[id[l]]-sum;
			else ans+=a[id[r]]*2,sum+=a[id[r]],--r;
		}
	}
	wr(ans);puts("");
	return 0;
}

// ---------- Main ---------- //