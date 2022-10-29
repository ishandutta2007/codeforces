/*
the vast starry sky,
bright for those who chase the light.
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define mk make_pair
const int inf=(int)1e9;
const ll INF=(ll)5e18;
const int MOD=1e9+7;
int _abs(int x){return x<0 ? -x : x;}
int add(int x,int y){x+=y; return x>=MOD ? x-MOD : x;}
int sub(int x,int y){x-=y; return x<0 ? x+MOD : x;}
#define mul(x,y) (ll)(x)*(y)%MOD
void Add(int &x,int y){x+=y; if(x>=MOD) x-=MOD;}
void Sub(int &x,int y){x-=y; if(x<0) x+=MOD;}
void Mul(int &x,int y){x=mul(x,y);}
int qpow(int x,int y){int ret=1; while(y){if(y&1) ret=mul(ret,x); x=mul(x,x); y>>=1;} return ret;}
void checkmin(int &x,int y){if(x>y) x=y;}
void checkmax(int &x,int y){if(x<y) x=y;}
void checkmin(ll &x,ll y){if(x>y) x=y;}
void checkmax(ll &x,ll y){if(x<y) x=y;}
#define out(x) cerr<<#x<<'='<<x<<' '
#define outln(x) cerr<<#x<<'='<<x<<endl
#define sz(x) (int)(x).size()
inline int read(){
    int x=0,f=1; char c=getchar();
    while(c>'9'||c<'0'){if(c=='-') f=-1; c=getchar();}
    while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=getchar();
    return x*f;
}
const int N=105;
int C[N][N],k; ll n;
struct matrix{
    int a[N][N],n,m;
    matrix(){}
    matrix(int n,int m):n(n),m(m){memset(a,0,sizeof(a));}
    void init(){for(int i=1;i<=n;i++) a[i][i]=1;}
    void print(){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++) cerr<<a[i][j]<<" "; cerr<<"\n";
        }
    }
};
matrix operator * (matrix &A,matrix &B){
    matrix C(A.n,B.m);
    for(int i=1;i<=C.n;i++){
        for(int k=1;k<=A.m;k++) if(A.a[i][k]){
            for(int j=1;j<=C.m;j++) 
                Add(C.a[i][j],mul(A.a[i][k],B.a[k][j]));
        }
    }
    return C;
}
matrix qpow(matrix &A,ll b){
    matrix ret(A.n,A.n); ret.init();
    while(b){
        if(b&1) ret=ret*A;
        A=A*A; b>>=1;
    }
    return ret;
}

int main()
{
    for(int i=0;i<=100;i++){
        C[i][0]=C[i][i]=1;
        for(int j=1;j<i;j++){
            C[i][j]=add(C[i-1][j],C[i-1][j-1]);
        }
    }
    scanf("%lld%d",&n,&k);
    matrix Base(2*(k+1)+1,2*(k+1)+1);
    for(int i=0;i<=k;i++){
        int pos=(i+1)*2-1;
        for(int j=0;j<=i;j++){
            Base.a[(j+1)*2][pos]=C[i][j];
            Base.a[(j+1)*2-1][pos+1]=C[i][j];
            Base.a[(j+1)*2][pos+1]=C[i][j];
        }
    }
    for(int j=0;j<=k;j++){
        Base.a[(j+1)*2-1][Base.n]=C[k][j];
        Base.a[(j+1)*2][Base.n]=C[k][j];
    }
    Base.a[Base.n][Base.n]=1;
    matrix ans(1,2*(k+1)+1);
    int f1=1,f2=2;
    for(int i=0;i<=k;i++){
        int pos=(i+1)*2-1; 
        ans.a[1][pos]=mul(f1,qpow(2,i)); 
        ans.a[1][pos+1]=mul(f2,qpow(2,i));
    }
    ans.a[1][ans.m]=add(f1,mul(f2,qpow(2,k)));
    if(n==1){puts("1"); return 0;}
    Base=qpow(Base,n-2);
    ans=ans*Base;
    cout<<ans.a[1][ans.m]<<endl;
    return 0;
}