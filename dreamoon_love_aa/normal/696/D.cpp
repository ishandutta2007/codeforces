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
int a[222],d[222][222];
LL dp[50][222][222],res[50][222][222];
template <class T>
void maa(T& x,T y){
    if(x<y)x=y;
}
template <class T>
void mii(T& x,T y){
    if(x>y)x=y;
}
int main(){
    string s;
    int n;
    LL l;
    cin>>n>>l;
    REP(i,n)
        RI(a[i]);
    map<string,int>score,NN,H;
    H[""]=0;
    REP(i,n){
        cin>>s;
        REPP(i,1,SZ(s)+1)H[s.substr(0,i)]=0;
        score[s]+=a[i];
    }
    int id=0;
    for(map<string,int>::iterator it=H.begin();it!=H.end();it++)
        it->S=id++;
    MS1(d);
    REP(i,id)d[i][i]=0;
    for(map<string,int>::iterator it=H.begin();it!=H.end();it++){
        string me=it->F;
        REP(i,26){
            char c='a'+i;
            string nxt=me+c;
            int id=0;
            int v=0;
            REP(j,SZ(nxt)){
                string you=nxt.substr(j);
                if(H.count(you)&&!id)id=H[you];
                v+=score[you];
            }
            maa(d[it->S][id],v);
        }
    }
    MS1(dp);
    REP(i,id)REP(j,id)dp[0][i][j]=d[i][j];
    MS1(res);
    REP(i,id)res[0][i][i]=0;
    int now=0;
    while(l){
        if(l&1){
            REP(i,id)REP(j,id)REP(k,id){
                if(dp[now][i][j]!=-1&&res[now][j][k]!=-1)
                    maa(res[now+1][i][k],dp[now][i][j]+res[now][j][k]);
            }
        }
        else REP(i,id)REP(j,id)res[now+1][i][j]=res[now][i][j];
        REP(i,id)REP(j,id)REP(k,id){
            if(dp[now][i][j]!=-1&&dp[now][j][k]!=-1)
                maa(dp[now+1][i][k],dp[now][i][j]+dp[now][j][k]);
        }
        l>>=1;
        now++;
    }
    LL an=0;
    REP(i,id)an=max(an,res[now][0][i]);
    cout<<an<<endl;
    return 0;
}