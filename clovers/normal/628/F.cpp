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
const int N=50005;
void GG(){puts("unfair"); exit(0);}
int n,q,b,L[N],R[N],num[N],top=0; pii a[N];
int f(int x,int id){
    if(x<id) return 0;
    return (x-id)/5+1;
}
int calc(int l,int r,int id){return f(r,id)-f(l-1,id);}

int main()
{
    n=read(); b=read(); q=read();
    for(int i=1;i<=q;i++) a[i].first=read(),a[i].second=read();
    sort(a+1,a+q+1);
    a[0]=mk(0,0); a[q+1]=mk(b,n);
    for(int i=1;i<=q+1;i++){
        if(a[i].second<a[i-1].second) GG();
        if(a[i].second-a[i-1].second>a[i].first-a[i-1].first) GG();
        L[++top]=a[i-1].first+1,R[top]=a[i].first;
        num[top]=a[i].second-a[i-1].second;
    }
    for(int S=0;S<=31;S++){
        int cnt=0,sum=0;
        for(int i=0;i<5;i++) if(S>>i&1) cnt++;
        for(int i=1;i<=top;i++){
            int tmp=0;
            for(int j=1;j<=5;j++) if(S>>(j-1)&1) 
                tmp+=calc(L[i],R[i],j);
            sum+=min(tmp,num[i]);
        }
        if(sum<cnt*n/5) GG();
    }
    puts("fair");
    return 0;
}