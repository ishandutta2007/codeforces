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

int a[26];
void solve(){
	int n;
	string s;
	cin>>n>>s;
	vector<int> t;
	t.pb(0);
	char c='a'-1,d=s[0];
	int cnt=1;
	rep(i,1,n){
		if(s[i]>=d){
			t.pb(0);
			d=s[i];
		}
		else{
			int z=0;
			rep(j,s[i]+1,d+1){
				z=max(a[j-'a'],z);
			}
			t.pb(z+1);
			a[s[i]-'a']=max(a[s[i]-'a'],z+1);
			cnt=max(cnt,2+z);
		}
	}
	cout<<cnt<<"\n";
	for(int x:t)cout<<x+1<<" ";
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