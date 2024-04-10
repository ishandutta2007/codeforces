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
#define INF 1LL<<60
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
#define debug(x)  cout << #x << " = " << (x) << endl;
typedef pair<int,int> P;
typedef vector<vector<P>> Graph;

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);  

  int n,m;
  cin >> n >> m;

  vector<int> a(2*n);
  vector<P> tmp;
  REP(i,2*n){
    cin >> a[i];
    tmp.pb(P(a[i],i));
  }
  
  vector<P> p(m);
  REP(i,m){
    int xxx,yyy;
    cin >> xxx >> yyy;
    xxx--;
    yyy--;
    if(a[xxx] < a[yyy]) swap(xxx,yyy);
    p[i] = P(xxx,yyy);
  }
  
  int t;
  cin >> t;

  vector<int> flag(2*n,0);
  sort(tmp.begin(),tmp.end());
  reverse(tmp.begin(),tmp.end());
  
  if(t == 1){
    REP(_,n){
      if(m > 0){
        m--;
        flag[p[m].fs]++;
        cout << p[m].fs+1 << endl;
      }
      else{
        REP(i,2*n){
          if(flag[tmp[i].sc]) continue;
          flag[tmp[i].sc]++;
          cout << tmp[i].sc+1 << endl;
          break;
        }
      }
      cout.flush();
      int res;
      cin >> res;
      res--;
      flag[res]++;
    }
  }

  else{
      int res;
      cin >> res;
      res--;
      flag[res]++;
    REP(x,n){
      bool f = true;
      REP(i,m){
        if(p[i].fs == res && !flag[p[i].sc]){
          cout << p[i].sc+1 << endl;
          flag[p[i].sc]++;
          f = false;
          break;
        }
        if(p[i].sc == res && !flag[p[i].fs]){
          cout << p[i].fs+1 << endl;
          flag[p[i].fs]++;
          f = false;
          break;
        }
      }

      if(f){
        bool ff = true;
        REP(i,m){
          if(flag[p[i].fs]) continue;
          cout << p[i].fs+1 << endl;
          ff = false;
          flag[p[i].fs]++;
          break;
        }
        if(ff){
          REP(i,2*n){
            if(flag[tmp[i].sc]) continue;
            flag[tmp[i].sc]++;
            cout << tmp[i].sc+1 << endl;
            break;
          }      
        }  
      }

      if(x != n-1){
        cout.flush();
      cin >> res;
      res--;
      flag[res]++;
      }
    }
  }

  cout << endl;
  cout.flush();

  return 0;
}