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
#define MAX 1000900
#define INF 0x3f3f3f3f

int n , m , now , x[MAX];
int F(int now , int l , int r){
    if(l > r || l < 0 || r > n - 1) return 0;
    l = x[l] , r = x[r];
    if(l <= now && now <= r) return (r - l) * 2;
    else return max(abs(now - r) , abs(now - l)) * 2;
}
int32_t main(){
    IOS;
    cin >> n >> m;
    REP(i , n) cin >> x[i] , x[i] *= 10;
    if(n & 1) now = x[n / 2];
    else now = (x[n / 2 - 1] + x[n / 2]) / 2;
    int ans = 0;
    int l = 0 , r = n - 1;
    while(l <= r){
        int a = min(l + m - 1 , r);
        int b = max(r - m + 1 , l);
        int vala = F(now , l , a);
        int valb = F(now , b , r);
        if(x[a] < now) l = a + 1 , ans += vala;
        if(x[b] > now) r = b - 1 , ans += valb;
        if(x[a] >= now && x[b] <= now){
            ans += (x[r] - x[l]) * 2;
            // int tma = F(now , l , b - 1);
            // int tmb = F(now , a + 1 , r);
            // ans += min(tma + valb , tmb + vala);
            break;
        }         
    }
    cout << ans / 10 << "\n";
    return 0;
}