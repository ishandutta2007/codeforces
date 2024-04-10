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

int query(int a,int b, int c, int d){
  cout << "?" SP a SP b SP c SP d << endl;
  cout.flush();
  int x;
  cin >> x;
  return x;
}

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  vec a(n+1,0),b(n+1,0);
  REP(i,n) a[i+1] = query(1,1,i+1,n);

  REP(i,n) b[i+1] = query(1,1,n,i+1);

  int Xa = -1,Ya = -1,Xb = -1,Yb = -1;
  REP(i,n){
    if(a[i]%2 != a[i+1]%2){
      if(Xa == -1) Xa = i+1;
      else Ya = i+1;
    }
  }

  REP(i,n){
    if(b[i]%2 != b[i+1]%2){
      if(Xb == -1) Xb = i+1;
      else Yb = i+1;
    }
  }

  if(Xa != -1 && Xb != -1){
    if(query(1,1,Xa,Xb)%2){
      cout << "!" SP Xa SP Xb SP Ya SP Yb << endl;
    }
    else{
      cout << "!" SP Xa SP Yb SP Ya SP Xb << endl;
    }  
  }

  else if(Xa == -1){
    int ok = n, ng = 0;
    while(ok-ng>1){
      int mid = (ok+ng)/2;
      if(query(1,1,mid,Xb)%2) ok = mid;
      else ng = mid;
    }
    cout << "!" SP ok SP Xb SP ok SP Yb << endl;
  }

  else if(Xb == -1){
    int ok = n, ng = 0;
    while(ok-ng>1){
      int mid = (ok+ng)/2;
      if(query(1,1,Xa,mid)%2) ok = mid;
      else ng = mid;
    }
    cout << "!" SP Xa SP ok SP Ya SP ok << endl;
  }

  cout.flush();

  return 0;
}