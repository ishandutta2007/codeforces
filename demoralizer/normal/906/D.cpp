#include <bits/stdc++.h>
using namespace std;
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define sz(x)             (int)((x).size())
#define int               long long
#define M                 1000000007
#define MM                998244353
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T>pair<T,T> operator+=(pair<T,T> &a,pair<T,T> b){a.fr+=b.fr;a.sc+=b.sc;return a;}
template<typename T>pair<T,T> operator-=(pair<T,T> &a,pair<T,T> b){a.fr-=b.fr;a.sc-=b.sc;return a;}
template<typename T>pair<T,T> operator+(pair<T,T> a,pair<T,T> b){a.fr+=b.fr;a.sc+=b.sc;return a;}
template<typename T>pair<T,T> operator-(pair<T,T> a,pair<T,T> b){a.fr-=b.fr;a.sc-=b.sc;return a;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

const int N=0;

int w[100005];
int phi(int n) {
    int result = n;
    for (int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            while(n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if(n > 1)
        result -= result / n;
    return result;
}
int p[100];

int pw(int a,int b,int p){
	if(b==0)return 1;
	int t=pw(a,b/2,p);
	if(b%2)return (((a*t)%p)*t)%p;
	else return ((t*t)%p);
}

int calc(int x,int y,int c){
	if(x==y){
		if(w[x]<p[c])return w[x];
		return (w[x]%p[c] + p[c]);
	}	
	if(p[c]==1){
		// if(__gcd(w[x],p[c])==1)return 0;
		return 1;
	}
	if(w[x]==1)return 1;
	int k=calc(x+1,y,c+1);
	// if(__gcd(w[x],p[c])==1) k%=p[c+1];
	if(k>32)return pw(w[x],k,p[c])+p[c];
	else{
		bool f=0;
		int ans=1;
		rep(i,0,k){
			ans*=w[x];
			if(ans>=p[c])f=1;
			ans%=p[c];
		}
		if(f)ans+=p[c];
		return ans;
	}
}

void solve(){
	int n,m;
	cin>>n>>m;
	rep(i,0,n)cin>>w[i];
	p[0]=m;
	rep(i,1,100){
		p[i]=phi(p[i-1]);
	}
	int q;
	cin>>q;
	rep(zz,0,q){
		int l,r;
		cin>>l>>r;
		cout<<calc(l-1,r-1,0)%m<<"\n";
	}
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SEIVE
		seive();
	#endif
	#ifdef NCR
		init();
	#endif
	#ifdef DSU
		cleardsu(MAXDSUSIZE);
	#endif
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}