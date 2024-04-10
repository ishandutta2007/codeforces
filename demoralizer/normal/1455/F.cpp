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

int n,k;
char dec(char c){
	char ret = (k + c - 'a' - 1) % k + 'a';
	return ret;
}
char inc(char c){
	char ret = (c - 'a' + 1) % k + 'a';
	return ret;
}

void solve(){
	string s;
	cin >> n >> k >> s;
	
	rep(i,0,n){
		if(i && i < n - 1 && s[i - 1] > min(s[i],s[i+1])){
			if(s[i] <= s[i+1]){
				swap(s[i],s[i-1]);
				continue;
			}
			else{
				char tmp = s[i-1];
				s[i-1] = s[i+1];
				s[i+1] = s[i];
				s[i] = tmp;
				i++;
				continue;
			}
		}
		if(i && s[i] < s[i-1]){
			swap(s[i],s[i-1]);
			continue;
		}
		if(s[i] == 'a' + k - 1 || s[i] == 'b' || s[i] == 'a'){
			s[i] = 'a';
			continue;
		}
		if(i < n - 2){
			char tmp = min({inc(s[i+1]),dec(s[i+1]),s[i+1]});
			char tmp2 = s[i+2];
			if(dec(s[i]) > min(tmp,tmp2)){
				if(tmp <= tmp2){
					if(tmp == s[i+1]){
						s[i] = dec(s[i]);
					}
					swap(s[i],s[i+1]);
					s[i] = tmp;
					i++;
					continue;
				}
				else{
					s[i+2] = s[i+1];
					s[i+1] = dec(s[i]);
					s[i] = tmp2;
					i += 2;
					continue;
				}
			}
		}
		
		if(i < n - 1){
			char tmp = min({inc(s[i+1]),dec(s[i+1]),s[i+1]});
			if(dec(s[i]) > tmp){
				if(tmp == s[i+1]){
					s[i] = dec(s[i]);
				}
				swap(s[i],s[i+1]);
				s[i] = tmp;
				i++;
				continue;
			}
		}
		
		s[i] = dec(s[i]);
		
		
	}
	cout << s << "\n";
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