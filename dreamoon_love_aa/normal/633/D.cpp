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
map<int,int>cnt;
set<PII>used;
int main(){
    VI input;
    DRI(n);
    REP(i,n){
        DRI(x);
        input.PB(x);
        cnt[x]++;
    }
    int an=2;
    REP(i,n)
        REP(j,n){
            if(i==j)continue;
            int x=input[i];
            int y=input[j];
            if(used.count(MP(x,y)))continue;
            cnt[x]--;cnt[y]--;
            deque<int>a;
            a.PB(x);a.PB(y);
            int len=2;
            while(1){
                int nxt=a[len-1]+a[len-2];
                if(cnt.count(nxt)&&cnt[nxt]>0){
                    a.PB(nxt);
                    cnt[nxt]--;
                    len++;
                    an=max(an,len);
                }
                else{
                    if(len>2&&!used.count(MP(a[1],a[2]))){
                        used.insert(MP(a[1],a[2]));
                        cnt[a[0]]++;
                        len--;
                        a.pop_front();
                    }
                    else break;
                }
            }
            while(len){
                len--;
                cnt[a[len]]++;
                a.pop_back();
            }
        }
    cout<<an<<endl;
    return 0;
}