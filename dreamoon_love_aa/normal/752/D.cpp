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
VI score[SIZE];
string ss[SIZE];
map<string,int>id;
int CNT;
int ins(const string& s){
    if(id.count(s))return id[s];
    ss[CNT]=s;
    return id[s]=CNT++;
}
bool pal(const string& s){
    REP(i,SZ(s)){
        if(s[i]!=s[SZ(s)-1-i])return 0;
    }
    return 1;
}
int main(){
    DRII(N,K);
    REP(i,N){
        string s;
        cin>>s;
        DRI(v);
        int x=ins(s);
        score[x].PB(v);
    }
    int center=0;
    int an=0;
    REP(i,CNT){
        if(pal(ss[i])){
            sort(ALL(score[i]),greater<int>());
            int v2=0,v1=-1e9,now=0;
            REP(j,SZ(score[i])){
                now+=score[i][j];
                if(j%2==0)v1=max(v1,now);
                else v2=max(v2,now);
            }
            an+=v2;
            center=max(center,v1-v2);

        }
        else{
            reverse(ALL(ss[i]));
            int id2=-1;
            if(id.count(ss[i])){
                id2=id[ss[i]];
            }
            if(id2==-1||id2<i)continue;
            int v2=0,now=0;
            sort(ALL(score[i]),greater<int>());
            sort(ALL(score[id2]),greater<int>());
            REP(j,min(SZ(score[i]),SZ(score[id2]))){
                now+=score[i][j]+score[id2][j];
                v2=max(v2,now);
            }
            an+=v2;
        }
    }
    printf("%d\n",an+max(0,center));
    return 0;
}