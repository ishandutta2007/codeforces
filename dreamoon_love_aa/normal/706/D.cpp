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
const int SIZE = 1e7+10;
int nxt[SIZE][2],id,num[SIZE];
int get(int x,int v){return 1&(x>>v);}
int main(){
    DRI(Q);
    REP(tt,Q+1){
        char s[4];
        int x;
        if(tt){
            RS(s);
            RI(x);
        }
        else{
            s[0]='+';
            x=0;
        }
        if(s[0]=='+'){
            int now=0;
            for(int i=29;i>=0;i--){
                num[now]++;
                int nt=get(x,i);
                if(nxt[now][nt]){
                    now=nxt[now][nt];
                }
                else{
                    now=nxt[now][nt]=++id;
                }
            }
            num[now]++;
        }
        else if(s[0]=='-'){
            int now=0;
            for(int i=29;i>=0;i--){
                num[now]--;
                int nt=get(x,i);
                if(nxt[now][nt]){
                    now=nxt[now][nt];
                }
                else{
                    now=nxt[now][nt]=++id;
                }
            }
            num[now]--;
        }
        else{
            int now=0;
            int an=0;
            for(int i=29;i>=0;i--){
                int nt=get(x,i);
                if(nxt[now][1^nt]&&num[nxt[now][1^nt]]){
                    now=nxt[now][1^nt];
                    an|=1<<i;
                }
                else{
                    now=nxt[now][nt];
                }
            }
            printf("%d\n",an);
        }
    }
    return 0;
}