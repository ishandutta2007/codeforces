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

const int N=1e6+5;

struct seg
{
	int l,v;char c;
	operator int() const{
		return l;
	}
};

set<seg> s;

void solve(){
	string t;
	cin>>t;
	
	int l=0,v=1;
	char c=t[0];
	t.pb('A');
	rep(i,1,sz(t)){
		if(c!=t[i]){
			s.insert({l,v,c});
			l=i;
			v=1;
			c=t[i];
		}
		else{
			v++;
		}
	}
	
	int ans=0;
	while(sz(s)>1){
		ans++;
		for(auto it=s.begin();it!=s.end();){
			auto tmp = it;tmp++;
			
			seg x=*it;
			if(it!=s.begin() && tmp!=s.end()){
				x.v-=2;
				amax(x.v,0);
			}
			else{
				x.v-=1;
				amax(x.v,0);
			}
			s.erase(it);
			s.insert(x);
			
			it=s.upper_bound(x);
		}
		
		for(auto it=s.begin();it!=s.end();){
			if(it->v){
				it++;
				continue;
			}
			auto tmp = it;tmp++;
			
			if(it!=s.begin() && tmp!=s.end()){
				s.erase(it--);
				if(it->c==tmp->c){
					seg x={*it,it->v + tmp->v,it->c};
					s.erase(it);
					s.erase(tmp);
					s.insert(x);
					it=s.upper_bound(x);
				}
				else{
					it=tmp;
				}
			}
			else{
				s.erase(it++);
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