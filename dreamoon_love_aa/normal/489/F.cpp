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
int MOD = 1e9+7;
const int SIZE = 1e6+10;
void ADD(LL &x,LL v){
    x=(x+v)%MOD;
}
int cnt[SIZE];
int main(){
    DRIII(n,m,mod);
    MOD=mod;
    REP(i,m){
        string s;
        cin>>s;
        REP(j,n)
            if(s[j]=='1')cnt[j]++;
    }
    int two=0,one=0;
    REP(i,n){
        if(cnt[i]>2)return 0*puts("0");
        if(cnt[i]==1)one++;
        if(cnt[i]==0)two++;
    }
    map<PII,LL>H[2];
    int now=0,nxt=1;
    H[now][MP(one,two)]=1;
    REPP(i,m,n){
        H[nxt].clear();
        for(map<PII,LL>::iterator it=H[now].begin();it!=H[now].end();it++){
            if(it->F.F>=2)ADD(H[nxt][MP(it->F.F-2,it->F.S)],it->S*it->F.F*(it->F.F-1)/2);
            if(it->F.F>=1&&it->F.S>=1)ADD(H[nxt][MP(it->F.F,it->F.S-1)],it->S*it->F.F*it->F.S);
            if(it->F.S>=2)ADD(H[nxt][MP(it->F.F+2,it->F.S-2)],it->S*it->F.S*(it->F.S-1)/2);
        }
        swap(now,nxt);
    }
    cout<<H[now][MP(0,0)];
    return 0;
}