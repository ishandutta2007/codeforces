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

#define int ll

const int N=1e3+5,K=1e6+5;
int n,m,k,p,a[N][N],l[K],r[K],sl[N],sr[N],ans=-1e18;
multiset<int> L,R;
#define IT multiset<int>::iterator

// ----------  ---------- //

signed main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	rd(n);rd(m);rd(k);rd(p);
	for(re i=1;i<=n;++i)
		for(re j=1;j<=m;++j) rd(a[i][j]),sl[i]+=a[i][j],sr[j]+=a[i][j];
	for(re i=1;i<=n;++i) L.insert(sl[i]);
	for(re i=1;i<=m;++i) R.insert(sr[i]);
	for(re i=1;i<=k;++i){
		IT it=L.end();--it;int res=*it;l[i]=l[i-1]+res;L.erase(it);L.insert(res-p*m);
		it=R.end();--it;res=*it;r[i]=r[i-1]+res;R.erase(it);R.insert(res-p*n);
	}
	for(re i=0;i<=k;++i) ans=max(ans,l[i]+r[k-i]-i*(k-i)*p);
	wr(ans);puts("");
	return 0;
}

// ---------- Main ---------- //