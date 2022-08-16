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

template<typename T1,typename T2>
std::istream& operator>>(std::istream& in,pair<T1,T2> &a)
{
	in>>a.fr>>a.sc;
	return in;
}
template<typename T1,typename T2>
std::ostream& operator<<(std::ostream& out,pair<T1,T2> &a)
{
	out<<a.fr<<" "<<a.sc;
	return out;
}

const int N=0;

void solve(){
	int n,w;
	cin>>n>>w;
	pii a[n];
	rep(i,0,n)cin>>a[i].fr,a[i].sc=i;
	sort(a,a+n);
	int b[n]={};
	rep(i,0,n){
		b[i]=(a[i].fr+1)/2;
		w-=b[i];
	}
	if(w<0){
		cout<<-1;
		return;
	}
	for(int i=n-1;w && i>=0;i--){
		while(w && b[i]<a[i].fr){
			b[i]++;
			w--;
		}
	}
	int c[n]={};
	rep(i,0,n){
		c[a[i].sc]=b[i];
	}
	rep(i,0,n)cout<<c[i]<<" ";
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