#include <bits/stdc++.h>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define PII pair<int,int>
#define VI vector<int>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 2e5+10;

#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> set_t;
struct data{
    int x,r,f;
    data(int _x=0,int _r=0,int _f=0):x(_x),r(_r),f(_f){}
    bool operator<(const data& b)const{
        if(x!=b.x)return x<b.x;
        return f>b.f;
    }
}a[SIZE];
set_t s[10021];
int main(){
    DRII(n,K);
    REP(i,n){
        DRIII(x,r,f);f+=10;
        a[i]=data(x,r,f);
        a[i+n]=data(x+r,x,-f);
    }
    sort(a,a+2*n);
    LL an=0;
    REP(i,2*n){
        if(a[i].f>0){
            REPP(j,a[i].f-K,a[i].f+K+1){
                an+=SZ(s[j])-s[j].order_of_key(a[i].x-a[i].r);
            }
            s[a[i].f].insert(a[i].x);
        }
        else{
            s[-a[i].f].erase(a[i].r);
        }
    }
    cout<<an<<endl;
    return 0;
}
/* 
int main() {
    set_t s;
    for ( int i=0; i<5; i++ ) s.insert(10*i);
    assert(*s.find_by_order(0) == 0);
    assert(*s.find_by_order(3) == 30);
    assert(s.find_by_order(5) == s.end());
    assert(s.order_of_key(0) == 0);
    assert(s.order_of_key(30) == 3);
    assert(s.order_of_key(35) == 4);
    assert(s.order_of_key(100) == 5);
    return 0;
}
*/