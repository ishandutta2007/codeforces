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
#define MAX 100900 
#define INF 0x3f3f3f3f
#define AC 514
#define mod 1000000009LL
#define mid ((l + r) >> 1)
#define ls (now << 1)
#define rs (now << 1 | 1)

int n , m , k;
string s;
int h[MAX] , chval[MAX][10] , tag[MAX * 4];
PII b[MAX * 4];
void pre(){
    h[0] = 1;
    REP(i , 1 , MAX){
        h[i] = h[i - 1] * AC % mod;
        REP(j , 0 , 10)
            chval[i][j] = (chval[i - 1][j] * AC + (j + '0')) % mod;
    }
}
void Push(int now , int l , int r){
    if(l == r || tag[now] == -1) return ;
    else {
        b[ls].A = chval[b[ls].B][tag[now]];
        b[rs].A = chval[b[rs].B][tag[now]];
        tag[ls] = tag[rs] = tag[now];
        tag[now] = -1;
    }
}
PII Pull(PII a , PII b){
    int tmp = (a.A * h[b.B] % mod + b.A) % mod;
    return mp(tmp , a.B + b.B);
}
void Build(int now , int l , int r){
    if(l == r){ b[now] = mp((int)(s[l]) , 1LL) , tag[now] = -1; }
    else {
        Build(ls , l , mid);
        Build(rs , mid + 1 , r);
        b[now] = Pull(b[ls] , b[rs]) , tag[now] = -1; 
    }
}
void modify(int now , int l , int r , int ql ,int qr , int k){
    Push(now , l , r);
    if(ql <= l && r <= qr){
        tag[now] = k;
        b[now].A = chval[b[now].B][k];
        return;
    }
    if(qr <= mid) modify(ls , l , mid , ql , qr , k);
    else if(mid + 1 <= ql) modify(rs , mid + 1 , r , ql , qr , k);
    else {
        modify(ls , l , mid , ql , qr , k);
        modify(rs , mid + 1 , r , ql , qr , k);
    }
    b[now] = Pull(b[ls] , b[rs]);
}
PII query(int now , int l , int r , int ql , int qr){
    Push(now , l , r);
    if(ql <= l && r <= qr) return b[now];
    if(qr <= mid) return query(ls , l , mid , ql , qr);
    if(mid + 1 <= ql) return query(rs , mid + 1 , r , ql , qr);
    PII a = query(ls , l , mid , ql , qr);
    PII b = query(rs , mid + 1 , r , ql , qr);
    return Pull(a , b);
}
int32_t main(){
    cin >> n >> m >> k;
    cin >> s;
    pre() , Build(1 , 0 , s.size() - 1);
    REP(i , 0 , m + k){
        int q , w , e , r;
        cin >> q >> w >> e >> r;
        if(q == 1){
            modify(1 , 0 , s.size() - 1 , w - 1 , e - 1 , r);
        }
        else if(q == 2 && (r == 0 || w == e || e - w + 1 == r)) cout << "YES" << endl; 
        else if(q == 2){
            PII a = query(1 , 0 , s.size() - 1 , w - 1 , e - r - 1);
            PII b = query(1 , 0 , s.size() - 1 , w + r - 1 , e - 1);
            // DB4(w - 1 , e - r - 1, w + r - 1 , e - 1);
            // DB4("val is = " , "" , a.A , b.A);
            cout << ((a == b) ? "YES" : "NO") << endl;
        }
    }
    return 0;
}