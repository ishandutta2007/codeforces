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
string sz[6]={"S","M","L","XL","XXL","XXXL"};
int d[6],an[SIZE];
VI p[5];
int main(){
    REP(i,6)RI(d[i]);
    DRI(n);
    REP(i,n){
        string s;
        cin>>s;
        bool done=0;
        REP(j,6){
            if(s==sz[j]){
                an[i]=j;
                d[j]--;
                if(d[j]<0)return 0*puts("NO");
                done=1;
                break;
            }
        }
        if(!done){
            REP(j,6){
                if(s.substr(0,SZ(sz[j]))==sz[j]){
                    p[j].PB(i);
                    break;
                }
            }
        }
    }
    REP(i,5){
        REP(j,SZ(p[i])){
            if(d[i]==0&&d[i+1]==0)return 0*puts("NO");
            if(d[i]){
                d[i]--;
                an[p[i][j]]=i;
            }
            else{
                d[i+1]--;
                an[p[i][j]]=i+1;
            }
        }
    }
    puts("YES");
    REP(i,n)cout<<sz[an[i]]<<endl;
    return 0;
}