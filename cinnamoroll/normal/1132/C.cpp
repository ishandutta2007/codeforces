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

signed main(){
  ios::sync_with_stdio(false);
  cin.tie(0);  
  //
  //
  //DP

  int n,q;
  cin >> n >> q;

  vec a(q),b(q);
  REP(i,q) cin >> a[i] >> b[i];
  
  vec tmp(n+1,0);
  REP(k,q){
    tmp[a[k]-1]++; tmp[b[k]]--;
  }
  REP(k,n) tmp[k+1] += tmp[k];

  vec sum1(n+1,0), sum2(n+1,0);
  REP(i,n){
    if(tmp[i] == 1) sum1[i+1]++;
    if(tmp[i] == 2) sum2[i+1]++;
  }

  int mx = 0;
  REP(i,n){
    sum1[i+1] += sum1[i];
    sum2[i+1] += sum2[i];
    if(tmp[i]) mx++;
    //cout << sum1[i] SP sum2[i] << endl;
  }
  
  int ans = 0;
  REP(i,q-1){
    FOR(j,i+1,q){
      if(a[i] < a[j]){
        if(b[i] < a[j]){
          ans = max(ans,mx-(sum1[b[j]]-sum1[a[j]-1])-(sum1[b[i]]-sum1[a[i]-1]));
        }
        else{
          if(b[i] < b[j]) ans = max(ans,mx-(sum1[a[j]-1]-sum1[a[i]-1])-(sum1[b[j]]-sum1[b[i]])-(sum2[b[i]]-sum2[a[j]-1]));
          else ans = max(ans,mx-(sum1[a[j]]-sum1[a[i]-1])-(sum1[b[i]]-sum1[b[j]])-(sum2[b[j]]-sum2[a[j]-1]));
        }
      }
      else if(a[i] > a[j]){
        if(b[j] < a[i]){
          ans = max(ans,mx-(sum1[b[j]]-sum1[a[j]-1])-(sum1[b[i]]-sum1[a[i]-1]));
        }
        else{
          if(b[i] > b[j]) ans = max(ans,mx-(sum1[a[i]-1]-sum1[a[j]-1])-(sum1[b[i]]-sum1[b[j]])-(sum2[b[j]]-sum2[a[i]-1]));
          else ans = max(ans,mx-(sum1[a[i]]-sum1[a[j]-1])-(sum1[b[j]]-sum1[b[i]])-(sum2[b[i]]-sum2[a[i]-1]));
        }
      }
      else ans = max(ans,mx-(sum2[min(b[i],b[j])]-sum2[a[i]-1])-(sum1[max(b[i],b[j])]-sum1[min(b[i],b[j])-1]));
      //debug(ans);
    }
  }

  cout << ans << endl;

  return 0;
}