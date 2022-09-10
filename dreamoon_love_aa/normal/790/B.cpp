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
const int SIZE = 2e5+10;
typedef vector<int> VI;
const double PI = acos(-1.0);
 
template<typename T> struct TPoint2D {
    T X, Y;
    TPoint2D() : X(), Y() {}
    TPoint2D(const T& x, const T& y) : X(x), Y(y) {}
    TPoint2D(const TPoint2D<T>& p) : X(p.X), Y(p.Y) {}
    TPoint2D& operator=(const TPoint2D<T>& p) { X = p.X; Y = p.Y; return *this; }
    T operator&(const TPoint2D<T>& p) const { return X * p.X + Y * p.Y; }
    T operator^(const TPoint2D<T>& p) const { return X * p.Y - Y * p.X; }
    TPoint2D conj() const { return TPoint2D(X, -Y); }
    TPoint2D<T> operator*(const TPoint2D<T>& p) const { return TPoint2D<T>(*this & p.conj(), -*this ^ p.conj()); }
    TPoint2D<T> operator*(const T& p) const { return TPoint2D<T>(p * X, p * Y); }
    TPoint2D<T> operator-(void) const { return TPoint2D(-X, -Y); }
    TPoint2D<T> operator+(const TPoint2D<T>& p) const { return TPoint2D(X + p.X, Y + p.Y); }
    TPoint2D<T> operator-(const TPoint2D<T>& p) const { return *this + (-p); }
    T norm() const { return X * X + Y * Y; }
};
 
typedef TPoint2D<double> base;
 
void fft (vector<base>& a, bool invert) {
    int n = (int) a.size();
    for (int i=1, j=0; i<n; ++i) {
        int bit = n >> 1;
        for (; j>=bit; bit>>=1)
            j -= bit;
        j += bit;
        if (i < j)
            swap (a[i], a[j]);
    }
    for (int len=2; len<=n; len<<=1) {
        double ang = 2*PI/len * (invert ? -1 : 1);
        base wlen (cos(ang), sin(ang));
        for (int i=0; i<n; i+=len) {
            base w (1, 0);
            for (int j=0; j<len/2; ++j) {
                base u = a[i+j],  v = a[i+j+len/2] * w;
                a[i+j] = u + v;
                a[i+j+len/2] = u - v;
                w = w*wlen;
            }
        }
    }
    if (invert)
        for (int i=0; i<n; ++i)
            a[i] = a[i] * (1.0 / n);
}
LL dd[SIZE];
void mul(const VI & a, const VI & b,int cc) {
    if(a.size()<=32){
        REP(i,SZ(a)){
            REP(j,i)dd[i+j]+=cc*(LL)a[i]*b[j]*2;
            dd[i+i]+=cc*(LL)a[i]*a[i];
        }
        return;
    }
    int n = 1;
    while (n < (int)a.size() + (int)b.size()) n *= 2;
    vector<base> x(n), y(n);
    for (int i = 0; i < a.size(); ++i) x[i] = base(a[i], 0);
    for (int i = 0; i < b.size(); ++i) y[i] = base(b[i], 0);
    fft(x, 0);
    fft(y, 0);
    for (int i = 0; i < x.size(); ++i) x[i] = x[i] * y[i];
    fft(x, 1);
    VI res(a.size()+b.size());
    for (int i = 1; i < res.size(); ++i) dd[i] += cc*(LL)round(x[i].X);
}
// template end here
VI e[SIZE];
int N,L,R;
int d[SIZE],dn;
int bfs[SIZE],sons[SIZE];
int used[SIZE],tt,tt2,father[SIZE];
vector<int>qq;
template <class T>
void maa(T& x,T y){
    if(x<y)x=y;
}
template <class T>
void mii(T& x,T y){
    if(x>y)x=y;
}
void build(int st){
    bfs[0]=st;
    tt2--;
    used[st]=tt2;
    int i=0,j=1;
    for(;i<j;i++){
        int x=bfs[i];
        sons[x]=1;
        REP(k,SZ(e[x])){
            int y=e[x][k];
            if(used[y]==tt||used[y]==tt2)continue;
            father[y]=x;
            used[y]=tt2;
            bfs[j++]=y;
        }
    }
    int num=j;
    for(i=j-1;i>=0;i--){
        int x=bfs[i];
        if(sons[x]*2>=num){
            qq.PB(x);
            used[x]=tt;
            REP(k,SZ(e[x])){
                int y=e[x][k];
                if(used[y]!=tt)build(y);
            }
            return;
        }
        sons[father[x]]+=sons[x];
    }
}
void init(){
    tt++;
    build(0);
}
int all[SIZE],cnt[SIZE],step[SIZE];
VI get_vector(int st){
    bfs[0]=st;
    int i=0,j=1;
    tt2--;
    used[st]=tt2;
    step[st]=1;
    int up=0;
    for(;i<j;i++){
        int x=bfs[i];
        if(step[x]>up)
            cnt[++up]=0;
        cnt[up]++;
        REP(k,SZ(e[x])){
            int y=e[x][k];
            if(used[y]==tt||used[y]==tt2)continue;
            used[y]=tt2;
            step[y]=step[x]+1;
            bfs[j++]=y;
        }
    }
    return vector<int>(cnt,cnt+up+1);
}
void solve(){
    tt++;
    REP(i,SZ(qq)){
        int me=qq[i];
        int up=0;
        all[0]=1;
        used[me]=tt;
        REP(j,SZ(e[me])){
            int you=e[me][j];
            if(used[you]!=tt){
                VI cur=get_vector(you);
                while(up+1<SZ(cur))all[++up]=0;
                REPP(k,1,SZ(cur))
                    all[k]+=cur[k];
                mul(cur,cur,-1);
            }
        }
        VI cur(all,all+up+1);
        mul(cur,cur,1);
    }
}
LL mypow(LL x,LL y){
    x%=MOD;
    LL res=1%MOD;
    while(y){
        if(y&1)res=res*x%MOD;
        y>>=1;
        x=x*x%MOD;
    }
    return res;
}
int main(){
    int K;
    RII(N,K);
    REPP(i,1,N){
        DRII(x,y);
        x--;y--;
        e[x].PB(y);
        e[y].PB(x);
    }
    init();
    solve();
    LL an=0;
    REPP(i,1,N){
        an+=dd[i]/2*((i+K-1)/K);
    }
    printf("%I64d\n",an);
    return 0;
}