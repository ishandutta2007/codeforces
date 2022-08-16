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

const int N=1e5+5;

struct part
{
	int a,b,id;
	bool operator< (const part& other)const{
		return tie(a,id) < tie(other.a,other.id);
	}
}p[N];
struct singer
{
	int c,d,k,id;
	bool operator< (const singer& other)const{
		return tie(d,id) < tie(other.d,other.id);
	}
}s[N];

istream& operator>>(istream& in,singer &s){in>>s.c>>s.d>>s.k;return in;}
istream& operator>>(istream& in,part &p){in>>p.a>>p.b;return in;}

set<part> parts;

int assignment[N];

void solve(){
	int n;
	cin>>n;
	rep(i,0,n){
		cin>>p[i];
		p[i].id = i+1;
	}
	sort(p,p+n,[&](part a,part b){
		return a.b < b.b;
	});
	
	int m;
	cin>>m;
	rep(i,0,m){
		cin>>s[i];
		s[i].id = i+1;
	}
	sort(s,s+m);
	
	int i = 0, j = 0;
	while(i < m){
		if(j < n && p[j].b <= s[i].d){
			parts.insert(p[j++]);
			continue;
		}
		auto it = parts.lower_bound({s[i].c,0,-1});
		if(it != parts.end()){
			assignment[it->id] = s[i].id;
			s[i].k--;
			parts.erase(it);
		}
		else{
			i++;
			continue;
		}
		if(s[i].k == 0) i++;
	}
	
	if(j < n || sz(parts)){
		cout<<"NO";
		return;
	}
	cout<<"YES\n";
	rep(i,1,n+1){
		cout<<assignment[i]<<" ";
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