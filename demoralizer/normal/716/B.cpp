#include <bits/stdc++.h>
using namespace std;
#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
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

int cnt[200];
int tot=0;
int qm=0;

void solve(){
	string s;
	cin>>s;
	
	int n=sz(s);
	
	if(n<26){
		cout<<-1;
		return;
	}
	
	rep(i,0,26){
		if(s[i]!='?'){
			if(cnt[s[i]]==0)tot++;
			cnt[s[i]]++;
		}
		else{
			qm++;
		}
	}
	
	rep(i,26,n+1){
		if(tot+qm == 26){
			vector<char> missing;
			rep(k,'A','Z'+1){
				if(cnt[k]==0)missing.pb(k);
			}
			rep(j,i-26,i){
				if(s[j]=='?'){
					s[j]=missing.back();
					missing.ppb();
				}
			}
			rep(j,0,n){
				if(s[j]=='?')cout<<'A';
				else cout<<s[j];
			}
			return;
		}
		if(i==n){
			cout<<-1;
			return;
		}
		if(s[i]!='?'){
			if(cnt[s[i]]==0)tot++;
			cnt[s[i]]++;
		}
		else{
			qm++;
		}
		if(s[i-26]!='?'){
			cnt[s[i-26]]--;
			if(cnt[s[i-26]]==0)tot--;
		}
		else{
			qm--;
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
	int t=1;
	//cin>>t;
	while(t--) solve();
	return 0;
}