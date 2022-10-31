// warm heart, wagging tail,and a smile just for you!
//                                                                     
//                                                                   
//                                                                
//                                                   
//                                      
//                               
//                             
//                           
//                         
//                       
//                     
//                 
//     
//   
// 
// 
// 
// 
//   
//         
//                                                        
//
#include "bits/stdc++.h"
using namespace std;
#define INF (1<<30)
#define LINF (1LL<<60)
#define fs first
#define sc second
#define int long long
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FOR2(i,a,b) for(int i=(a);i<=(b);++i)
#define RFOR(i,a,b) for(int i = (b-1);i>=(a);--i)
#define RFOR2(i,a,b) for(int i = (b);i>=(a);--i)
#define REP(i,n)  FOR(i,0,(n))
#define REP2(i,n)  FOR2(i,0,(n))
#define RREP(i,n) RFOR(i,0,(n))
#define RREP2(i,n) RFOR2(i,0,(n))
#define ITR(itr,mp) for(auto itr = (mp).begin(); itr != (mp).end(); ++itr)
#define RITR(itr,mp) for(auto itr = (mp).rbegin(); itr != (mp).rend(); ++itr)
#define range(i,a,b) ((a)<=(i) && (i)<(b))
#define range2(i,a,b) ((a)<=(i) && (i)<=(b))
#define debug(x)  cout << #x << " = " << (x) << endl
#define SP << " " << 
template<typename T1,typename T2> inline bool chmin(T1 &a,T2 b){if(a>b) {a=b; return true;} else return false;}
template<typename T1,typename T2> inline bool chmax(T1 &a,T2 b){if(a<b) {a=b; return true;} else return false;}
#define MSB(x) (63-__builtin_clzll(x))
#define pcnt(x) (__builtin_popcountll(x))
#define parity(i,j) (i&(1LL<<j))
typedef pair<int,int> P;
typedef tuple<int,int,int> T;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

int N,M, mx = -LINF;
map<P,P> mp;
mat x(3,vec(25));
vector<string> ans2;

string ans[] = {"MW","LW","LM"};

void f(int a, int b, int c, int mask, int d){
	if(d==M){
		if(mp.count(P(a-b,b-c))){
      if(mp[P(a-b,b-c)].sc < a)  mp[P(a-b,b-c)] = P(mask,a);
    }
    else mp[P(a-b,b-c)] = P(mask,a);
		return;
	}

	REP(i,3){
		int na = a + x[0][d], nb = b + x[1][d],	nc = c + x[2][d];
		if(i==0) na -= x[0][d];
		if(i==1) nb -= x[1][d];
		if(i==2) nc -= x[2][d];
		f(na,nb,nc,mask*4+i,d+1);
	}
}

void g(int a, int b, int c, int mask, int d){
	if(d==N){
		if(mp.count(P(b-a,c-b))){
			int mask2 = mp[P(b-a,c-b)].fs, val = mp[P(b-a,c-b)].sc;
      if(!chmax(mx,val+a)) return;
      ans2.clear();
			vector<string> res,res2;
			REP(i,M) res.push_back(ans[mask2%4]), mask2 /= 4;
			REP(i,N-M) res2.push_back(ans[mask%4]), mask /= 4;

			RREP(i,M) ans2.push_back(res[i]);
			RREP(i,N-M) ans2.push_back(res2[i]);
		}
		return;
	}

	REP(i,3){
		int na = a + x[0][d], nb = b + x[1][d],	nc = c + x[2][d];
		if(i==0) na -= x[0][d];
		if(i==1) nb -= x[1][d];
		if(i==2) nc -= x[2][d];
		g(na,nb,nc,mask*4+i,d+1);
	}
}
void solve(){

	cin >> N;

	REP(i,N) cin >> x[0][i] >> x[1][i] >> x[2][i];
	
	M = N/2;

	f(0,0,0,0,0);
	g(0,0,0,0,M);

 // debug(mx);

	if(!ans2.size()) cout << "Impossible" << endl;
  else REP(i,N) cout << ans2[i] << endl;
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T = 1;
	// cin >> T;

	while(T--) solve();

	return 0;
}