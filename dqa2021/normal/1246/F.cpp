#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned uint;
#define G getchar()
int read()
{
	int x=0; bool flg=false; char ch=G;
	for (;!isdigit(ch);ch=G) if (ch=='-') flg=true;
	for (;isdigit(ch);ch=G) x=(x<<3)+(x<<1)+(ch^48);
	return flg?-x:x;
}
#undef G
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
//typedef pair<int,int> P;
/*const int mod=;
inline int upd(const int &x){return x+(x>>31&mod);}
inline void add(int &x,const int &y){x=upd(x+y-mod);}
inline void iadd(int &x,const int &y){x=upd(x-y);}
int qpow(int x,int y){
	int res=1;
	for (;y;y>>=1,x=1LL*x*x%mod)
		if (y&1) res=1LL*res*x%mod;
	return res;
}*/
#define rep(i,l,r) for (int i(l),_##i(r);i<=_##i;i++)
#define per(i,l,r) for (int i(r),_##i(l);i>=_##i;i--)
#define forall(x,y) for (const int &y: e[x])
const int INF=1e6;

char s[100010]; int n;
int L[100010],R[100010];
ll ans;

int pre[100010][26],suf[100010][26];
int a[100010][26],b[100010][26];

int lj[17][100010],rj[17][100010];
ll lw[17][100010],rw[17][100010];

int mx[100010],mn[100010];

void work(int o){
	//printf("work %d\n",o);
	/*memset(lj,0,sizeof lj);
	memset(rj,0,sizeof rj);
	memset(lw,0,sizeof lw);
	memset(rw,0,sizeof rw);*/
	rep(i,1,n){
		int &mn=::mn[i];
		const int &p=b[i][o-1];
		if (p!=n+1) mn=min(mn,pre[p-1][s[p]-'a']);
		mn=max(mn,1);
		
		lj[0][i]=mn,lw[0][i]=mn;
		rep(j,1,16)
			lj[j][i]=lj[j-1][lj[j-1][i]],
			lw[j][i]=lw[j-1][i]+lw[j-1][lj[j-1][i]];
	}
	per(i,1,n){		
		int &mx=::mx[i];
		const int &p=a[i][o-1];
		if (p) mx=max(mx,suf[p+1][s[p]-'a']);
		mx=min(mx,n);
		
		rj[0][i]=mx,rw[0][i]=mx;
		rep(j,1,16)
			rj[j][i]=rj[j-1][rj[j-1][i]],
			rw[j][i]=rw[j-1][i]+rw[j-1][rj[j-1][i]];
	}
	
	static int lim[100010],c[26],d;
	memset(c,0,sizeof c); d=0;
	for (int i=n,l=n+1,r=n;i;--i){
		if (!(c[s[--l]-'a']++)) ++d;
		while (d>o) d-=!--c[s[r--]-'a'];
		lim[i]=r;
	}
	
	const auto check=[&](int l,int r){
		return r<=lim[l];
	};
	
	rep(i,1,n){
		int &l=L[i],&r=R[i];
		if (!check(l,r)) continue;
		per(j,0,16){
			if (check(lj[j][l],rj[j][r]))
				ans+=1LL*(n-1)*(1<<j)-rw[j][r]+lw[j][l],
				l=lj[j][l],r=rj[j][r];
		}
		ans+=n-1-rw[0][r]+lw[0][l];
		l=lj[0][l],r=rj[0][r];
		
		//printf("  test pos %d o %d: %d %d\n",i,o,l,r);
	}
}

void solve(){
	scanf("%s",s+1); n=strlen(s+1);
	
	//fill(pre[0],pre[0]+26,INF);
	rep(i,1,n){
		memcpy(pre[i],pre[i-1],26<<2);
		pre[i][s[i]-'a']=i;
		memcpy(a[i],pre[i],26<<2);
		sort(a[i],a[i]+26,greater<int>());
	}
	fill(suf[n+1],suf[n+1]+26,/*-INF*/n+1);
	per(i,1,n){
		memcpy(suf[i],suf[i+1],26<<2);
		suf[i][s[i]-'a']=i;
		memcpy(b[i],suf[i],26<<2);
		sort(b[i],b[i]+26);
	}
	rep(i,1,n) mx[i]=mn[i]=i;
	
	rep(i,1,n) L[i]=R[i]=i,ans+=n-1;
	rep(t,1,26) work(t);
	printf("%lld\n",ans);
}

int main()
{
	for (int T=1;T--;) solve();
	return 0;
}