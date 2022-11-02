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
#define MAX 
#define INF 0x3f3f3f3f

vector<int> v;
int n;
int F(int now){ return now * now * now; }
int FFFF(int val){
    int cnt = 0;
    while(val){
        int now = 1;
        RREP(i , 17 , 0){
            int to = now + (1 << i);
            if(to * to * to <= val) now = to;
        }
        now = now * now * now;
        while(val >= now) val -= now , cnt ++;
    }
    return cnt;
}
int32_t main(){
    int nxt = 2 , val = 1 , sum = 0;
    cin >> n;
    while(sum + val <= n){
        sum += val;
        v.pb(nxt - 1);
        while(sum + val >= nxt * nxt * nxt){
            val = nxt * nxt * nxt;
            nxt ++;
            if(sum + val > n) break;
        }
    }
    RREP(i , v.size() - 1 , 0){
        while(1){
            v[i] ++;
            int tmp = 0;
            REP(j , 0 , v.size()){
                tmp += F(v[j]);
            }
            if(FFFF(tmp) != v.size() || tmp > n){
                v[i] --;
                break;
            }
        }
    }
    int tmp = 0;
    REP(j , 0 , v.size()){
        tmp += F(v[j]);
    }
    cout << v.size() << " " << tmp << endl;
    return 0;
}