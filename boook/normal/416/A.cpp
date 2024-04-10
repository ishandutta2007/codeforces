#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i,j)       for(int i = 0 ; i < j ; i++)
#define REPNM(i,j,k)   for(int i = j ; i < k ; i++)
#define RREP(i,j,k)    for(int i = j ; i >=k ; i--)
#define A    first
#define B    second
#define pb   push_back
#define mp   make_pair
#define PII pair<int , int>
#define VI  vector<int> 
#define VPII vector<PII>
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie() , cout.sync_with_stdio(0)
///------------------------------------------------------------
#define int long long
#define MAX 
#define INF 2000000000LL

string a , b;
int n , l , r;
int32_t main(){
    l = -INF , r = INF;
    cin >> n;
    REP(i , n){
        int tmp;
        cin >> a >> tmp >> b;
        if(a == ">="){
            if(b == "Y") l = max(l , tmp);
            else r = min(r , tmp - 1);
        }
        if(a == "<="){
            if(b == "Y") r = min(r , tmp);
            else l = max(l , tmp + 1);
        }
        if(a == ">"){
            if(b == "Y") l = max(l , tmp + 1);
            else r = min(r , tmp);
        }
        if(a == "<"){
            if(b == "Y") r = min(r , tmp - 1);
            else l = max(l , tmp);
        }
        // DB4(a , tmp , b , i);
        // DB4("now = " , l , r , "");
    }
    if(l > r) puts("Impossible");
    else cout << l << "\n";
    return 0;
}