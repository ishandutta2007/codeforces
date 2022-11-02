/*input

*/
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
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
// #define endl "\n"
///------------------------------------------------------------
#define MAX 
#define INF 0x3f3f3f3f

int n;
int in(int i , int j){
    return 1 <= i && i <= n && 1 <= j && j <= n;
}
int query(int i , int j , int l , int r){
    if(in(i , j) && in(l , r) && i <= l && j <= r){
        assert(l - i + r - j >= n - 1);
        cout << "? " << i << " " << j << " " << l << " " << r << endl;
        fflush(stdout);
        string s; cin >> s;
        return s == "YES";
    }
    return 0;
}
int32_t main(){
    IOS;
    cin >> n;
    int x = n , y = n;

    string ba , fr;
    REP(i , 0 , n - 1){
        if(query(1 , 1 , x - 1 , y)) ba += "D" , x --;
        else ba += "R" , y --;
    }
    // cout << "HERe" << endl;
    reverse(ALL(ba));
    int nowx = 1 , nowy = 1;
    REP(i , 0 , n - 1){
        if(ba[i] == 'D') x ++;
        else y ++;
        if(query(nowx , nowy + 1 , x , y)) 
            fr += "R" , nowy ++;
        else 
            fr += "D" , nowx ++;
        // DBGG("get = " , fr.back());
    }
    cout << "! " << fr << ba << endl;
    return 0;
}