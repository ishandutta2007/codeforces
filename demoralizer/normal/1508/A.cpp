#include "bits/stdc++.h"
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
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=0;



void solve(){
	int n;
	cin >> n;
	string s[3];
	int c[3];
	rep(i,0,3){
		cin >> s[i];
		int d[2] = {0};
		rep(j,0,2*n){
			d[s[i][j] - '0']++;
		}
		if(d[0] > d[1]){
			c[i] = 0;
		}
		else{
			c[i] = 1;
		}
	}
	
	
	int x,y;
	if(c[0] == c[1]){
		x = 0; y = 1;
	}
	else if(c[1] == c[2]){
		x = 1; y = 2;
	}
	else{
		x = 0; y = 2;
	}
	
	string ans = s[x];
	// s[y] has at least n chars common with s[x] which are c[x] = c[y]
	vector<string> z;
	int cnt = 0;
	int i = 0;
	while(cnt < n){
		string tmp;
		while(s[y][i] != '0' + c[y]){
			tmp.pb(s[y][i]);
			i++;
		}
		cnt++;
		i++;
		z.pb(tmp);
	}
	string tmp;
	while(i < 2 * n){
		tmp.pb(s[y][i]);
		i++;
	}
	z.pb(tmp);
	
	string pr;
	cnt = 0;
	rep(i,0,2*n){
		if(cnt < n && ans[i] == c[x] + '0'){
			pr += z[cnt];
			pr.pb(ans[i]);
			cnt++;
		}
		else{
			pr.pb(ans[i]);
		}
	}
	pr += z.back();
	cout << pr << "\n";
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
	cin>>t;
	while(t--) solve();
	return 0;
}