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
#define VL vector<long long>
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long> >
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
bool gg[128];
bool match(char c,char c2){
    if(c==c2)return 1;
    if(c=='?')return gg[c2];
    if(c=='*')return !gg[c2];
    return 0;
}
int u[SIZE],tt;
void no(){puts("NO");}
void yes(){puts("YES");}
int main(){
    string good,pat,s;
    cin>>good;
    REP(i,SZ(good))gg[good[i]]=1;
    cin>>pat;
    int star=-1;
    REP(i,SZ(pat))
        if(pat[i]=='*')star=i;
    DRI(n);
    REP(i,n){
        cin>>s;
        if(star==-1){
            bool suc=1;
            if(SZ(pat)!=SZ(s)){
                no();
                continue;
            }
            REP(i,SZ(pat)){
                if(!match(pat[i],s[i]))suc=0;
            }
            if(suc)yes();
            else no();
        }
        else{
            bool suc=1;
            if(SZ(pat)-1>SZ(s)){
                no();
                continue;
            }
            tt++;
            REP(i,star){
                u[i]=tt;
                if(!match(pat[i],s[i]))suc=0;
            }
            REPP(i,star+1,SZ(pat)){
                u[SZ(s)-(SZ(pat)-i)]=tt;
                if(!match(pat[i],s[SZ(s)-(SZ(pat)-i)]))suc=0;
            }
            REP(i,SZ(s)){
                if(u[i]!=tt&&!match('*',s[i]))suc=0;
            }
            if(suc)yes();
            else no();
        }
    }
    return 0;
}