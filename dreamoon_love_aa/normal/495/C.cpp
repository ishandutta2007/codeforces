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
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
char s[SIZE];
int main(){
    RS(s);
    int n=LEN(s);
    int L=0,R=0,now=0,cnt=0;
    REP(i,n){
        if(s[i]=='(')L++,now++;
        else{
            R++,now--;
            if(s[i]=='#')cnt++;
        }
        if(now<0){
            puts("-1");
            return 0;
        }
    }
    if(s[n-1]=='('){
        puts("-1");
        return 0;
    }
    if(R>L){
        puts("-1");
    }
    else{
        vector<int>an;
        int ha=0;
        REP(i,n){
            if(s[i]=='(')ha++;
            else if(s[i]=='#'){
                if(cnt!=1)an.PB(1),cnt--;
                else an.PB(L-R+1);
                ha-=an.back();
            }
            else ha--;
            if(ha<0){
                puts("-1");
                return 0;
            }
        }
        REP(i,SZ(an))printf("%d\n",an[i]);
    }
    return 0;
}