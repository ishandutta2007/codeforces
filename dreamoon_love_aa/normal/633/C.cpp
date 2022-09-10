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
string word[100000];
int nxt[1500000][26],wid[1500000],ID;
void add(string& str,int x){
    int now=0;
    REP(i,SZ(str)){
        int me=(str[i]>='a'&&str[i]<='z')?(str[i]-'a'):(str[i]-'A');
        if(!nxt[now][me])nxt[now][me]=++ID;
        now=nxt[now][me];
    }
    wid[now]=x;
}
int dp[11111];
int main(){
    MS1(wid);
    DRI(n);
    RS(s);
    DRI(m);
    REP(i,m){
        cin>>word[i];
        add(word[i],i);
    }
    REP(i,n)s[i]-='a';
    MS1(dp);
    dp[n]=0;
    for(int i=n-1;i>=0;i--){
        if(dp[i+1]==-1)continue;
        int now=0;
        for(int j=i;j>=0;j--){
            if(!nxt[now][s[j]])break;
            now=nxt[now][s[j]];
            if(wid[now]!=-1){
                dp[j]=wid[now];
            }
        }
    }
    {
        int now=0;
        while(now!=n){
            if(now)printf(" ");
            cout<<word[dp[now]];
            now+=SZ(word[dp[now]]);
        }
        puts("");
    }
    return 0;
}