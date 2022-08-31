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

int a[200005];


set<int,greater<int>> s;
vector<pii> e;
void solve(){
	int n;
	cin>>n;
	rep(i,1,n+1)s.insert(i);
	for(int i=0;i<n-1;i++){
		cin>>a[i];
	}
	int r=a[0];
	s.erase(r);
	int cp=r;int p=1;
	while(!s.empty()){
		int k=*s.begin();
		s.erase(s.begin());
		while(a[p]!=k && s.count(a[p])){
			e.pb({cp,a[p]});
			cp=a[p];
			s.erase(a[p]);
			p++;
		}
		e.pb({cp,k});
		cp=a[p];
		p++;
	}
	cout<<r<<"\n";
	for(pii x:e)cout<<x<<"\n";
}
signed main(){
	ios_base::sync_with_stdio(false);
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