#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<queue>
#define SZ(X) ((int)(X).size())
#define ALL(X) (X).begin(), (X).end()
#define REP(I, N) for (int I = 0; I < (N); ++I)
#define REPP(I, A, B) for (int I = (A); I < (B); ++I)
#define REPC(I, C) for (int I = 0; !(C); ++I)
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
using namespace std;
char s[50010];
int now[26],last[50010][26],r[50010][51],dp[51],ker[51],sp[51];
void dfs(int id,int lv,vector<char>&res){
    res.PB(s[id]);
    if(lv==1)return;
    dfs(r[id][lv],lv-1,res);
}
void print(int id,int lv,bool flag){
    vector<char>res;
    dfs(id,lv,res);
    for(int i=SZ(res)-1;i>=0;i--)printf("%c",res[i]);
    if(flag)printf("%c",s[id+1]);
    for(int i=0;i<SZ(res);i++)printf("%c",res[i]);
    puts("");
}
int main(){
    RS(s+1);
    int n=strlen(s+1);
    if(n==1){
        puts(s+1);
        return 0;
    }
    REPP(i,1,n+1){
        now[s[i]-'a']=i;
        REP(j,26)last[i][j]=now[j];
    }
    int ma=0;
    REPP(i,1,n+1){
        for(int j=ma;j>0;j--){
            if(last[dp[j]-1][s[i]-'a']>i){
                if(j==ma||dp[j+1]<last[dp[j]-1][s[i]-'a']){
                    r[i][j+1]=ker[j];
                    ker[j+1]=i;
                    dp[j+1]=last[dp[j]-1][s[i]-'a'];
                    ma=max(ma,j+1);
                    if(i+1<dp[j+1]){
                        sp[j+1]=i;
                    }
                }
            }
        }
        if(last[n][s[i]-'a']>i){
            if(ma==0||dp[1]<last[n][s[i]-'a']){
                ker[1]=i;
                dp[1]=last[n][s[i]-'a'];
                ma=max(ma,1);
                if(i+1<dp[1]){
                    sp[1]=i;
                }
            }
        }
        if(ma==50){
            print(i,ma,0);
            return 0;
        }
    }
    if(!ma){
        printf("%c\n",s[1]);
        return 0;
    }
    if(sp[ma])print(sp[ma],ma,1);
    else print(ker[ma],ma,0);
    return 0;
}