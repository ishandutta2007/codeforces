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
// template end here
struct Frac{
    LL pp,qq;
    Frac(LL _pp=0,LL _qq=1):pp(_pp),qq(_qq){
        if(!qq)fprintf(stderr,"err!\n");
        if(qq<0){
            qq=-qq;
            pp=-pp;
        }
        if(!pp)qq=1;
        else{
            LL gg=__gcd(abs(pp),qq);
            pp/=gg;
            qq/=gg;
        }
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
};
set<pair<Frac,int> >H;
bool zero[SIZE];
int cnt[SIZE];
vector<int>e[SIZE];
vector<int>an;
void ff(){
    an.clear();
    for(set<pair<Frac,int> >::iterator it=H.begin();it!=H.end();it++){
        an.PB(it->S);
    }
}
void print_array(vector<int>&arr){
    REP(i,SZ(arr)){
        if(i)printf(" ");
        printf("%d",arr[i]);
    }
    puts("");
}
int main(){
    DRIII(n,m,k);
    REP(i,k){
        DRI(x);
        zero[x]=1;
    }
    REP(i,m){
        DRII(x,y);
        e[x].PB(y);
        if(!zero[y])cnt[x]++;
        e[y].PB(x);
        if(!zero[x])cnt[y]++;
    }
    REPP(i,1,n+1){
        if(!zero[i]){
            H.insert(MP(Frac(cnt[i],SZ(e[i])),i));
        }
    }
    Frac ma=H.begin()->F;
    ff();
    while(SZ(H)){
        int me=H.begin()->S;
        H.erase(H.begin());
        REP(i,SZ(e[me])){
            int y=e[me][i];
            if(!zero[y]){
                H.erase(MP(Frac(cnt[y],SZ(e[y])),y));
                cnt[y]--;
                H.insert(MP(Frac(cnt[y],SZ(e[y])),y));
            }
        }
        zero[me]=1;
        if(SZ(H)&&ma<H.begin()->F){
            ma=H.begin()->F;
            ff();
        }
    }
    printf("%d\n",SZ(an));
    print_array(an);
    return 0;
}