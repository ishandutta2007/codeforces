#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define mp   make_pair
#define pb   emplace_back
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 300900
#define INF 0x3f3f3f3f

int n , w , k;
int val[MAX] , x[MAX];

set<PII> sml , big;
int good = 0 , times = 0;
int maintain(){
    if(times <= k) return 1;
    else {
        while(sml.size() && big.size() < w){
            auto tmp = sml.end(); tmp --;
            times -= (*tmp).A;
            times += ((*tmp).A + 1) / 2;
            big.insert(*tmp);
            sml.erase(tmp);
            if(times <= k) return 1;
        }
        while(sml.size() && big.size()){
            auto q = sml.end(); q --;
            auto w = big.begin();
            if((*q).A <= (*w).A) break;
            else {
                times +=  ((*q).A + 1) / 2;
                big.insert(*q);

                times += (*w).A;
                sml.insert(*w);

                times -= (*q).A;
                sml.erase(q);
                
                times -=  ((*w).A + 1) / 2;
                big.erase(w);
            }
        }
        if(times <= k) return 1;
        else return 0;
    }
}
int32_t main(){
    IOS;
    cin >> n >> w >> k;
    REP(i , 1 , n + 1) cin >> val[i];
    REP(i , 1 , n + 1) cin >> x[i];

    int r = 0 , ans = 0;
    REP(l , 1 , n + 1){
        while(maintain()){
            ans = max(ans , good);
            // cout << "times = " << times << " ";
            // DB4("now = " , l , r , good);
            if(r == n) break;
            else{
                sml.insert(mp(x[r + 1] , r + 1));
                times += x[r + 1];
                good += val[r + 1];
                r ++;
            }
        }
        if(sml.find(mp(x[l] , l)) != sml.end())
            sml.erase(mp(x[l] , l)) , times -= x[l];
        if(big.find(mp(x[l] , l)) != big.end())
            big.erase(mp(x[l] , l)) , times -= (x[l] + 1) / 2;
        good -= val[l];
    }
    cout << ans << endl;
    return 0;
}