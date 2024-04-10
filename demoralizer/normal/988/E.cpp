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



void solve(){
	string s;
	cin>>s;
	if(sz(s) == 1){
		cout<<-1;
		return;
	}
	reverse(all(s));
	string t = s;
	int ans = INF;
	rep(i,0,sz(t)){
		if(t[i] == '0'){
			t.erase(t.begin()+i);
			rep(j,0,sz(t)){
				if(t[j] == '0' || t[j] == '5'){
					amin(ans,i+j);
					break;
				}
			}
			break;
		}
	}
	t = s;
	rep(i,0,sz(t)){
		int k = 0;
		if(t[i] == '5'){
			t.erase(t.begin()+i);
			rep(j,0,sz(t)){
				if(t[j] == '2' || t[j] == '7'){
					t.erase(t.begin()+j);
					while(k < sz(t) && t[sz(t)-1-k] == '0'){
						k++;
					}
					amin(ans,i+j+k);
					break;
				}
			}
			break;
		}
	}
	if(ans == INF)ans = -1;
	cout<<ans;
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