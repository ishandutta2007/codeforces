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
const int OP_AND=1;
const int OP_OR=2;
const int OP_XOR=3;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
char s[SIZE];
int cul[1000][3];
int bits[5001][1000];
int pp[5001][2],op[5001];
char an1[1000],an2[1000];
map<string,int>ids;
int n,m;
int cal(int x,int v){
    int ret=0;
    bits[0][x]=v;
    REPP(i,1,n+1){
        if(!op[i])continue;
        if(op[i]==OP_AND){
            ret+=bits[i][x]=bits[pp[i][0]][x]&bits[pp[i][1]][x];
        }
        else if(op[i]==OP_OR){
            ret+=bits[i][x]=bits[pp[i][0]][x]|bits[pp[i][1]][x];
        }
        else if(op[i]==OP_XOR){
            ret+=bits[i][x]=bits[pp[i][0]][x]^bits[pp[i][1]][x];
        }
    }
    return ret;
}
int main(){
    RII(n,m);gets(s);
    REP(i,n){
        gets(s);
        int it=0;
        while(s[it]!=' ')it++;
        s[it]=0;
        ids[s]=i+1;
        it++;
        while(s[it]!=' ')it++;
        it++;
        if(s[it]=='1'||s[it]=='0'){
            REP(j,m){
                bits[i+1][j]=s[it+m-j-1]-'0';
            }
        }
        else{
            int it2=it;
            while(s[it2]!=' ')it2++;
            s[it2]=0;
            if(s[it]=='?')pp[i+1][0]=0;
            else pp[i+1][0]=ids[s+it];

            for(it=it2+1;s[it]!=' ';it++);
            s[it]=0;
            if(s[it2+1]=='X')op[i+1]=OP_XOR;
            else if(s[it2+1]=='A')op[i+1]=OP_AND;
            else op[i+1]=OP_OR;
            it++;
            if(s[it]=='?')pp[i+1][1]=0;
            else pp[i+1][1]=ids[s+it];
        }
    }
    REP(i,m){
        int v1=cal(i,0);
        int v2=cal(i,1);
        if(v1==v2)an1[i]=an2[i]='0';
        else if(v1<v2){
            an1[i]='0';
            an2[i]='1';
        }
        else{
            an1[i]='1';
            an2[i]='0';
        }
    }
    REP(i,m)printf("%c",an1[m-1-i]);
    puts("");
    REP(i,m)printf("%c",an2[m-1-i]);
    puts("");
    return 0;
}