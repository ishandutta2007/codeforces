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
#define MAX 5
#define INF 0x3f3f3f3f
#define mod 1000000007LL

int n;
string s;

int cnt[MAX];
int32_t main(){
    cin >> n >> s;
    REP(i , 0 , s.size()){
        if(s[i] == 'A') cnt[0] ++;
        if(s[i] == 'T') cnt[1] ++;
        if(s[i] == 'C') cnt[2] ++;
        if(s[i] == 'G') cnt[3] ++;
    }
    int mm = cnt[0] , res = 0;
    REP(i , 0 , 4) mm = max(cnt[i] , mm);
    REP(i , 0 , 4) if(cnt[i] == mm) res ++;
    int ans = 1;
    REP(i , 0 , s.size()){
        ans = ans * res % mod;
    }

    cout << ans << endl;
    return 0;
}