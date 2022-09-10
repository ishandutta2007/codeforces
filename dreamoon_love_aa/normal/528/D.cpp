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
const int SIZE = 1e6+10;
inline int pow(long long n,int k,int m){
    unsigned i;
    int a;
    for(a=i=1;i<=k;i*=2,n=(n*n)%m)
        if(k&i)a=(a*n)%m;
    return a;
}
inline int rev(int n,int k){
    int i=0;
    while(k--)(i<<=1)+=n&1,n/=2;
    return i;
}
const long long p=1107296257,r=10;
void ntt(bool f,int& n,int s[]){
    int i,j,k;
    long long x,w;
    for(j=1,k=0;j<n ;j<<=1,k++);
    for(;n<j;n++)s[n]=0;
    for(i=0;i<n;i++)
        if(i<rev(i,k))
            swap(s[i],s[rev(i,k)]);
    for(i=2;i<=n;i*=2){
        w=pow(pow(r,(p-1)/n,p),f?p-1-n/i:n/i,p);
        for(j=0;j<n;j+=i)
            for(k=0,x=1;k<i/2;k++){
                int &a=s[j+k],&b=s[j+k+i/2];
                b=(b*x)%p;
                a=(a*1ll+b)%p;
                b=(a+p+p-b-b)%p;
                x=x*w%p;
            }
    }
    x=pow(n,p-2,p);
    if(f)for(j=0;j<n;j++)
        s[j]=(s[j]*x)%p;
}
void mul(int n,int a[],int b[]){
    for(int i=0;i<n;i++)
        a[i]=(1ll*a[i]*b[i])%p;
}
void print(int n,int s[]){
    for(int i=0;i<n;i++)
        printf("%d ",s[i]);
    puts("");
}
int s[1000000],t[1000000];
char input[2][SIZE];
int ch(char c){
    if(c=='A')return 0;
    if(c=='C')return 1;
    if(c=='G')return 2;
    return 3;
}
int stop[SIZE];
int cover[SIZE];
int n1,n2;
int get(int L,int R){
    R=min(R,n1-1);
    if(L<=0)return cover[R];
    return cover[R]-cover[L-1];
}
main(){
    int i,j;
    RII(n1,n2);
    int nn[2]={n1,n2};
    DRI(K);
    REP(i,2){
        RS(input[i]);
        REP(j,nn[i])input[i][j]=ch(input[i][j]);
    }
    REP(cc,4){
        n1=nn[0];
        n2=nn[1];
        cover[0]=(input[0][0]==cc);
        REPP(i,1,n1)cover[i]=cover[i-1]+(input[0][i]==cc);
        REP(i,n1){
            if(get(i-K,i+K))s[i]=0;
            else s[i]=1;
        }
        REP(i,n2){
            if(input[1][i]==cc)t[n2-1-i]=1;
            else t[n2-i-1]=0;
        }
        int ii;
        for(ii=2;ii<n1+n2 || ii<max(n1,n2)*2;ii*=2);
        for(;n1<ii;n1++)s[n1]=0;
        for(;n2<ii;n2++)t[n2]=0;
        ntt(0,n1,s);
        ntt(0,n2,t);
        mul(n2,t,s);
        ntt(1,n2,t);

        REP(i,nn[0]-nn[1]+1){
            if(t[i+nn[1]-1])stop[i]=1;
        }
    }
    /*
    while(scanf("%s %s",a,b)==2){
        for(n1=0;a[n1];n1++);
        for(n2=0;b[n2];n2++);
        for(i=0;n1--;i++)
            s[i]=a[n1]-'0';
        n1=i;
        for(i=0;n2--;i++)
            t[i]=b[n2]-'0';
        n2=i;
        for(i=2;i<n1+n2 || i<max(n1,n2)*2;i*=2);
        for(;n1<i;n1++)s[n1]=0;
        for(;n2<i;n2++)t[n2]=0;
        ntt(0,n1,s);
        ntt(0,n2,t);
        mul(n2,t,s);
        ntt(1,n2,t);
        t[n2]=0;
        for(i=0;i<n2;i++){
            t[i+1]+=t[i]/10;
            t[i]%=10;
        }
        if(t[n2])n2++;
        while(n2 && !t[n2-1])n2--;
        printf("%d",t[n2-1]);
        for(i=n2-2;i>=0;i--)
            printf("%d",t[i]);
        puts("");
    }*/
    int ans=0;
    REP(i,nn[0]-nn[1]+1)if(!stop[i])ans++;
    printf("%d\n",ans);
}