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

vector<int> prefix_function(vector<pii> s) {
    int n = sz(s);
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

vector<pii> s,t;

void input(vector<pii> &s,int n){
	rep(i,0,n){
		string tmp;
		cin>>tmp;
		char c=tmp.back();
		tmp.ppb();
		tmp.ppb();
		int l;
		stringstream(tmp)>>l;
		if(sz(s) && s.back().sc == c){
			s.back().fr += l;
		}
		else{
			s.pb({l,c});
		}
	}
}

vector<pii> z;

void solve(){
	int n,m;
	cin>>n>>m;
	input(s,n);
	input(t,m);
	rep(i,1,sz(t)-1){
		auto x=t[i];
		z.pb(x);
	}
	z.pb({-1,-1});
	rep(i,1,sz(s)-1){
		auto x=s[i];
		z.pb(x);
	}
	
	if(sz(t)==1){
		int ans=0;
		for(auto x:s){
			if(x.sc == t[0].sc && x.fr >= t[0].fr){
				ans += x.fr - t[0].fr + 1;
			}
		}
		cout<<ans;
		return;
	}
	
	if(sz(t) == 2){
		int ans=0;
		rep(i,0,sz(s)-1){
			if(s[i].sc == t[0].sc && s[i+1].sc == t[1].sc && s[i].fr >= t[0].fr && s[i+1].fr >= t[1].fr){
				ans++;
			}
		}
		cout<<ans;
		return;
	}
	
	int ans=0;
	vector<int> pf=prefix_function(z);
	rep(i,1,sz(s)-1){
		int j=i+sz(t)-2;
		if(pf[j]==sz(t)-2){
			if(t.back().sc == s[i+1].sc && t.back().fr <= s[i+1].fr && t[0].sc == s[i-sz(t)+2].sc && t[0].fr <= s[i-sz(t)+2].fr){
				ans++;
			}
		}
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