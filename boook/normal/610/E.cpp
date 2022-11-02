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
#define MAX 200900
#define INF 0x3f3f3f3f
#define mid ((l + r) >> 1)
#define ls (now << 1)
#define rs (now << 1 | 1)

int n , m , k;
string s;
int b[MAX * 4][11][11] , tag[MAX * 4];
void Pull(int now , int l , int r){
    REP(i , 0 , 10) REP(j , 0 , 10)
        b[now][i][j] = b[ls][i][j] + b[rs][i][j];
}
void Build(int now , int l , int r){
    tag[now] = -1;
    if(l == r){ b[now][s[l] - 'a'][s[l + 1] - 'a'] = 1;}
    else {
        Build(ls , l , mid);
        Build(rs , mid + 1 , r);
        Pull(now , l , r);
    }
}
void Push(int now , int l , int r){
    if(tag[now] != -1 && l != r){
        tag[ls] = tag[now];
        tag[rs] = tag[now];
        REP(i , 0 , 10) REP(j , 0 , 10)
            b[ls][i][j] = b[rs][i][j] = 0;
        b[ls][tag[now]][tag[now]] = mid - l + 1;
        b[rs][tag[now]][tag[now]] = r - (mid + 1) + 1;
        tag[now] = -1;
    }
}
void modify(int now , int l , int r , int ql , int qr , char v){
    Push(now , l , r);
    if(ql <= l && r <= qr){
        tag[now] = v - 'a';
        REP(i , 0 , 10) REP(j , 0 , 10) b[now][i][j] = 0;
        b[now][v - 'a'][v - 'a'] = r - l + 1;
    }
    else{
        if(qr <= mid) modify(ls , l , mid , ql , qr , v);
        else if(mid + 1 <= ql) modify(rs , mid + 1 , r , ql , qr , v);
        else {
            modify(ls , l , mid , ql , qr , v);
            modify(rs , mid + 1 , r , ql , qr , v);
        }
        Pull(now , l , r);
    }
}
void update(int now , int l , int r , int k , int fr , int ba){
    Push(now , l , r);
    if(l == k && r == k){
        int q , w;
        REP(i , 0 , 10) REP(j , 0 , 10)
            if(b[now][i][j]) q = i , w = j , b[now][i][j] = 0;
        if(fr == -1) w = ba - 'a';
        else q = fr - 'a';
        b[now][q][w] = 1;
    }
    else{
        if(k <= mid) update(ls , l , mid , k , fr , ba);
        else update(rs , mid + 1 , r , k , fr , ba);
        Pull(now , l , r);
    }
}
int32_t main(){
    IOS;
    cin >> n >> m >> k;
    cin >> s;
    if(n > 1) Build(1 , 0 , n - 2);

    REP(i , 1 , m + 1){
        int q , w , e;
        cin >> q;
        if(q == 1){
            cin >> q >> w >> s;
            q -- , w --;
            if(q != w) modify(1 , 0 , n - 2 , q , w - 1 , s[0]);
            if(q != 0) update(1 , 0 , n - 2 , q - 1 , -1 , s[0]);
            if(w != n - 1) update(1 , 0 , n - 2 , w , s[0] , -1);
        }
        else {
            cin >> s;

            int ans = 1;
            REP(i , 0 , s.size()) REP(j , 0 , i + 1)
                ans += b[1][s[i] - 'a'][s[j] - 'a'];
            cout << ans << endl;
        }
    }
    return 0;
}