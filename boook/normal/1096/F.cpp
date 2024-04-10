/*input
2
-1 -1
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define REP(i, j, k)  for(int i = j; i <  k; ++i)
#define RREP(i, j, k) for(int i = j; i >= k; --i)
#define F first
#define S second
#define mp make_pair
#define pb emplace_back
#define PII pair<int , int>
#define DBGG(i,j)     cout << i << " " << j << endl
#define DB4(i,j,k,l)  cout << i << " " << j << " " << k << " " << l << endl
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 200009
#define INF 0x3f3f3f3f
#define mod 998244353LL

int bit[MAX];
void update(int from , int val){
    for(int i = from + 1 ; i < MAX ; i += i & -i)
        bit[i] += val;
}
int query(int from){
    int cnt = 0;
    for(int i = from + 1 ; i > 0 ; i -= i & -i)
        cnt += bit[i];
    return cnt;
}
int ppow(int a , int k){
    if(k == 0) return 1;
    if(k % 2 == 0) return ppow(a * a % mod , k >> 1);
    if(k % 2 == 1) return ppow(a * a % mod , k >> 1) * a % mod;
}
int gi[MAX] , ni[MAX];
int C(int a , int b){
    if(a < b) return 0;
    else return gi[a] * ni[b] % mod * ni[a - b] % mod;
}
void getcountmath(){
    gi[0] = gi[1] = ni[0] = ni[1] = 1;
    REP(i , 2 , MAX) gi[i] = gi[i - 1] * i % mod;
    REP(i , 2 , MAX) ni[i] = ni[mod % i] * (mod - mod / i) % mod;
    REP(i , 1 , MAX) ni[i] = ni[i - 1] * ni[i] % mod;
}

int n , x[MAX] , r[MAX];
int32_t main(){
    IOS;
    getcountmath();
    cin >> n;
    int no = 0;
    REP(i , 1 , n + 1) cin >> x[i];
    REP(i , 1 , n + 1) no += x[i] == -1;


    int base = 0;
    RREP(i , n , 1) if(x[i] != -1){
        base = (base + query(x[i])) % mod;
        update(x[i] , 1);
    }
    memset(bit , 0 , sizeof bit);

    REP(i , 1 , n + 1) if(x[i] != -1) r[x[i]] = i;
    

    REP(i , 1 , n + 1) if(r[i] == 0) update(i , 1);
    int ans = 0 , cnt = 0;
    REP(i , 1 , n + 1){
        if(x[i] == -1){
            ans = (ans + cnt) % mod;
        }
        else {
            cnt = (cnt + query(x[i])) % mod;
        }
    }
    cnt = 0;
    RREP(i , n , 1){
        if(x[i] == -1){
            ans = (ans + cnt) % mod;
        }
        else {
            cnt = (cnt + no - query(x[i]) + mod) % mod;
        }
    }


    if(no >= 1) ans = ans * gi[no - 1] % mod;
    // DBGG("ans = " , ans);
    // DBGG("base = " , base);
    int las = 0 , div2 = ppow(2 , mod - 2);
    las = C(no , 2) * div2 % mod * gi[no] % mod;

    ans = (ans + las) % mod;


    ans = (ans + base * gi[no]) % mod;
    // DBGG("las = " , las);
    // cout << ans << " " << gi[no] << endl;

    int final = ans * ppow(gi[no] , mod - 2) % mod;
    cout << final << endl;
    return 0;
}/*
1 2 4 3 5 
1 2 4 5 3 
1 3 4 2 5 
1 3 4 5 2 
1 5 4 2 3 
1 5 4 3 2 
19 6
[Finished in 1.8s]
*/