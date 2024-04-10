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
#define RI(i)       scanf("%d" , &i)
#define RII(i,j)    scanf("%d%d" , &i , &j)
#define RIII(i,j,k) scanf("%d%d%d" , &i , &j , &k)
#define RL(i)       scanf("%lld" , &i)
#define RLL(i,j)    scanf("%lld%lld" , &i , &j)
#define RLLL(i,j,k) scanf("%lld%lld%lld" , &i , &j , &k)
#define AS assert
#define IOS cin.tie() , cout.sync_with_stdio(0)
///------------------------------------------------------------
#define MAX 100090
#define INF 0x3f3f3f3f
#define ls (now << 1)
#define rs (now << 1 | 1)
#define mid ((l + r) >> 1)

int tag[30][MAX * 4] , sum[30][MAX * 4];
int n , m;
string s;
void Push(int ty , int now , int l , int r){
    if(tag[ty][now] && r > l){
        tag[ty][ls] = tag[ty][rs] = tag[ty][now];
        sum[ty][ls] = (mid - l + 1) * (tag[ty][now] - 1);
        sum[ty][rs] = (r - (mid + 1) + 1) * (tag[ty][now] - 1);
        tag[ty][now] = 0;
    }
}
void Pull(int ty , int now , int l , int r){
    sum[ty][now] = sum[ty][ls] + sum[ty][rs];
}
void modify(int ty , int now , int l , int r , int ql , int qr , int val){
    Push(ty , now , l , r);
    if(ql <= l && r <= qr){
        sum[ty][now] = (r - l + 1) * val;
        tag[ty][now] = val + 1;
        return ;
    }
    if(qr <= mid) modify(ty , ls , l , mid , ql , qr , val);
    else if(mid + 1 <= ql) modify(ty , rs , mid + 1 , r , ql , qr , val);
    else {
        modify(ty , ls , l , mid , ql , qr , val);
        modify(ty , rs , mid + 1 , r , ql , qr , val);
    }
    Pull(ty , now , l , r);
}
int query(int ty , int now , int l , int r , int ql , int qr){
    Push(ty , now , l , r);
    if(ql <= l && r <= qr) return sum[ty][now];
    else if(qr <= mid) return query(ty , ls , l , mid , ql , qr);
    else if(mid + 1 <= ql) return query(ty , rs , mid + 1 , r , ql , qr);
    return query(ty , ls , l , mid , ql , qr) + query(ty , rs , mid + 1 , r , ql , qr);
}
void getans(){
    REP(i , 26) REP(j , n)
        if(query(i , 1 , 0 , n - 1 , j , j) == 1) s[j] = 'a' + i;
}
int32_t main(){
    cin >> n >> m;
    cin >> s;
    REP(i , n) modify(s[i] - 'a' , 1 , 0 , n - 1 , i , i , 1);
    REP(times , m){
        int q , w , e;
        cin >> q >> w >> e;
        VI tmp;
        REP(i , 26){
            tmp.pb(query(i , 1 , 0 , n - 1 , q - 1 , w - 1));
            modify(i , 1 , 0 , n - 1 , q - 1 , w - 1 , 0);
        }
        if(e == 1){
            int from = q - 1;
            REP(k , 26){
                if(tmp[k] == 0) continue;
                int to = from + tmp[k] - 1;
                modify(k , 1 , 0 , n - 1 , from , to , 1);
                from = to + 1;
            }
            // assert(from == w);
        }
        if(e == 0){
            int from = q - 1;
            RREP(k , 25 , 0){
                if(tmp[k] == 0) continue;
                int to = from + tmp[k] - 1;
                modify(k , 1 , 0 , n - 1 , from , to , 1);
                from = to + 1;
            }
            assert(from == w);
        }
    }
    getans();
    cout << s << "\n" ;
    return 0;
}