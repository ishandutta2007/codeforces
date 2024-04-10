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
int an[SIZE];
void print_array(int arr[],int n){
    REP(i,n){
        if(i)printf(" ");
        printf("%d",arr[i]);
    }
    puts("");
}
struct data{
    int x,dir,id;
    data(int _x=0,int _dir=0,int _id=0):x(_x),dir(_dir),id(_id){}
    bool operator<(const data& b)const{return x<b.x;}
}a[SIZE];
int b[SIZE];
int main(){
    DRII(n,m);
    LL t;
    cin>>t;
    REP(i,n){
        RI(a[i].x);
        a[i].x%=m;
        a[i].id=i;
        char s[4];
        RS(s);
        if(s[0]=='R')a[i].dir=1;
        else a[i].dir=-1;
    }
    sort(a,a+n);
    bool dif=0;
    REPP(i,1,n){
        if(a[i].dir!=a[i-1].dir)dif=1;
    }
    if(!dif){
        if(a[0].dir==1){
            REP(i,n)an[a[i].id]=(a[i].x+t)%m;
        }
        else{
            REP(i,n)an[a[i].id]=((a[i].x-t)%m+m)%m;
        }
    }
    else{
        int st=0;
        while(a[st].dir==-1)st++;
        int neg=0,lst_neg=0;
        REP(i,n){
            if(a[i].dir==-1){
                neg+=2;
                if((a[i].x-a[st].x+m)%m<t%m*2)lst_neg++;
                if((a[i].x-a[st].x+m)%m+m<t%m*2)lst_neg++;
            }
        }
        int ch=(neg*(t/m)+lst_neg)%n;
        REP(i,n){
            if(a[i].dir==1)b[i]=(a[i].x+t)%m;
            else b[i]=((a[i].x-t)%m+m)%m;
        }
        sort(b,b+n);
        int st_new_pos=(a[st].x+t)%m;
        int new_st=0;
        while(b[new_st]<st_new_pos)new_st++;
        REP(i,n)
            an[a[(st+i+ch)%n].id]=b[(new_st+i)%n];
    }
    REP(i,n)
        if(an[i]==0)an[i]=m;
    print_array(an,n);
    return 0;
}