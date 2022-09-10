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
const int SIZE = 1e6+10;
map<char,int>cc;
bool same(int c,int c2){
    if(c==-1||c2==-1)return 1;
    return c==c2;
}
int main(){
    cc['R']=0;
    cc['L']=1;
    cc['U']=2;
    cc['D']=3;
    DRI(n);
    string s;
    cin>>s;
    int h=-1,v=-1;
    int an=0;
    REP(i,n){
        int x=cc[s[i]];

        if(x&2){
            if(!same(v,x)){
                h=-1;
                an++;
            }
            v=x;
        }
        else{
            if(!same(h,x)){
                an++;
            v=-1;
            }
            h=x;
        }
    }
    an++;
    printf("%d\n",an);
    return 0;
}