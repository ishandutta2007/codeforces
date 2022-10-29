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
const int MOD=998244353;
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
const int N=200005;
struct matrix{
    int a[5][5],n,m;
    matrix(){}
    matrix(int n,int m):n(n),m(m){memset(a,0x3f,sizeof(a));}
    void print(){
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++) printf("%d ",a[i][j]);
            puts("");
        }
    }
};
matrix operator * (matrix A,matrix B){
    matrix C(A.n,B.m);
    for(int i=0;i<=A.n;i++){
        for(int k=0;k<=A.m;k++){
            for(int j=0;j<=B.m;j++){
                checkmin(C.a[i][j],A.a[i][k]+B.a[k][j]);
            }
        }
    }
    return C;
}
matrix mat[N];
struct Segment_Tree{
    matrix sum[N<<2];
    void pushup(int x){sum[x]=sum[x<<1]*sum[x<<1|1];}
    void build(int x,int l,int r){
        if(l==r){sum[x]=mat[l]; return;}
        int mid=(l+r)>>1;
        build(x<<1,l,mid); build(x<<1|1,mid+1,r);
        pushup(x);
    }
    matrix query(int x,int l,int r,int L,int R){
        if(L<=l&&r<=R) return sum[x];
        int mid=(l+r)>>1;
        if(mid<L) return query(x<<1|1,mid+1,r,L,R);
        if(mid>=R) return query(x<<1,l,mid,L,R);
        return query(x<<1,l,mid,L,R)*query(x<<1|1,mid+1,r,L,R);
    }
}tree;

int n,q;
char s[N];
matrix Mat(char c){
    matrix ret(4,4);
    for(int i=0;i<=4;i++) ret.a[i][i]=0;
    if(c=='2') ret.a[0][1]=0,ret.a[0][0]=1;
    else if(c=='0') ret.a[1][2]=0,ret.a[1][1]=1;
    else if(c=='1') ret.a[2][3]=0,ret.a[2][2]=1;
    else if(c=='7') ret.a[3][4]=0,ret.a[3][3]=1;
    else if(c=='6') ret.a[3][3]=1,ret.a[4][4]=1;
    return ret;
}

int main()
{
    n=read(); q=read();
    scanf("%s",s+1);
    for(int i=1;i<=n;i++) mat[i]=Mat(s[i]);
    tree.build(1,1,n);
    while(q--){
        int l=read(),r=read();
        matrix A(0,4);
        A.a[0][0]=0;
        matrix B=tree.query(1,1,n,l,r);
        A=A*B; 
        if(A.a[0][4]>n) puts("-1");
        else printf("%d\n",A.a[0][4]);
    }
    return 0;
}