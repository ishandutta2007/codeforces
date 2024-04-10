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
const int SIZE = 1e3+5;
char s[SIZE];
bool valid(int idx,char c){
    if(idx-1>=0&&s[idx-1]==c)return false;
    if(idx-2>=0&&s[idx-2]==c)return false;
    return true;
}
int main(){
    DRII(n,p);
    RS(s);
    if(p==1){
        puts("NO");
    }
    else if(p==2){
        int n=LEN(s);
        if(n==1){
            if(strcmp(s,"b")<0)puts("b");
            else puts("NO");
        }
        else if(n==2){
            if(strcmp(s,"ba")<0)puts("ba");
            else puts("NO");
        }
        else puts("errr");
    }
    else{
        for(int i=n-1;i>=0;i--){
            int me=s[i]-'a';
            REPP(j,1,4){
                if(me+j<p&&valid(i,me+j+'a')){
                    s[i]=me+j+'a';
                    REPP(k,i+1,n){
                        REP(r,p){
                            if(valid(k,'a'+r)){
                                s[k]='a'+r;
                                break;
                            }
                        }
                    }
                    puts(s);
                    return 0;
                }
            }
        }
        puts("NO");
    }
    return 0;
}