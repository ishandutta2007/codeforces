#include <bits/stdc++.h>
#define rep0(i,r) for (int i=0,i##end=r;i<i##end;++i)
#define rep(i,l,r) for (int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define pr pair<ll,int>
#define mp make_pair
#define fi first
#define se second
#define ll long long
#define pb push_back
#define db long double
using namespace std;
const int N=21,S=1<<N; int n,cnt[S];
struct poly{
	int f[S];
	int& operator [] (int i){ return f[i]; }
	bool zero(){
		rep(s,0,(1<<n)-1) if (f[s]) return false;
		return true;
	}
	void FMT(int op,int g[N][S]){
		if (op==1)
			rep(i,1,n)
				rep(s,0,(1<<n)-1)
					g[i][s]=cnt[s]==i?f[s]:0;
		rep(i,1,n)
			rep(j,1,n)
				rep(s,0,(1<<n)-1)
					if (s>>j-1&1) g[i][s]+=g[i][s^(1<<j-1)]*op;
		if (op==-1) 
			rep(s,0,(1<<n)-1) f[s]=g[cnt[s]][s];
	}
}g[N];
poly operator * (poly a,poly b){
	static int a_[N][S],b_[N][S],c_[N][S];
	rep(i,1,n) rep(s,0,(1<<n)-1) c_[i][s]=0;
	a.FMT(1,a_),b.FMT(1,b_);
	rep(i,1,n) rep(j,1,n-i)
		rep(s,0,(1<<n)-1) c_[i+j][s]+=a_[i][s]*b_[j][s];
	a.FMT(-1,c_); return a;
}
ll a[N],b[S]; int l[2]; pr val[2][S];
void calc(int p,int q,int w){
	ll s=0; rep(i,p,q) s+=b[i];
	val[w][l[w]=1]=mp(0,0);
	rep(i,p,q){
		int k=0; static pr tmp[S];
		for (int x=1,y=1;x<=l[w]||y<=l[w];)
			if (x<=l[w]&&(y>l[w]||val[w][x].fi+b[i]<val[w][y].fi))
				tmp[++k].fi=val[w][x].fi+b[i],tmp[k].se=val[w][x++].se+1;
			else tmp[++k]=val[w][y],tmp[k].se=val[w][y++].se;
		l[w]=k; rep(j,1,k) val[w][j]=tmp[j];
	}
	rep(i,1,l[w]) val[w][i].fi=2*val[w][i].fi-s;
}
int main(){
	scanf("%d",&n);
	rep(s,1,(1<<n)-1) cnt[s]=cnt[s^(s&-s)]+1;
	rep(i,1,n){
		scanf("%lld",&a[i]); if (a[i]==0) --i,--n;
	}
	rep(s,1,(1<<n)-1){
		int m=0,v=0;
		rep(i,1,n) if (s>>i-1&1) b[++m]=a[i],v+=a[i];
		if ((v%2+2)%2!=(m+1)%2) continue;
		calc(1,m>>1,0),calc((m>>1)+1,m,1);
		bool ok=false;
		for (int i=1,j=1;i<=l[0];++i){
			while (j<=l[1]&&val[0][i].fi-val[1][j].fi>=m) ++j;
			for (int k=j;k<=l[1];++k){
				if (val[1][k].fi-val[0][i].fi>=m) break;
				int c=val[0][i].se+m-(m>>1)-val[1][k].se;
				if (0<c&&c<m){ ok=true; break; }
			}
			if (ok) break;
		}
		if (ok) g[0][s]=1;
	}
	if (g[0].zero()){ printf("%d\n",n); return 0; }
	for (int j=1;;++j){
		g[j]=g[j-1]*g[j-1];
		if (g[j].zero()){
			poly f=g[j-1]; int s=1<<j-1;
			per(k,j-2,0){
				poly h=f*g[k];
				if (!h.zero()) f=h,s+=1<<k;
			}
			printf("%d\n",n-s);
			return 0;
		}
	}
}