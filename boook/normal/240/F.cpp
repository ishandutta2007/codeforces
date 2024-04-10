/*input
4 2
aabb
1 3
1 4
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
#define MAX 100090
#define INF 0x3f3f3f3f
#define ls (now << 1)
#define rs (now << 1 | 1)
#define mid ((l + r) >> 1)

struct Node{ int x[26]; } b[MAX * 4];
int n , m , tag[MAX * 4];
string s;
Node Pull(Node a , Node b){
    Node ans;
    REP(i , 0 , 26) ans.x[i] = a.x[i] + b.x[i];
    return ans;
}
void Build(int now , int l , int r){
    tag[now] = -1;
    if(l == r){
        REP(i , 0 , 26) b[now].x[i] = 0;
        b[now].x[s[l - 1] - 'a'] ++;
    }
    else {
        Build(ls , l , mid + 0);
        Build(rs , mid + 1 , r);
        b[now] = Pull(b[ls] , b[rs]);
    }
}
void Push(int now , int l , int r){
    if(l != r && tag[now] != -1){
        REP(i , 0 , 26) b[ls].x[i] = 0;
        REP(i , 0 , 26) b[rs].x[i] = 0;
        b[ls].x[tag[now]] = (mid + 0) - l + 1;
        b[rs].x[tag[now]] = r - (mid + 1) + 1;
        tag[ls] = tag[now];
        tag[rs] = tag[now];
        tag[now] = -1;
    }
}
void update(int now , int l , int r , int ql , int qr , int val){
    if(ql <= l && r <= qr){
        REP(i , 0 , 26) b[now].x[i] = 0;
        b[now].x[val] = r - l + 1;
        tag[now] = val;
    }
    else{
        Push(now , l , r);
        if(ql <= mid + 0) update(ls , l , mid + 0 , ql , qr , val);
        if(mid + 1 <= qr) update(rs , mid + 1 , r , ql , qr , val);
        b[now] = Pull(b[ls] , b[rs]);
    }
}
Node query(int now , int l , int r , int ql , int qr){
    Push(now , l , r);
    if(ql <= l && r <= qr) return b[now];
    if(qr <= mid + 0) return query(ls , l , mid + 0 , ql , qr);
    if(mid + 1 <= ql) return query(rs , mid + 1 , r , ql , qr);
    return Pull(query(ls , l , mid + 0 , ql , qr) , query(rs , mid + 1 , r , ql , qr));
}
int Print(int now , int l , int r){
    Push(now , l , r);
    if(l == r){
        REP(i , 0 , 26) if(b[now].x[i]) cout << (char)('a' + i);
    }
    else {
        Print(ls , l , mid + 0);
        Print(rs , mid + 1 , r);
    }
}
int32_t main(){
    freopen("input.txt" , "r" , stdin);
    freopen("output.txt" , "w" , stdout);
    IOS;
    cin >> n >> m >> s;
    Build(1 , 1 , n);
    // Print(1 , 1 , n); cout << endl;
    REP(times , 1 , m + 1){
        int ql , qr , one = 0 , id;
        cin >> ql >> qr;
        Node sum = query(1 , 1 , n , ql , qr);
        REP(i , 0 , 26) if(sum.x[i] % 2) one ++ , id = i;
        // cout << "get = ";
        // REP(i , 0 , 26) REP(j , 0 , sum.x[i]) cout << char('a' + i) << " ";
        // cout << endl;
        if(one > 1 || one != (qr - ql + 1) % 2) continue;
        if(one == 1){
            sum.x[id] --;
            update(1 , 1 , n , (ql + qr) / 2 , (ql + qr) / 2 , id);
        }
        int lpo = ql , rpo = qr;
        REP(i , 0 , 26){
            if(sum.x[i] == 0) continue;
            update(1 , 1 , n , lpo , lpo + sum.x[i] / 2 - 1 , i);
            lpo += sum.x[i] / 2;
            update(1 , 1 , n , rpo - sum.x[i] / 2 + 1 , rpo , i);
            rpo -= sum.x[i] / 2;
        }
    }
    Print(1 , 1 , n); cout << endl;
    return 0;
}