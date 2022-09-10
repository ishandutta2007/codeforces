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
char s[SIZE];
int n,cnt[26];
int BIT[SIZE];
void ins(int x){
    for(;x<SIZE;x+=x&-x)BIT[x]++;
}
int qq(int x){
    int res=0;
    for(;x;x-=x&-x)res+=BIT[x];
    return res;
}
void solve(int cc,int n,int m){
    int lt=-1;
    int now=-1;
    int v=0;
    REP(i,n){
        if(s[i]<'a'+cc)lt=i;
        if(s[i]=='a'+cc)now=i;
        if(i-lt==m){
            lt=now;
            v++;
        }
    }
    REP(i,cc){
        REP(j,cnt[i])printf("%c",'a'+i);
    }
    REP(j,v)printf("%c",'a'+cc);
    puts("");
}
int main(){
    DRI(m);
    RS(s);
    n=LEN(s);
    REP(i,n)cnt[s[i]-'a']++;
    REP(i,26){
        int ma=0,now=0;
        REP(j,n){
            if(s[j]>'a'+i)now++;
            else now=0;
            ma=max(ma,now);
        }
        if(ma>=m)continue;
        solve(i,n,m);
        return 0;
    }
    return 0;
}