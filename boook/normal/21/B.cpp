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
#define MAX 
#define INF 0x3f3f3f3f

int a , b , c;
int q , w , e;

int32_t main(){
    cin >> a >> b >> c;
    cin >> q >> w >> e;
    if(a == 0 && b == 0 && q == 0 && w == 0){
        if(c == 0 && e == 0) puts("-1");
        else puts("0");
    }
    else if(a * w == b * q){
        if(a == 0 && q == 0 && b * e == c * w) puts("-1");
        else if((a != 0 || q != 0) && a * e == c * q) puts("-1");
        else puts("0");
    }
    else puts("1");
    return 0;
}