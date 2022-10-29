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
const int N=100005;
int n,p,q;
struct Point{
    double x,y;
    Point(){}
    Point(int x,int y):x(x),y(y){}
    bool operator < (const Point &rhs) const{
        if(x==rhs.x) return y<rhs.y;
        return x<rhs.x;
    }
}a[N];
#define Vector Point
Vector operator - (Vector A,Vector B){return Vector(A.x-B.x,A.y-B.y);}
double operator * (Vector A,Vector B){return A.x*B.y-A.y*B.x;}
Vector b[N]; int top=0;
double ans=1e9;
void calc(Vector a,Vector b){
    Vector d=b-a;
    double k=(1.0*q*a.x-1.0*p*a.y)/(1.0*p*d.y-1.0*q*d.x);
    if(k<0||k>1) return;
    ans=min(ans,1.0*p/(a.x+d.x*k));
}

int main()
{
    n=read(); p=read(); q=read();
    for(int i=1;i<=n;i++) a[i].x=read(),a[i].y=read();
    sort(a+1,a+n+1);
    b[++top]=a[1];
    for(int i=2;i<=n;i++){
        while((a[i].y>=b[top].y&&top)||(top>=2&&(b[top]-b[top-1])*(a[i]-b[top])>0)) top--;
        b[++top]=a[i];
    }
    b[0]=Vector(0,b[1].y); b[top+1]=Vector(b[top].x,0);
    for(int i=1;i<=top+1;i++) calc(b[i-1],b[i]);
    printf("%.8lf\n",ans);
    return 0;
}