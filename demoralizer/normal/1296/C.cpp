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
	int n;string s;
	cin>>n>>s;
	map<pii, int> z;
	pii cur={0,0};
	z[cur]=0;
	
	int ans=-1;
	int l,r;
	
	rep(i,0,n){
		
		if(s[i]=='L')cur.fr++;
		if(s[i]=='R')cur.fr--;
		if(s[i]=='U')cur.sc++;
		if(s[i]=='D')cur.sc--;
		
		if(z.count(cur)){
			int t=i-z[cur]+1;
			if(ans==-1 || t<ans){
				ans=t;
				l=z[cur];
				r=i;
			}
		}
		
		z[cur]=i+1;
	}
	if(ans==-1){
		cout<<-1;
	}
	else{
		cout<<l+1<<" "<<1+r;
	}
	cout<<"\n";
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
	cin>>t;
	while(t--) solve();
	return 0;
}