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
struct Frac{
    LL pp,qq;
    Frac(LL _pp=0,LL _qq=1):pp(_pp),qq(_qq){
        if(!qq)fprintf(stderr,"err!\n");
        if(qq<0){
            qq=-qq;
            pp=-pp;
        }
        if(!pp)qq=1;
    }
    bool operator<(const Frac& b)const{
        return pp*b.qq<b.pp*qq;
    }
    bool operator==(const Frac& b)const{
        return pp==b.pp&&qq==b.qq;
    }
    Frac operator+(Frac b){
        LL gg=__gcd(qq,b.qq);
        LL x=pp*(b.qq/gg)+b.pp*(qq/gg);
        LL y=qq/gg*b.qq;
        return Frac(x,y);
    }
    Frac operator-(Frac b){
        b.pp=-b.pp;
        return *this+b;
    }
    Frac operator*(Frac b){
        LL gg1=__gcd(pp,b.qq);
        LL gg2=__gcd(b.pp,qq);
        return Frac(pp/gg1*(b.pp/gg2),qq/gg2*(b.qq/gg1));
    }
    Frac operator/(Frac b){
        swap(b.pp,b.qq);
        return *this*b;
    }
    void print(){
        cout<<pp<<"/"<<qq<<endl;
    }
}ma;
LL sum[SIZE];
int a[SIZE];
LL get(int x,int y){return sum[y]-sum[x-1];}
void print_array(vector<int>&arr){
    REP(i,SZ(arr)){
        if(i)printf(" ");
        printf("%d",arr[i]);
    }
    puts("");
}
int main(){
    DRI(n);
    REPP(i,1,n+1){
        RI(a[i]);
    }
    sort(a+1,a+n+1);
    REPP(i,1,n+1)sum[i]=sum[i-1]+a[i];
    int an_ty=1;
    PII an;

    REPP(i,2,n){
        int ll=1,rr=min(i-1,n-i);
        while(ll<rr){
            int mm1=(ll+rr)/2;
            int mm2=mm1+1;
            Frac v1=Frac(get(i-mm1,i)+get(n-mm1+1,n),mm1*2+1)-Frac(a[i],1);
            Frac v2=Frac(get(i-mm2,i)+get(n-mm2+1,n),mm2*2+1)-Frac(a[i],1);
            if(v2<v1)rr=mm1;
            else ll=mm2;
        }
        Frac v=Frac(get(i-ll,i)+get(n-ll+1,n),ll*2+1)-Frac(a[i],1);

        if(ma<v){
            an_ty=1;
            ma=v;
            an=MP(i,ll);
        }
    }

    REPP(i,2,n-1){
        int ll=1,rr=min(i-1,n-i-1);
        while(ll<rr){
            int mm1=(ll+rr)/2;
            int mm2=mm1+1;
            Frac v1=Frac(get(i-mm1,i+1)+get(n-mm1+1,n),mm1*2+2)-Frac(a[i]+a[i+1],2);
            Frac v2=Frac(get(i-mm2,i+1)+get(n-mm2+1,n),mm2*2+2)-Frac(a[i]+a[i+1],2);
            if(v2<v1)rr=mm1;
            else ll=mm2;
        }
        Frac v=Frac(get(i-ll,i)+get(n-ll+1,n),ll*2+1)-Frac(a[i],1);

        if(ma<v){
            an_ty=2;
            ma=v;
            an=MP(i,ll);
        }
    }

    if(ma==Frac(0,1))printf("1\n%d\n",a[1]);
    else{
        VI res;
        if(an_ty==1){
            REPP(i,an.F-an.S,an.F+1)res.PB(a[i]);
            REPP(i,n-an.S+1,n+1)res.PB(a[i]);
        }
        else{
            REPP(i,an.F-an.S,an.F+2)res.PB(a[i]);
            REPP(i,n-an.S+1,n+1)res.PB(a[i]);
        }
        printf("%d\n",SZ(res));
        print_array(res);
    }
    return 0;
}