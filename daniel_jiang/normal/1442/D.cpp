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

const int N=3e3+5;
int n,k;
ll ans,t[N],s[N];
vector<ll> a[N],f;

#define mid ((l+r)>>1)

inline void solve(int l,int r){
//	cout<<l<<' '<<r<<endl;
//	for(re i=0;i<=k;++i) cout<<f[i]<<' ';cout<<"qaq"<<endl; 
	if(l==r){
		ll sum=0;
		for(re i=0;i<k&&i<t[l];++i) sum+=a[l][i],ans=max(ans,f[k-i-1]+sum);
//		cout<<ans<<endl;
		return ;
	}
	vector<ll> tmp=f;
	for(re i=l;i<=mid;++i)
		for(re j=k;j>=t[i];--j) f[j]=max(f[j-t[i]]+s[i],f[j]);
	solve(mid+1,r);
	f=tmp;
	for(re i=mid+1;i<=r;++i)
		for(re j=k;j>=t[i];--j) f[j]=max(f[j-t[i]]+s[i],f[j]);
	solve(l,mid);
}

// ----------  ---------- //

int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	rd(n);rd(k);f.resize(k+10);
	for(re i=1;i<=n;++i){
		rd(t[i]);ll x;
		for(re j=1;j<=t[i];++j) rd(x),a[i].pb(x),s[i]+=x;
	}
	solve(1,n);wr(ans);puts("");
	return 0;
}

// ---------- Main ---------- //