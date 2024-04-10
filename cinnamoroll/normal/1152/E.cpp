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
#include "bits/stdc++.h"
using namespace std;
#define MOD 1000000007
const double EPS = 1e-9;
#define INF (1LL<<60)
#define fs first
#define sc second
#define D double
#define int long long
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define RFOR(i,a,b) for(int i = (b-1);i>=a;i--)
#define REP(i,n)  FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ITR(itr,mp) for(auto itr = (mp).begin(); itr != (mp).end(); ++itr)
#define RITR(itr,mp) for(auto itr = (mp).rbegin(); itr != (mp).rend(); ++itr)
#define range(i,a,b) ((a)<=(i) && (i)<(b))
#define debug(x)  cout << #x << " = " << (x) << endl;
#define SP << " " << 
typedef pair<int,int> P;
typedef vector<vector<P> > Graph;
typedef vector<int> vec;
typedef vector<vector<int>> mat;

template<typename T>
vector<T> compress(vector<T> v){
  sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
  return v;
}
 
template<typename T>
map<T, int> dict(const vector<T> &v){
  map<T, int> res;
  for(int i=0;i<(int)v.size();i++)
    res[v[i]]=i;
  return res;
}


template<int MV> class UndirectedEulerPath {
public:
	vector<int> path;
	multiset<int> E[MV];
	void add_path(int x,int y) { E[x].insert(y); E[y].insert(x); }
	
	void dfs(int cur) {
		while(E[cur].size()) {
			int tar=*E[cur].begin();
			E[cur].erase(E[cur].begin());
			E[tar].erase(E[tar].find(cur));
			dfs(tar);
		}
		path.push_back(cur);
	}
	
	bool GetPath() { // 
		int fo=-1,odd=0,i,np=0;
		REP(i,MV) {
			np += E[i].size();
			if(E[i].size()%2) odd++, fo=(fo==-1)?i:fo;
		}
		if(odd!=0 && odd!=2) return false;
		dfs(odd?fo:0);
		reverse(path.begin(),path.end());
		return path.size()==np/2+1;
	}

	vector<int> GetPath(int root) { //
		dfs(root);
		reverse(path.begin(),path.end());
		return path;
	}
};

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vec a(n-1),v(2*(n-1));
  REP(i,n-1) cin >> a[i], v[i] = a[i];
  
  vec b(n-1);
  REP(i,n-1) cin >> b[i],v[n-1+i] = b[i];
  
  auto x = compress(v);
  auto r = dict(x);

  UndirectedEulerPath<200010> uep;
  REP(i,n-1) {
    if(a[i] > b[i]){
      cout << -1 << endl;
      return 0;
    }
    uep.add_path(r[a[i]],r[b[i]]);
  }

  if(uep.GetPath()) REP(i,n) cout << x[uep.path[i]] << " ";
  else cout << -1 << endl;
  return 0;
}