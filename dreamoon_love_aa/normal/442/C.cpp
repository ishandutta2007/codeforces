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
#define F first
#define S second
typedef long long LL;
const int SIZE = 5e5+5;
using namespace std;
vector<pair<int,int> >v;
set<pair<int,int> >H;
bool used[SIZE];
int b[SIZE];
int main(){
    DRI(n);
    REP(i,n){
        DRI(x);
        v.PB(MP(x,i));
        H.insert(MP(i,x));
    }
    LL an=0;
    sort(ALL(v));
    REP(i,SZ(v)){
        if(v[i].S==0||v[i].S==n-1)continue;
        set<pair<int,int> >::iterator it=H.lower_bound(MP(v[i].S,0));
        set<pair<int,int> >::iterator it2=it;
        int now=it->S;
        it2--;
        int tmp=it2->S;
        it2++;
        it2++;
        tmp=min(it2->S,tmp);
        if(now<=tmp){
            used[i]=1;
            an+=tmp;
            H.erase(it);
        }
    }
    int bn=0;
    for(set<pair<int,int> >::iterator it=H.begin();it!=H.end();it++){
        b[bn++]=it->S;
    }
    if(bn>2){
        sort(b,b+bn);
        for(int i=0;i+2<bn;i++)an+=b[i];
    }
    cout<<an<<endl;
    return 0;
}