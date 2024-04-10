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

const int INF=1e18;

const int N=1e6+5;

// int pw(int a,int b=M-2,int p=M){
// 	if(b==0)return 1;
// 	int t=pw(a,b/2,p);
// 	if(b%2)return (((a*t)%p)*t)%p;
// 	else return ((t*t)%p);
// }

int pw(int a,int p=M-2)  {
    int result = 1;
    while (p > 0) {
        if (p & 1)
            result = a*result % M;

        a = a*a%M;
        p >>= 1;
    }

    return result;
}

int P[N];
int d[N];
int num[N];
void solve(){
	int n,k;
	cin>>n>>k;
	rep(i,1,k+4){
		P[i]=P[i-1]+pw(i,k);
		P[i]%=M;
	}
	if(n<=k+2){
		cout<<P[n];
		return;
	}
	d[1]=1;
	num[1]=1;
	rep(i,1,k+2){
		d[1]*=M-i;
		d[1]%=M;
		num[1]*=(M+n-i-1)%M;
		num[1]%=M;
	}
	// cout<<num[1]<<"\n";
	int ans=0;
	ans+=num[1]*pw(d[1])%M * P[1]%M;
	ans%=M;
	rep(i,2,k+3){
		d[i]=d[i-1];
		d[i]*=pw(M-k+i-3);
		d[i]%=M;
		d[i]*=i-1;
		d[i]%=M;
		num[i]=num[i-1];
		num[i]*=pw((M+n-i)%M);
		num[i]%=M;
		num[i]*=(M+n-i+1)%M;
		num[i]%=M;
		// cout<<num[i]<<"\n";
		ans+=num[i]*pw(d[i])%M * P[i] %M;
		ans%=M;
	}
	cout<<ans;
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
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}