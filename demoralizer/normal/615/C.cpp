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
const int32_t M=1e9+7;
const int32_t MM=998244353;

const int N=0;

vector<int> prefix_function(string &s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

void solve(){
	string s,t,r;
	cin>>s>>t;
	
	int n=sz(t);
	int m=sz(s);
	
	r=s;
	reverse(all(r));
	
	vector<pii> ans;
	while(sz(t)){
		
		string z=t+"&"+s;
		vector<int> pf=prefix_function(z);
		int lps=0;
		pii pr;
		rep(i,n+1,n+m+1){
			if(pf[i]>lps){
				lps=pf[i];
				pr={i-n-lps+1,i-n};
			}
		}
		z=t+"&"+r;
		pf=prefix_function(z);
		rep(i,n+1,n+m+1){
			if(pf[i]>lps){
				lps=pf[i];
				pr={m+1-(i-n-lps+1),m+1-(i-n)};
			}
		}
		if(!lps){
			cout<<-1;
			return;
		}
		ans.pb(pr);
		reverse(all(t));
		t.resize(n-lps);
		reverse(all(t));
		n=sz(t);
	}
	cout<<sz(ans)<<"\n";
	for(auto x:ans){
		cout<<x<<"\n";
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