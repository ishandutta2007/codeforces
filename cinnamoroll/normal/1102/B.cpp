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
#define range(i,a,b) (a)<=(i) && (i)<(b)
#define debug(x)  cout << #x << " = " << (x) << endl;
#define SP << " " << 
typedef pair<int,int> P;
typedef vector<vector<P> > Graph;

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);  

  int n,k;
  cin >> n >> k;

  vector<int> a(n);
  REP(i,n) cin >> a[i];
  
  map<int,int> mp;
  REP(i,n) mp[a[i]]++;

  ITR(itr,mp){
    if(itr->sc > k){
      cout << "NO" << endl;
      return 0;
    }
  }

  if(n < k){
    cout << "NO" << endl;
    return 0;
  }

  cout << "YES" << endl;
  queue<int> que[mp.size()];
  map<int,int> index;
  
  int id = 0,cnt = 0;

  ITR(itr,mp){
    index[itr->fs] = id;
    REP(i,itr->sc){
      que[id].push(cnt%k+1);
      cnt++;
    }
    id++;
  }

  REP(i,n){
    cout << que[index[a[i]]].front() << " ";
    que[index[a[i]]].pop();
  }

  return 0;
}