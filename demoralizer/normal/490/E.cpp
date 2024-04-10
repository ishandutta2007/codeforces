#include <bits/stdc++.h>
using namespace std;
#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll

template<typename T1,typename T2>istream& operator>>(istream& in,pair<T1,T2> &a){in>>a.fr>>a.sc;return in;}
template<typename T1,typename T2>ostream& operator<<(ostream& out,pair<T1,T2> a){out<<a.fr<<" "<<a.sc;return out;}
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

const long long INF=1e18;
const int32_t M  = 1e9+7;
const int32_t MM = 998244353;

const int N=1e5+5;

bool calc(string &a,string &b,int pos,bool f){
	if(pos == sz(a)){
		return f;
	}
	if(b[pos] != '?'){
		if(!f && b[pos] < a[pos]) return 0;
		if(f){
			return calc(a,b,pos+1,1);
		}
		else{
			if(b[pos] == a[pos]){
				return calc(a,b,pos+1,0);
			}
			else{
				return calc(a,b,pos+1,1);
			}
		}
	}
	else{
		if(f){
			if(calc(a,b,pos+1,1)){
				b[pos] = '0';
				return 1;
			}
		}
		else{
			if(calc(a,b,pos+1,0)){
				b[pos] = a[pos];
				return 1;
			}
			if(a[pos] != '9'){
				if(calc(a,b,pos+1,1)){
					b[pos] = a[pos] + 1;
					return 1;
				}
			}
		}
	}
	return 0;
}

string s[N];

void solve(){
	int n;
	cin>>n;
	s[0] = "0";
	rep(i,1,n+1){
		cin>>s[i];
		if(sz(s[i]) > sz(s[i-1])){
			if(s[i][0] == '?'){
				s[i][0] = '1';
			}
			for(char &c:s[i]){
				if(c=='?') c = '0';
			}
		}
		else{
			if(sz(s[i]) < sz(s[i-1]) || !calc(s[i-1],s[i],0,0)){
				cout<<"NO";
				return;
			}
		}
	}
	cout<<"YES\n";
	rep(i,1,n+1){
		cout<<s[i]<<"\n";
	}
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	#ifdef SIEVE
		sieve();
	#endif
	#ifdef NCR
		init();
	#endif
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}