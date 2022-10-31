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

  int t;
  cin >> t;
  
  REP(_,t){
    int n,m;
    cin >> n >> m;

    int x1,x2,y1,y2,x3,x4,y3,y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    int b = n*m/2, w = n*m/2 + ((n*m)%2==1?1:0);
    //debug(n*m);
    //debug(b+w);
    if((x2-x1)%2==1 || (y2-y1)%2==1){
      w += (x2-x1+1)*(y2-y1+1)/2;
      b -= (x2-x1+1)*(y2-y1+1)/2;
    }
    else{
      if((y1+x1)%2==1){
        w += (x2-x1+1)*(y2-y1+1)/2 + 1;
        b -= (x2-x1+1)*(y2-y1+1)/2 + 1;
      }
      else{
        w += (x2-x1+1)*(y2-y1+1)/2;
        b -= (x2-x1+1)*(y2-y1+1)/2;
      }
    }

    //    debug(b);
    //debug(w);

    if((x4-x3)%2==1 || (y4-y3)%2==1){
      b += (x4-x3+1)*(1+y4-y3)/2;
      w -= (x4-x3+1)*(1+y4-y3)/2;
    }
    else{
      if((y3+x3)%2==0){
        b += (1+x4-x3)*(1+y4-y3)/2 + 1;
        w -= (x4-x3+1)*(1+y4-y3)/2 +1;
      }
      else{
        b += (x4-x3+1)*(1+y4-y3)/2;
        w -= (x4-x3+1)*(1+y4-y3)/2;
      }
    }
    //debug(b);
   // debug(w);

    if(x2 < x3 || x1 > x4 || y1 > y4 || y2 < y3) ;
    else{
      int cnt = abs((min(x2,x4)-max(x3,x1)+1)*(min(y2,y4)-max(y3,y1)+1));
    //  debug(cnt);
      if((min(x2,x4)-max(x3,x1))%2==1 || (min(y2,y4)-max(y3,y1))%2 == 1){
      w -= cnt/2;
      b += cnt/2;
      }
      else {
       if((min(x2,x4)+min(y2,y4))%2 == 1){
          w -= cnt/2+1;
          b += cnt/2+1;
        }
        else{
          w -= cnt/2;
          b += cnt/2;
        }
      }
    }

  cout << w << " " << b << endl;

  }


  return 0;
}