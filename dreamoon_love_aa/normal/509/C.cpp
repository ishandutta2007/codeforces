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
#define VPII vector<pair<int,int> >
#define PLL pair<long long,long long>
#define F first
#define S second
typedef long long LL;
using namespace std;
const int MOD = 1e9+7;
const int SIZE = 1e6+10;
int b[SIZE],len;
char s[SIZE],tmp[SIZE];
void print(){
    for(int i=len;i>=0;i--)putchar(s[i]);
    puts("");
}
bool check(int sum,int idx){
    for(int i=len;i>=idx;i--)sum-=tmp[i]-'0';
    if(sum<0)return 0;
    REP(i,idx){
        tmp[i]='0'+min(sum,9);
        sum-=min(sum,9);
    }
    return !sum;
}
void go(int sum){
    if(9*(len+1)<sum){
        len=0;
        while(sum>9){
            s[len++]='9';
            sum-=9;
        }
        s[len]=sum+'0';
        print();
        return;
    }
    strcpy(tmp,s);
    REP(i,len+1){
        for(char c=s[i]+1;c<='9';c++){
            tmp[i]=c;
            if(check(sum,i)){
                memcpy(s,tmp,len+1);
                print();
                return;
            }
        }
    }

    len++;
    memset(s,'0',len);
    s[len]='1';
    int now=0;
    sum--;
    while(sum>0){
        s[now]+=min(sum,9);
        sum-=min(sum,9);
        now++;
    }
    print();
}
int main(){
    DRI(n);
    REP(i,n){
        RI(b[i]);
    }
    while(b[0]>9){
        s[len++]='9';
        b[0]-=9;
    }
    s[len]=b[0]+'0';
    print();
    REPP(i,1,n){
        go(b[i]);
    }
    return 0;
}