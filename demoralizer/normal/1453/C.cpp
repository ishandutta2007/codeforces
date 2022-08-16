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

const int N=2005;

vector<int> row[N][10], col[N][10];
int ans[10];
int mnrow[10];
int mxrow[10];
int mncol[10];
int mxcol[10];

void solve(){
	int n;
	cin >> n;
	rep(i,0,n){
		rep(j,0,10){
			row[i][j].clear();
			col[i][j].clear();
		}
	}
	string s[n];
	rep(i,0,n){
		cin >> s[i];
		rep(j,0,n){
			int d = s[i][j] - '0';
			row[i][d].pb(j);
			col[j][d].pb(i);
		}
	}
	
	mem0(ans);
	mem1(mnrow);
	mem1(mxrow);
	mem1(mncol);
	mem1(mxcol);
	
	rep(i,0,n){
		rep(d,0,10){
			if(!row[i][d].empty()){
				if(mnrow[d] == -1) mnrow[d] = i;
				mxrow[d] = i;
			}
			if(!col[i][d].empty()){
				if(mncol[d] == -1) mncol[d] = i;
				mxcol[d] = i;
			}
		}
	}
	
	rep(i,0,n){
		rep(d,0,10){
			// row
			if(!row[i][d].empty()){
				int x = row[i][d].front(), y = row[i][d].back();
				amax(ans[d],(x-y)*max(i-0,n-1-i));
				int height = max(i - mnrow[d], mxrow[d] - i);
				amax(ans[d],height * max(n-1-x,y-0));
			}
			// col
			if(!col[i][d].empty()){
				int x = col[i][d].front(), y = col[i][d].back();
				amax(ans[d],(x-y)*max(i-0,n-1-i));
				int height = max(i - mncol[d], mxcol[d] - i);
				amax(ans[d],height * max(n-1-x,y-0));
			}
		}
	}
	for(int x:ans)
		cout << x << " ";
	cout << "\n";
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