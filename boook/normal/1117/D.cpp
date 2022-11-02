/*input
1000000000000000 100
*/
#include <iostream>
#include <vector>
using namespace std;
#define REP(i,j,k)     for(int i = j ; i < k ; ++i)
#define RREP(i,j,k)    for(int i = j ; i >=k ; --i)
#define MEM(i,j)   memset(i , j , sizeof i)
#define ALL(i)     i.begin() , i.end()
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 100000
#define INF 0x3f3f3f3f
#define mod 1000000007LL

int n , k , x[MAX] , c[MAX];
vector<int> mul(vector<int> a , vector<int> b){
    vector<int> ans(n + n + 1);
    REP(i , 1 , n + 1) REP(j , 1 , n + 1)
        ans[i + j] = (ans[i + j] + (a[i] * b[j])) % mod;
    RREP(i , n + n , n + 1){
        REP(j , 1 , n + 1) ans[i - j] = (ans[i - j] + ans[i] * c[j]) % mod;
        ans[i] = 0;
    }
    // cout << "final = " << ans.size() << endl;
    // REP(i , 1 , n + 1) cout << ans[i] << " "; cout << endl;
    return ans;
}
vector<int> ppow(vector<int> a , int k){
    if(k == 1) return a;
    if(k % 2 == 0) return     ppow(mul(a , a) , k >> 1);
    if(k % 2 == 1) return mul(ppow(mul(a , a) , k >> 1) , a);
}
int nn , mm;
int32_t main(){
    IOS;
    cin >> nn >> mm;
    if(nn < mm) cout << 1 << endl;
    else if(nn < mm + mm) cout << nn - mm + 2 << endl;
    else {
        n = mm + mm - 2;
        REP(i , 1 , n + 1) x[i] = i < mm ? 1 : i - mm + 2;
        REP(i , 1 , n + 1) if(i <= mm) c[n + 1 - i] = 1;
        // REP(i , 1 , n + 1) cout << c[i] << " "; cout << endl;
        vector<int> v(n + n + 1);
        v[1] = 1;
        v = ppow(v , nn);
        int ans = 0;
        REP(i , 1 , n + 1) ans = (ans + x[i] * v[i]) % mod;
        cout << ans << endl;
    }
    return 0;
}


// while(cin >> n && n){
    //     REP(i , 1 , n + 1) cin >> x[i];
    //     REP(i , 1 , n + 1) cin >> c[i];
    //     vector<int> v(n + n + 1);
    //     v[1] = 1;
    //     cin >> k , k ++;
    //     v = ppow(v , k);
    //     int ans = 0;
    //     REP(i , 1 , n + 1) ans = (ans + x[i] * v[i]) % mod;
    //     cout << ans << endl;
    // }