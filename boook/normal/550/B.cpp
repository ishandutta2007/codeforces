#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
#define PII pair<int , int>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 30
#define INF 0x3f3f3f3f

int n , l , r , a;
int x[MAX];

int32_t main(){
    cin >> n >> l >> r >> a;
    REP(i , 0 , n) cin >> x[i];
    sort(x , x + n);
    int ans = 0;
    REP(i , 1 , (1 << n)){
        bitset<30> tmp(i);
        vector<int> now;
        int sum = 0;
        REP(j , 0 , n){
            if(tmp.test(j)) now.pb(x[j]) , sum += x[j];
        }
        if(now.size() >= 2){
            int res = now.back() - now[0];
            if(res >= a){
                if(l <= sum && sum <= r){
                    ans ++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}