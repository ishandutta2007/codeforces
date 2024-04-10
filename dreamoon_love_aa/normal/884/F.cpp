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
#define CASET int ___T; scanf("%d", &___T); for(int cs=1;cs<=___T;cs++)
#define MP make_pair
#define PB push_back
#define MS0(X) memset((X), 0, sizeof((X)))
#define MS1(X) memset((X), -1, sizeof((X)))
#define LEN(X) strlen(X)
#define PII pair<int,int>
#define VI vector<int>
#define VL vector<long long>
#define VPII vector<pair<int,int>>
#define PLL pair<long long,long long>
#define VPLL vector<pair<long long,long long>>
#define F first
#define S second
typedef int64_t LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
pair<char,char>cc[SIZE];
PII cc_cost[SIZE];
int ccn;
char s[SIZE];
int b[SIZE];
int main(){
    DRI(n);
    RS(s);
    int sum=0;
    REP(i,n){RI(b[i]);sum+=b[i];}
    int same[26]={};
    int same_num=0,same_ma=0;
    int an=0;
    char ma_char='0';
    REP(i,n/2){
        if(s[i]==s[n-i-1]){
            same_num++;
            same[s[i]-'a']++;
            an+=min(b[i],b[n-i-1]);
            same_ma=max(same_ma,same[s[i]-'a']);
            if(same[s[i]-'a']==same_ma)ma_char=s[i];
        }
        else{
            cc[ccn]=MP(s[i],s[n-i-1]);
            cc_cost[ccn++]=MP(b[i],b[n-i-1]);
        }
    }
    if(same_ma*2>same_num){
        int need=(same_ma*2-same_num);
        VI d;
        REP(i,ccn){
            int mi=111;
            if(cc[i].F==ma_char||cc[i].S==ma_char)continue;
            if(cc[i].F!=ma_char)mi=min(mi,cc_cost[i].F);
            if(cc[i].S!=ma_char)mi=min(mi,cc_cost[i].S);
            d.PB(mi);
        }
        sort(ALL(d));
        REP(i,need)an+=d[i];
    }
    printf("%d\n",sum-an);
    return 0;
}