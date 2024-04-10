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

const int N=2e5+5;
string s;
int q,a;

int ps[N][28];
void solve(){
	cin>>s;
	int n=sz(s);
	cin>>q;
	rep(i,0,n){
		ps[i+1][s[i]-'a']=1;
	}
	rep(i,1,n+1){
		rep(j,0,26){
			ps[i][j]+=ps[i-1][j];
		}
	}
	rep(i,0,q){
		int l,r;
		cin>>l>>r;
		if(l==r){
			cout<<"Yes\n";
			continue;
		}
		l--;r--;
		int c=0;
		rep(i,0,26){
			c+=((ps[r+1][i]-ps[l][i])!=0);
		}
		if(c<=2 && s[l]==s[r]){
			cout<<"No\n";
			continue;
		}
		else{
			cout<<"Yes\n";
		}
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