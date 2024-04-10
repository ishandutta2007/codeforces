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

string rev(string s){
	reverse(all(s));
	return s;
}

void solve(){
	int n;
	cin>>n;
	set<string> s;
	map<string, int> id;
	
	int cnt[2] = {0,0};
	int inver[2] = {0,0};
	vector<int> avail[2];
	
	bool has[2] = {0,0};
	
	rep(i,0,n){
		string t;
		cin>>t;
		id[t] = i+1;
		if(t.front() != t.back()){
			s.insert(t);
			cnt[t[0]-'0']++;
		}
		else{
			has[t[0]-'0'] = 1;
		}
	}
	
	for(string t:s){
		if(!s.count(rev(t))){
			inver[t[0]-'0']++;
			avail[t[0]-'0'].pb(id[t]);
		}
	}
	
	if(sz(s) == 0){
		if(has[0] && has[1]){
			cout<<-1;
		}
		else{
			cout<<0;
		}
		cout<<"\n";
		return;
	}
	if(cnt[0] > cnt[1]){
		swap(cnt[0],cnt[1]);
		swap(inver[0],inver[1]);
		swap(avail[0],avail[1]);
	}
	
	int way = cnt[1] - cnt[0];
	way /= 2;
	
	if(inver[1] < way){
		cout<<-1;
	}
	else{
		cout<<way<<"\n";
		rep(i,0,way){
			cout<<avail[1][i]<<" ";
		}
	}
	cout<<"\n";
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