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
#define endl "\n"
///------------------------------------------------------------
#define MAX 100900
#define INF 0x3f3f3f3f
#define N 333

int n , m , x[MAX];
int cnt[N][MAX];
queue<int> qu[N];
void update(int l , int r){
    int lid = l / N , lto = l % N;
    int rid = r / N , rto = r % N;
    queue<int> ql , qr;

    RREP(i , N - 1 , rto + 1) qr.push(qu[rid].front()) , qu[rid].pop();
        
    int val = qu[rid].front(); qu[rid].pop();
    cnt[rid][val] --;
    cnt[lid][val] ++;

    while(qu[rid].size()) qr.push(qu[rid].front()) , qu[rid].pop();
    qu[rid] = qr;

    RREP(i , rid - 1 , lid){
        cnt[i + 1][qu[i].front()] ++;
        cnt[i + 0][qu[i].front()] --;
        qu[i + 1].push(qu[i].front());
        qu[i + 0].pop();
    }
    RREP(i , N - 2 , lto) ql.push(qu[lid].front()) , qu[lid].pop();
    ql.push(val);
    while(qu[lid].size()) ql.push(qu[lid].front()) , qu[lid].pop();
    qu[lid] = ql;

}
int solve(int l , int r , int k){
    int id = l / N , lid = l % N , rid = r % N , ans = 0;
    queue<int> tmp;
    RREP(i , N - 1 , 0){
        int now = qu[id].front(); qu[id].pop();
        if(lid <= i && i <= rid && now == k) ans ++;
        tmp.push(now);
    }
    qu[id] = tmp;
    return ans;
}
int query(int l , int r , int k){
    int ans = 0;
    while(l <= r){
        if(l % N == 0 && l + N - 1 <= r){
            ans += cnt[l / N][k] , l += N;
        }
        else {
            if(l / N == r / N) ans += solve(l , r , k) , l = r + 1;
            else {
                ans += solve(l , ((l / N) + 1) * N - 1 , k);
                l = ((l / N) + 1) * N;
            }
        }
    }
    return ans;
}
inline int rit(){
    char c = getchar();
    int res = 0;
    while(!isdigit(c)) c = getchar();
    while(isdigit(c)) res = (res << 1) + (res << 3) + c - '0' , c = getchar();
    return res;
}
int32_t main(){
    n = rit();
    REP(i , 1 , n + 1) x[i] = rit();

    RREP(i , n + N , 0){
        qu[i / N].push(x[i]);
        cnt[i / N][x[i]] ++;
    }

    m = rit();
    int ty , l , r , k , lasans = 0;
    REP(i , 1 , m + 1){
        ty = rit();
        if(ty == 1){
            l = rit() , r = rit();
            l = (l + lasans - 1) % n + 1;
            r = (r + lasans - 1) % n + 1;
            if(l > r) swap(l , r);
            update(l , r);
        }
        else {
            l = rit() , r = rit() , k = rit();
            l = (l + lasans - 1) % n + 1;
            r = (r + lasans - 1) % n + 1;
            k = (k + lasans - 1) % n + 1;
            if(l > r) swap(l , r);
            lasans = query(l , r , k);
            printf("%d\n", lasans);
        }
    }
    return 0;
}