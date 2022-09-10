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

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    DRI(n);
    DRII(x,a);
    DRII(b,c);
    pair<int,string>team[64];
    REP(i,n){
        cin>>team[i].S>>team[i].F;
    }
    sort(team,team+n);
    reverse(team,team+n);
    set<pair<int,string>,greater<pair<int,string> > >H[4];
    REP(i,n){
        H[i/(n/4)].insert(team[i]);
    }
    REP(i,n/4){
        printf("Group %c:\n",'A'+i);
        REP(j,4){
            int y=(a*x+b)%c;
            x=y;
            int id=x%SZ(H[j]);
            set<pair<int,string>,greater<pair<int,string> > >::iterator it=H[j].begin();
            for(;id;id--)it++;
            cout<<it->S<<endl;
            H[j].erase(it);
        }
    }
    return 0;
}