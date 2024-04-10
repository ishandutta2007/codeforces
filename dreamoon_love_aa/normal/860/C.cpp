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
const int SIZE = 1e5+10;
bool is_digit(char c){
    return c>='0'&&c<='9';
}
vector<string> other[2];
int from[SIZE];
VI can_use[2];
VI need_move_from[2];
int ex_n;
vector<pair<string,int> >an;
bool stop(){
    return SZ(other[0])==0
        && SZ(other[1])==0
        && SZ(need_move_from[0])==0
        && SZ(need_move_from[1])==0;
}
/*
string to_string(int x){
    char tmp[9];
    sprintf(tmp,"%d",x);
    return tmp;
}
*/
int main(){
    DRI(n);
    MS1(from);
    REP(i,n){
        char s[9],s2[9];
        RS(s);DRI(ty);
        if(ty)ex_n++;
        int v=0;
        if(is_digit(s[0])){
            sprintf(s2,"%d",atoi(s));
            if(strcmp(s2,s)==0)v=atoi(s);
        }
        if(v>0&&v<=n){
            from[v]=ty;
        }
        else{
            other[ty].PB(s);
        }
    }
    REPP(i,1,ex_n+1){
        if(from[i]==-1){
            can_use[1].PB(i);
        }
        else if(from[i]!=1){
            need_move_from[0].PB(i);
        }
    }
    REPP(i,ex_n+1,n+1){
        if(from[i]==-1){
            can_use[0].PB(i);
        }
        else if(from[i]){
            need_move_from[1].PB(i);
        }
    }
    while(!stop()){
        if(!SZ(can_use[0])&&!SZ(can_use[1])){
            an.PB(MP(to_string(need_move_from[0][0]),0));
            REP(i,SZ(need_move_from[1])){
                an.PB(MP(to_string(need_move_from[1][i]),need_move_from[0][i]));
                if(i+1<SZ(need_move_from[1])){
                    an.PB(MP(to_string(need_move_from[0][i+1]),need_move_from[1][i]));
                }
                else{
                    an.PB(MP("0",need_move_from[1][i]));
                }
            }
            break;
        }
        REP(i,2){
            if(SZ(can_use[i])){
                if(SZ(need_move_from[i])){
                    an.PB(MP(to_string(need_move_from[i].back()),can_use[i].back()));
                    can_use[1-i].PB(need_move_from[i].back());
                    need_move_from[i].pop_back();
                    can_use[i].pop_back();
                }
                else{
                    an.PB(MP(other[i].back(),can_use[i].back()));
                    other[i].pop_back();
                    can_use[i].pop_back();
                }
            }
        }
    }
    printf("%d\n",SZ(an));
    REP(i,SZ(an)){
        printf("move %s %d\n",an[i].F.c_str(),an[i].S);
    }
    return 0;
}