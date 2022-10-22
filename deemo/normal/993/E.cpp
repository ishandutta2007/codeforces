#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define F first
#define S second

const int MAXN = 2e5 + 10;

int n, x, a[MAXN], pt[MAXN];

//coppied code
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second
typedef vector<ll> VI;
typedef pair<ll,ll> PII;
const ll mod=1000000007;
ll powmod(ll a,ll b) {ll res=1;a%=mod;for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
// head

typedef complex<double> CD;
const double pi=acos(-1);
namespace fft{
	const int N=1<<19;
	CD cp1[N+10],cp2[N+10];
	int R[N+10];
	void rev(CD* a,int n) { for (int i=0;i<n;i++) if (R[i]<i) swap(a[R[i]],a[i]);}
	void dft(CD* a,int n,bool inv) {
		CD wi,w,u,v;
		rev(a,n);
		for (int m=2;m<=n;m<<=1) {
			double Arg=2*pi/m*(inv?-1:1);
			wi=CD(cos(Arg),sin(Arg));
			for (int j=0;j<n;j+=m) { w=1;
				for (int k=j,k2=j+m/2;k2<j+m;k++,k2++)
					u=a[k],v=a[k2]*w,a[k]=u+v,a[k2]=u-v,w=w*wi;
			}
		}
		if (inv) for (int j=0;j<n;j++) a[j]=a[j]/(1.*n);
	}
	VI solve(VI& p1,VI& p2) {
		int n=p1.size()+p2.size()+1;
		int l=1,cnt=0;
		while (l<=n) l+=l,cnt++;
		rep(i,0,l) { R[i]=0;rep(j,0,cnt) R[i]=(R[i]<<1)|((i>>j)&1);}
		rep(i,0,l) cp1[i]=0,cp2[i]=0;
		rep(i,0,SZ(p1)) cp1[i]=p1[i];
		rep(i,0,SZ(p2)) cp2[i]=p2[i];
		dft(cp1,l,0);
		dft(cp2,l,0);
		rep(i,0,l) cp1[i]*=cp2[i];
		dft(cp1,l,1);
		VI res;
		res.clear();
		n=p1.size()+p2.size()-1;
		rep(i,0,n) res.pb((ll)floor(cp1[i].real()+0.5));
		return res;
	}
}

vector<ll> cnt, cnt2, ans;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> x;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		if (a[i] < x) a[i] = 1;
		else a[i] = 0;
		pt[i+1] = pt[i] + a[i];
	}
	cnt.resize(n+1);
	for (int i = 0; i <= n; i++) cnt[pt[i]]++;
	cnt2.assign(cnt.begin(), cnt.end());
	reverse(cnt2.begin(), cnt2.end());
	ans = fft::solve(cnt, cnt2);

	ll z = 0;
	for (int l = 0; l < n;){
		if (a[l]){
			l++;
			continue;
		}

		int r = l;
		while (r < n && a[r] == 0) r++;
		z += 1ll*(r-l)*(r-l+1)/2;
		l = r;
	}
	cout << z << " ";

	for (int i = 1; i <= n; i++)
		cout << ans[n+i] << " ";
	cout << "\n";
	return 0;
}