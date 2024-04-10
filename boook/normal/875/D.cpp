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
#define mid ((l + r) >> 1)
#define ls (now << 1)
#define rs (now << 1 | 1)

int b[MAX * 4];
int n , x[MAX] , l[MAX] , r[MAX];
void Build(int now , int l , int r){
    if(l == r) b[now] = x[l];
    else {
        Build(ls , l , mid);
        Build(rs , mid + 1 , r);
        b[now] = b[ls] | b[rs];
    }
}
int pat;
int query(int now , int l , int r , int ql , int qr , int ty){
    if(ql <= l && r <= qr){
        if(b[now] & pat){
            // if(l == r) DB4("QQ" , l , pat , b[now]);
            if(l == r) return l;
            else if(ty == 1){
                if(b[rs] & pat) return query(rs , mid + 1 , r , ql , qr , ty);
                return query(ls , l , mid , ql , qr , ty);
            }
            else {
                if(b[ls] & pat) return query(ls , l , mid , ql , qr , ty);
                return query(rs , mid + 1 , r , ql , qr , ty);
            }
        }
        else{
            if(ty == 1) return ql - 1;
            else return qr + 1;
        }
    }
    else if(qr <= mid) return query(ls , l , mid , ql , qr , ty);
    else if(mid + 1 <= ql) return query(rs , mid + 1 , r , ql , qr , ty);
    else {
        int a = query(ls , l , mid , ql , qr , ty);
        int b = query(rs , mid + 1 , r , ql , qr , ty);
        if(ty == 1) return max(a , b);
        else return min(a , b);
    }
}
int L(int id , int val){ return x[id] >  val ? id : L(l[id] , val); }
int R(int id , int val){ return x[id] >= val ? id : R(r[id] , val); }
int32_t main(){
    IOS;
    cin >> n;
    x[0] = x[n + 1] = INF;
    REP(i , 1 , n + 1) cin >> x[i];

    REP(i , 1 , n + 1) l[i] = L(i - 1 , x[i]);
    RREP(i , n , 1)    r[i] = R(i + 1 , x[i]);

    // REP(i , 1 , n + 1) cout << l[i] << " " ; cout << endl;
    // REP(i , 1 , n + 1) cout << r[i] << " " ; cout << endl;

    Build(1 , 1 , n);

    int ans = 0;
    REP(i , 1 , n + 1){
        int ppo = 0 , ttmp = x[i];
        pat = 0;
        while(ttmp){
            if(ttmp % 2 == 0) pat |= (1LL << ppo);
            ppo ++;
            ttmp /= 2;
        }
        // DBGG("pat = " , pat);
        int fr = l[i] + 1 , ba = r[i] - 1;
        int tma = query(1 , 1 , n , fr , i ,  1) + 1;
        int tmb = query(1 , 1 , n , i , ba , -1) - 1;
        // DB4("?? = " , fr , i , tma);

        // DB4("fr = " , fr , "ba = " , ba);
        // DB4("tma = " , tma , "tmb = " , tmb);
        ans += (i - fr + 1) * (ba - i + 1) - (i - tma + 1) * (tmb - i + 1);
        // DB4("ans = " , ans , (i - fr + 1) * (ba - i + 1) , (i - tma + 1) * (tmb - i + 1));
    }
    cout << ans << endl;
    return 0;
}