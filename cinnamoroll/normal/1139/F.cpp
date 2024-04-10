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
#define pb push_back
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

struct BIT{
private:
  vector<int> bit;
  int num;

public:
  BIT(vector<int> v){
    num = v.size();
    bit.resize(num);
    REP(i,num) bit[i] = v[i];
  }

  int sum(int i){
    int s = 0;
    while(i > 0){
      s += bit[i];
      i -= i & -i;
    }
    return s;
  }

  void add(int i, int x){
    while(i <= num){
      bit[i] += x;
      i += i & -i;
    }
  }
};

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n,m;
  cin >> n >> m;

  vector<P> val;
  vec bP,bM;
  bP.push_back(-INF);
  bM.push_back(-INF);

  vec p(n);
  REP(i,n){
    cin >> p[i];
    val.push_back(P(p[i],i));
  }
  
  vec s(n);
  REP(i,n){
    cin >> s[i];
    val.push_back(P(s[i],i+200000)); //indexp,s,b
  }
  
  vec b(n);
  REP(i,n){
    cin >> b[i];
    bP.push_back(b[i]+p[i]);
    bM.push_back(p[i]-b[i]);
  }
  
  vec inc(m);
  REP(i,m){
    cin >> inc[i];
    val.push_back(P(inc[i],i+100000)); // s->inc->p
  }
  
  vec pref(m);
  REP(i,m){
    cin >> pref[i];
    bP.push_back(inc[i]+pref[i]);
    bM.push_back(inc[i]-pref[i]);
  }

  sort(val.begin(),val.end());
  sort(bP.begin(),bP.end());
  sort(bM.begin(),bM.end());
  
  BIT bitP(vec(bP.size(),0)), bitM(vec(bM.size(),0));
  vec ans(m,0);
  int cnt = 0; //
  REP(i,val.size()){
    int id = val[i].sc;
    if(id < 100000){
      cnt++;
      int tmp = lower_bound(bP.begin(),bP.end(),b[id]+p[id]) - bP.begin();
      bitP.add(tmp,1);
      tmp = lower_bound(bM.begin(),bM.end(),p[id]-b[id]) - bM.begin();
      bitM.add(tmp,1);
    }
    else if(id < 200000){
      id -= 100000;
      ans[id] -= cnt;
      int tmp = lower_bound(bP.begin(),bP.end(),inc[id]+pref[id]) - bP.begin();
      ans[id] += bitP.sum(tmp);
      tmp = lower_bound(bM.begin(),bM.end(),inc[id]-pref[id]) - bM.begin();
      ans[id] += bitM.sum(tmp);   
    }
    else{
      id -= 200000;
      cnt--;
      int tmp = lower_bound(bP.begin(),bP.end(),b[id]+p[id]) - bP.begin();
      bitP.add(tmp,-1);
      tmp = lower_bound(bM.begin(),bM.end(),p[id]-b[id]) - bM.begin();
      bitM.add(tmp,-1);   
    }
  }

  REP(i,m) cout << ans[i] << " ";
  cout << endl;


  return 0;
}