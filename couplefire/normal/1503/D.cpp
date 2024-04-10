#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int , int> pii;
typedef long double ld;

const int N = 2e5+10 , mod = 1e9+7;

void solve(){
   int n;
   cin >> n;
   int oth[2 * n + 1] , num[2 * n + 1];
   for(int i = 0 ; i < n ; i++){
      int a , b;
      cin >> a >> b;
      oth[a] = b;
      oth[b] = a;
      num[a] = 1;
      num[b] = 0;
   }
   int l1 = 0 , r1 = 2 * n + 1 , l2 = 2 * n + 1 , r2 = 0;
   int cur_min = 1 , cur_max = 2 * n;
   int ans = 0;
   bool mark[2 * n + 1];
   memset(mark , 0 , sizeof(mark));
   while(cur_min <= cur_max){
      int sum = 0 , tot = 0;

      r1 = cur_max--;
      mark[r1] = true;
      r2 = oth[r1];
      mark[r2] = true;
      tot++;
      sum += num[r1];

      while(l2 < cur_max || r2 > cur_min){
         while(r2 > cur_min){
            if(mark[cur_min]){
               cur_min++;
               continue;
            }
            if(cur_min < l1){
               cout << "-1\n";
               return;
            }
            l1 = cur_min++;
            mark[l1] = true;
            sum += num[l1];
            tot++;
            if(l2 < oth[l1]){
               cout << "-1\n";
               return;
            }
            mark[oth[l1]] = true;
            l2 = oth[l1];
         }

         while(l2 < cur_max){
            if(mark[cur_max]){
               cur_max--;
               continue;
            }
            if(cur_max > r1){
               cout << "-1\n";
               return;
            }
            r1 = cur_max--;
            mark[r1] = true;
            sum += num[r1];
            tot++;
            if(r2 > oth[r1]){
               cout << "-1\n";
               return;
            }
            mark[oth[r1]] = true;
            r2 = oth[r1];
         }
      }
      while(cur_max >= cur_min && mark[cur_max]){
         cur_max--;
      }
      while(cur_min <= cur_max && mark[cur_min]){
         cur_min++;
      }
      //cout << l1 << " " << r1 << " " << l2 << " " << r2 << endl;
      ans += min(sum , tot - sum);
   }
   if(l1 > r1 || l2 < r2){
      cout << "-1\n";
      return;
   }
   cout << ans << "\n";
}

int32_t main(){
   ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
   int t = 1;
   //cin >> t;
   while(t--){
      solve();
   }
   return 0;
}