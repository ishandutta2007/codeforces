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
#define MAX 
#define INF 0x3f3f3f3f

int n;
int X[] = {-1 , -2 , -1 ,  1 , 2 , 1};
int Y[] = {2  ,  0 , -2 , -2 , 0 , 2};
int32_t main(){
    cin >> n;
    PII now = mp(0 , 0);
    int l = 0 , r = 600000000;
    while(r - l > 1){
        int mid = (l + r) / 2;
        if((mid * mid + mid) * 3 >= n) r = mid;
        else l = mid;
    }
    n -= 3 * r * (r - 1);
    now.A += 2 * (r - 1);
    int tmp = r;
    if(n){
        now.A += 2;
        REP(i , 0 , 6){
            if(n >= tmp) now.A += X[i] * tmp , now.B += Y[i] * tmp , n -= tmp;
            else now.A += X[i] * n , now.B += Y[i] * n , n -= n;
        }
    }
    cout << now.A << " " << now.B << endl;
    return 0;
}