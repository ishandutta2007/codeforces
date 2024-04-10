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

vector<int> prefix_function(string s) {
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
	int n;
	cin >> n;
	int L[n], R[n], S[n];
	string s[n],t[n];
	rep(i,0,n){
		cin >> s[i];
	}
	rep(i,0,n){
		cin >> t[i];
	}
	set<pair<string, string>> z;
	rep(i,0,n){
		S[i] = sz(s[i]);
		if(s[i] == t[i]){
			L[i] = R[i] = -1;
			continue;
		}
		int l = 0;
		while(s[i][l] == t[i][l]) l++;
		int r = sz(s[i]) - 1;
		while(s[i][r] == t[i][r]) r--;
		L[i] = l;
		R[i] = r;
		string m,M;
		rep(j,l,r+1){
			m.pb(s[i][j]);
			M.pb(t[i][j]);
		}
		z.insert({m,M});
	}
	
	if(sz(z) > 1){
		cout << "NO";
		return;
	}
	
	while(1){
		bool flag = false;
		set<char> z;
		rep(i,0,n){
			if(L[i] == -1) continue;
			if(L[i] == 0 || s[i][L[i]-1] != t[i][L[i]-1]) flag = true;
			z.insert(s[i][L[i]-1]);
		}
		if(flag || sz(z) > 1) break;
		rep(i,0,n){
			if(L[i] == -1) continue;
			L[i]--;
		}
	}
	while(1){
		bool flag = false;
		set<char> z;
		rep(i,0,n){
			if(R[i] == -1) continue;
			if(R[i] == S[i] - 1 || s[i][R[i]+1] != t[i][R[i]+1]) flag = true;
			z.insert(s[i][R[i]+1]);
		}
		if(flag || sz(z) > 1) break;
		rep(i,0,n){
			if(R[i] == -1) continue;
			R[i]++;
		}
	}
	int id = 0;
	while(L[id] == -1) id++;
	string m,M;
	rep(j,L[id],R[id]+1){
		m.pb(s[id][j]);
		M.pb(t[id][j]);
	}
	// replace first occurance of m with M in each s[i] and it should become t[i]
	
	bool yes = true;
	
	rep(i,0,n){
		string k = m + "$" + s[i];
		auto p = prefix_function(k);
		int pos = 0;
		rep(j,0,sz(p)){
			if(p[j] == sz(m)){
				pos = j;
				break;
			}
		}
		if(pos){
			pos -= sz(m)+1;
			for(int j = sz(M) - 1; j >= 0; j--){
				s[i][pos] = M[j];
				pos--;
			}
		}
		if(s[i] != t[i]) yes = false;
	}
	
	if(yes){
		cout << "YES\n";
		cout << m << "\n" << M;
		return;
	}
	else{
		cout << "NO";
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


// (150, 19, 471, 105), 
// (3, 8, 492, 252)