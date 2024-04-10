/*input
1
abacaba
4
4 a
1 a
1 c
2 b
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
#define IOS cin.tie(0) , cout.sync_with_stdio(0)
#define endl "\n"
///------------------------------------------------------------
#define MAX 300000
#define INF 0x3f3f3f3f

struct N{
    int val , pri , siz;
    N *l , *r;
    N(int _val){
        val = _val , pri = rand() , siz = 1;
        l = r = NULL;
    }
};
int SIZ(N *now){ return now ? now->siz : 0; }
void Pull(N *now){ now->siz = 1 + SIZ(now->l) + SIZ(now->r); }
N *Merge(N *a , N *b){
    if(!a || !b) return a ? a : b;
    if(a->pri > b->pri)
         return a->r = Merge(a->r , b) , Pull(a) , a;
    else return b->l = Merge(a , b->l) , Pull(b) , b;
}
void Split(N *t , int k , N *&a , N *&b){
    if(!t) return a = b = NULL , void();
    if(SIZ(t->l) + 1 <= k)
         a = t , Split(t->r , k - 1 - SIZ(t->l) , a->r , b);
    else b = t , Split(t->l , k , a , b->l);
    Pull(t);
}
int k , m , pos = 1 , ans[MAX];
N *root[30];
string s;
void Print(N *now , int id){
    if(now){
        ans[now->val] = id;
        Print(now->l , id);
        Print(now->r , id);
    }
}
N *aaa = NULL;
void put(N *now){
    if(!now) return ;
    put(now->l);
    cout << now->val << " ";
    put(now->r);
}
int32_t main(){
    IOS;
    cin >> k >> s;
    REP(i , 0 , k) REP(j , 0 , s.size())
        root[s[j] - 'a'] = Merge(root[s[j] - 'a'] , new N(pos++));
    cin >> m;
    REP(i , 0 , m){
        cin >> k >> s;
        N *left , *right , *mid , *tmp;
        int now = s[0] - 'a';
        Split(root[now] , k , tmp , right);
        Split(tmp , k - 1 , left , mid);
        root[now] = Merge(left , right);
    }
    REP(i , 0 , MAX) ans[i] = -1;
    REP(i , 0 , 26) Print(root[i] , i);
    string p;
    REP(i , 0 , MAX) if(ans[i] != -1) p += 'a' + ans[i];
    cout << p << endl;
    return 0;
}