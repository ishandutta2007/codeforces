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

const int N=6;
const int ITR=1e4+1;

int l[N],r[N];
void solve(){
	int n;
	cin>>n;
	int t5 = 1;
	rep(i,0,n){
		t5 *= 3;
		cin>>l[i]>>r[i];
	}
	
	double ans = 0;
	rep(v,1,ITR){
		double prob = 0;
		rep(i,0,t5){
			int x = i , c1 = 0, c2 = 0;
			vector<int> z(5);
			rep(j,0,n){
				z[j] = x%3;
				if(z[j] == 1) c1++;
				if(z[j] == 2) c2++;
				x /= 3;
			}
			if(c2 > 1 || (c2 == 0 && c1 < 2) || (c1 == 0))continue;
			double p = 1;
			rep(j,0,n){
				if(z[j] == 0){
					if(l[j] >= v) p*=0;
					else p *= 1.0*(min(v-1,r[j]) - l[j] + 1) / (r[j] - l[j] + 1);
				}
				else if(z[j] == 1){
					if(l[j] > v || r[j] < v) p*=0;
					else p *= 1.0 / (r[j] - l[j] + 1);
				}
				else{
					if(r[j] <= v) p*=0;
					else p *= 1.0*(r[j] - max(v+1,l[j]) + 1) / (r[j] - l[j] + 1);
				}
			}
			prob += p;
		}
		ans += prob * v;
	}
	
	cout<<setprecision(12);
	cout<<fixed;
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