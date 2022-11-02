/*input
5
5 4 3 2 1
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
#define IOS cin.tie() , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define int long long
#define MAX 200900
#define INF 0x3f3f3f3f
#define mid (l + (r - l) / 2)
#define L -500000
#define R 1000000000

int n , x[MAX] , fr[MAX] , ba[MAX];
vector<int> v;
PII big[MAX * 60];
int ls[MAX * 60] , rs[MAX * 60] , po = 2;
void update(int now , int l , int r , int k , PII val){
    if(l == r) big[now] = max(big[now] , val);
    else {
        if(k <= mid + 0 && ls[now] == 0) ls[now] = po ++;
        if(k <= mid + 0) update(ls[now] , l , mid + 0 , k , val); 
        if(mid + 1 <= k && rs[now] == 0) rs[now] = po ++; 
        if(mid + 1 <= k) update(rs[now] , mid + 1 , r , k , val);
        big[now] = max(big[ls[now]] , big[rs[now]]);
    }
}
PII query(int now , int l , int r , int ql , int qr){
    if(ql <= l && r <= qr) return big[now];
    if(qr <= mid + 0) return query(ls[now] , l , mid + 0 , ql , qr);
    if(mid + 1 <= ql) return query(rs[now] , mid + 1 , r , ql , qr);
    return max(query(ls[now] , l , mid + 0 , ql , qr) , query(rs[now] , mid + 1 , r , ql , qr));
}
int32_t main(){
    IOS;
    cin >> n;
    REP(i , 1 , n + 1) cin >> x[i];
    REP(i , 1 , n + 1) x[i] -= i;

    REP(i , 1 , n + 1){
        if(v.empty() || v.back() <= x[i]){
            v.pb(x[i]);
            fr[i] = v.size();
        }
        else {
            int tmp = upper_bound(ALL(v) , x[i]) - v.begin();
            v[tmp] = x[i];
            fr[i] = tmp + 1;
        }
    }
    v.clear();
    RREP(i , n , 1){
        x[i] *= -1;
        if(v.empty() || v.back() <= x[i]){
            v.pb(x[i]);
            ba[i] = v.size();
        }
        else {
            int tmp = upper_bound(ALL(v) , x[i]) - v.begin();
            v[tmp] = x[i];
            ba[i] = tmp + 1;
        }
        x[i] *= -1;
    }
    // REP(i , 1 , n + 1) cout << fr[i] << " "; cout << endl;
    // REP(i , 1 , n + 1) cout << ba[i] << " "; cout << endl;
    int ans = 0;
    map<int , int> cc;
    REP(i , 1 , n + 1){
        PII tmp = query(1 , L , R , L , x[i] + 1);
        PII res = query(1 , L , R , L , x[i]);
        int good = ba[i] + res.A;
        if(good != n) good ++;
        ans = max(ans , good);
        if(-tmp.B == i - 1) ans = max(ans , ba[i] + tmp.A);
        else                ans = max(ans , ba[i] + tmp.A + 1);
        update(1 , L , R , x[i] , mp(fr[i] , -i));
    }
    cout << n - ans << endl;
    return 0;
}