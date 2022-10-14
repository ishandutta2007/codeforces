// writer: w33z8kqrqk8zzzx33
#include <bits/stdc++.h>
using namespace std;

#define iter(i, a, b) for(int i=(a); i<(b); i++)
#define rep(i, a) iter(i, 0, a)
#define rep1(i, a) iter(i, 1, (a)+1)
#define all(a) a.begin(), a.end()
#define fi first
#define se second
#define pb push_back
#define mp make_pair
 
using ll=long long;
using pii=pair<int, int>;
//#define int ll
// const int MOD = 1000000007;

 
namespace poly {
	const int MOD = 998244353;
	const int IMAG = 86583718;
	const int NTTG = 3;
	
	int rev[4500000];
	int minv[4500000];
	int w[8400000];
	
	int qpow(int b, int e) {
		int re=1;
		while(e){
			if(e&1)re=1ll*re*b%MOD;
			b=1ll*b*b%MOD;e>>=1;
		}
		return re;
	}
	
	void constructrev(int n) {
		for(int i=1, j=0; i < n; i++) {
			int bit=n>>1;
			for(;j&bit;bit>>=1)j^=bit;
			j^=bit; rev[i] = j;
		}
	}
 
	void constructroot(int n) {
		minv[1] = 1;
		iter(i, 2, n+1)
			minv[i]=1ll*(MOD-MOD/i)*minv[MOD%i]%MOD;
		for(int l=1; (1<<l)<=n; l++) {
            int re = qpow(NTTG,(MOD-1)>>l);
            w[(1<<l)|0] = 1;
            rep1(i,(1<<(l-1))-1) w[(1<<l)|i] = 1ll*w[(1<<l)|(i-1)]*re%MOD;
        }
	}
	
	void ntt(int *v, int n, bool inv) {
        if(inv) reverse(v+1, v+n);
		rep(i, n) if(i < rev[i]) swap(v[i], v[rev[i]]);
		for(int l=1;(1<<l)<=n;l++)
			for(int i=0;i<n;i+=(1<<l)) {
				int p=i+(1<<(l-1));
				iter(j, i, p) {
					int a=v[j],b=1ll*v[j+(1<<(l-1))]*w[(1<<l)|(j-i)]%MOD;
					v[j]=(a+b>=MOD?a+b-MOD:a+b);
					v[j+(1<<(l-1))]=(a<b?a+MOD-b:a-b);
				}
			}
		if(inv) rep(i, n) v[i] = 1ll*v[i]*minv[n]%MOD;
	}
	
	void mult(int *a, int as, int *b, int bs, int *o, bool construct, bool clean = 0, int th = 100000000) {
		int n = as+bs-1;
		while(n - (n & (-n))) n += (n & (-n));
		// if(construct) constructroot(n);
		constructrev(n);
		ntt(a, n, 0); ntt(b, n, 0);
		rep(i, n) o[i] = 1ll*a[i]*b[i]%MOD;
		ntt(o, n, 1);
		iter(i, th, n) o[i] = 0;
		if(clean) rep(i, n) a[i] = b[i] = 0;
	}
 
	void init(int n) { constructroot(n); }
}

string a,b;
int ps[500005];
int canA[500005],canG[500005],canC[500005],canT[500005];
int A[500005],B[500005];
int con[500005];
int res[500005];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    poly::init(1<<20);
    int n,m,k;cin>>n>>m>>k;
    cin>>a>>b;
    int h=n-m+1;
    // int h=n;
    for(int i=n-1;i>=0;i--)ps[i]=(a[i]=='A')+ps[i+1];
    rep(i,n)canA[i]=(ps[max(0,i-k)]!=ps[min(n,i+k+1)]);
    for(int i=n-1;i>=0;i--)ps[i]=(a[i]=='G')+ps[i+1];
    rep(i,n)canG[i]=(ps[max(0,i-k)]!=ps[min(n,i+k+1)]);
    for(int i=n-1;i>=0;i--)ps[i]=(a[i]=='C')+ps[i+1];
    rep(i,n)canC[i]=(ps[max(0,i-k)]!=ps[min(n,i+k+1)]);
    for(int i=n-1;i>=0;i--)ps[i]=(a[i]=='T')+ps[i+1];
    rep(i,n)canT[i]=(ps[max(0,i-k)]!=ps[min(n,i+k+1)]);
    auto go=[&](char x,int*can){
        memset(A,0,sizeof A);
        memset(B,0,sizeof B);
        rep(i,m)A[m-i]=(b[i]==x);
        rep(i,n)B[i]=can[i];
        memset(con,0,sizeof con);
        poly::mult(A,m+1,B,h,con,0);
        rep(i,h)res[i]+=con[m+i];
    };
    go('A',canA);go('C',canC);go('G',canG);go('T',canT);
    int ans=0;
    // rep(i,h)cout<<res[i]<<' ';cout<<endl;
    rep(i,h)ans+=(res[i]==m);
    cout<<ans<<endl;
}