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
#define MAX 100000
#define INF 0x3f3f3f3f

set<char> a , b , c;
int n;
string p[MAX];
int32_t main(){
    cin >> n;
    REP(i , n) cin >> p[i];
    REP(i , n) REP(j , n){
        c.insert(p[i][j]);
        if(i == j || i + j == n - 1) a.insert(p[i][j]);
        else b.insert(p[i][j]);
    }
    if(a.size() == 1 && b.size() == 1 && c.size() == 2) puts("YES");
    else puts("NO");
    return 0;
}