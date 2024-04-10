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
const int SIZE = 7e4+10;
map<string,int>all[10];
string an[SIZE];
int main(){
    DRI(n);
    REP(i,n){
        string s;
        cin>>s;
        set<string>me[10];
        REPP(j,1,10)REP(k,j){
            me[j-k].insert(s.substr(k,j-k));
        }
        REPP(j,1,10){
            for(auto it=me[j].begin();it!=me[j].end();it++){
                if(all[j].count(*it)){
                    all[j][*it]=-1;
                }
                else{
                    all[j][*it]=i;
                }
            }
        }
    }
    REPP(i,1,10){
        for(auto it=all[i].begin();it!=all[i].end();it++){
            if(it->S!=-1&&an[it->S]==""){
                an[it->S]=it->F;
            }
        }
    }
    REP(i,n)cout<<an[i]<<endl;
    return 0;
}