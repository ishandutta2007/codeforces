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
#define MAX 5010
#define INF 0x3f3f3f3f

string s;
int k , x[MAX][MAX];
int val[MAX * MAX];
int b[MAX * MAX];
int ls[MAX * MAX] , rs[MAX * MAX] , po = 3;
void Build(int now , int from , int idx){
    if(x[from][idx] == 1) b[now] ++;
    if(idx + 1 < s.size()){
        if(s[idx + 1] == 'a'){
            if(ls[now] == 0) ls[now] = po++;
            Build(ls[now] , from , idx + 1);
        }
        if(s[idx + 1] == 'b'){
            if(rs[now] == 0) rs[now] = po++;
            Build(rs[now] , from , idx + 1);
        }
    }
    val[now] = b[now];
    if(ls[now]) val[now] += val[ls[now]];
    if(rs[now]) val[now] += val[rs[now]];
}
void P(int now , int k){
    k -= b[now];
    if(k <= 0) return;
    if(ls[now] == 0) {cout << "b" ; P(rs[now] , k); return ; }
    if(rs[now] == 0) {cout << "a" ; P(ls[now] , k); return ; }
    if(val[ls[now]] >= k) {cout << "a" ; P(ls[now] , k); return ; }
    else {cout << "b" ; P(rs[now] , k - val[ls[now]]); return ; }  
}
int32_t main(){
    IOS;
    cin >> s >> k;
    int siz = s.size();
    REP(i , 0 , s.size()){
        int a = i , b = i;
        while(a >= 0 && b < s.size() && s[a] == s[b])
            x[a][b] = 1 , a -= 2 , b += 2;
    }
    REP(i , 0 , s.size()){
        int a = i - 1 , b = i + 1;
        while(a >= 0 && b < s.size() && s[a] == s[b])
            x[a][b] = 1 , a -= 2 , b += 2;
    }
    REP(i , 0 , s.size() - 1){
        int a = i , b = i + 1;
        while(a >= 0 && b < s.size() && s[a] == s[b])
            x[a][b] = 1 , a -= 2 , b += 2;
    }
    REP(i , 0 , s.size() - 1){
        int a = i - 1 , b = i + 1 + 1;
        while(a >= 0 && b < s.size() && s[a] == s[b])
            x[a][b] = 1 , a -= 2 , b += 2;
    }

    ls[0] = 1 , rs[0] = 2;
    // REP(i , 0 , 1){
    REP(i , 0 , s.size()){
        if(s[i] == 'a') Build(1 , i , i);
        if(s[i] == 'b') Build(2 , i , i);
    }
    b[0] = 0 , val[0] = val[1] + val[2];
    // if(s.size() > 100) cout << val[0] << endl;
    P(0 , k) , cout << endl;
    return 0;
}