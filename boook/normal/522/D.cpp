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
#define MAX 500900
#define INF 0x3f3f3f3f
#define mid ((l + r) >> 1)

int n , m , x[MAX] , root[MAX];
map<int , int> cc;
int b[MAX * 40] , ls[MAX * 40] , rs[MAX * 40] , po = 2;

void Build(int now , int l , int r){
    if(l == r) { b[now] = INF; }
    else {
        b[now] = INF;
        if(ls[now] == 0) ls[now] = po ++;
        if(rs[now] == 0) rs[now] = po ++;
        Build(ls[now] , l , mid);
        Build(rs[now] , mid + 1 , r);
    }
}
int query(int now , int l , int r , int ql , int qr){
    // DB4("" , "query" , a , b);
    // DBGG("query = " , now);
    if(ql <= l && r <= qr) return b[now];
    else if(qr <= mid) return query(ls[now] , l , mid , ql , qr);
    else if(mid + 1 <= ql) return query(rs[now] , mid + 1 , r , ql , qr);
    int a = query(ls[now] , l , mid , ql , qr);
    int b = query(rs[now] , mid + 1 , r , ql , qr);
    return min(a , b);
}
int update(int now , int l , int r , int pos , int val){
    int dot = po ++;
    ls[dot] = ls[now] , rs[dot] = rs[now];
    if(l == pos && r == pos){
        b[dot] = val;
        return dot;
    }
    else if(pos <= mid) {
        ls[dot] = update(ls[now] , l , mid , pos , val);
        b[dot] = min(b[ls[dot]] , b[rs[dot]]);
        return dot;
    }
    else {
        rs[dot] = update(rs[now] , mid + 1 , r , pos , val);
        b[dot] = min(b[ls[dot]] , b[rs[dot]]);
        return dot;
    }
}
int32_t main(){
    IOS;
    cin >> n >> m;
    REP(i , 1 , n + 1) cin >> x[i];

    Build(1 , 1 , n);
    root[0] = 1;
    REP(i , 1 , n + 1){
        if(cc.find(x[i]) == cc.end()) cc[x[i]] = i , root[i] = root[i - 1];
        else {
            int pos = cc[x[i]] , val = i - cc[x[i]];
            cc[x[i]] = i;
            root[i] = update(root[i - 1] , 1 , n , pos , val);
        }
    }
    REP(i , 1 , m + 1){
        int l , r;
        cin >> l >> r;
        int ans = query(root[r] , 1 , n , l , r);
        cout << ((ans == INF) ? -1 : ans) << endl;
    }
    return 0;
}