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
#define MAX 
#define INF 0x3f3f3f3f

map<int , int> cc;
int n;
int32_t main(){
    cin >> n;
    int big = 0;
    REP(i , 1 , n + 1){
        int tmp;
        cin >> tmp;
        cc[tmp] ++;
        big = max(big , cc[tmp]);
    }
    if(cc.size() == 2 && big == n / 2){
        cout << "YES" << endl;
        for(auto to : cc) cout << to.A << " " ; cout << endl;
    }
    else cout << "NO" << endl;
    return 0;
}