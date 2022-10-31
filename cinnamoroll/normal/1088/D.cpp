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

  cout << "? " << 0 << " " << 0 << endl;
  int tmp;
  cin >> tmp;

  int a = 0, b = 0;
  bool flag = false;
  RREP(i,30){
    //
    if(flag){
      cout << "? " << a << " " << b << endl;
      cout.flush();
      cin >> tmp;
      flag = false;
    }

    //101
    cout << "? " << (1LL<<i)+a << " " << (1LL<<i)+b << endl;
    cout.flush();
    int y;
    cin >> y;

    if(tmp != 0  && tmp == -y){
      if(tmp == 1) a += (1LL<<i);
      else b += (1LL<<i);
      flag = true;
    }

    // 11or00
    else{
      cout << "? " << a << " " << (1LL<<i)+b << endl;
      cout.flush();
      cin >> y;
      if(y == 1){
        a += (1LL<<i);
        b += (1LL<<i);
      }
    }
  }

  cout << "! " << a << " " << b << endl;
  cout.flush();

  return 0;
}