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
const int N=500005;
char s[N];
int n,a[N],b[N];

int calc(int x,int y){
    int ret=0;
    for(int i=1;i<=n;i++){
        if(x<=a[i]&&y<=b[i]) checkmax(ret,max(a[i]-x,b[i]-y));
        else if(x>=a[i]&&y>=b[i]) checkmax(ret,max(x-a[i],y-b[i]));
        else checkmax(ret,_abs(x-a[i])+_abs(y-b[i]));
    }
    return ret;
}

pii find(int x){
    int l=0,r=500000,mid1,mid2,best,ret=inf;
    while(l+5<=r){
        mid1=(l+l+r)/3,mid2=(l+r+r)/3;
        int val1=calc(x,mid1),val2=calc(x,mid2);
        if(val1<val2) ret=val1,best=mid1,r=mid2;
        else ret=val2,best=mid2,l=mid1;
    }
    for(int i=l;i<=r;i++){
        int val=calc(x,i);
        if(ret>val) ret=val,best=i;
    }
    return mk(ret,best);
}

int main()
{
    n=read();
    for(int i=1;i<=n;i++){
        scanf("%s",s+1); int len=strlen(s+1);
        for(int j=1;j<=len;j++){
            if(s[j]=='B') a[i]++;
            else b[i]++;
        }
    }
    int l=0,r=500000,mid1,mid2,rx,ry,ret=inf;
    while(l+5<=r){
        mid1=(l+l+r)/3; mid2=(l+r+r)/3;
        pii val1=find(mid1),val2=find(mid2);
        if(val1.first<val2.first) ret=val1.first,rx=mid1,ry=val1.second,r=mid2;
        else ret=val2.first,rx=mid2,ry=val2.second,l=mid1;
    }
    for(int i=l;i<=r;i++){
        pii val=find(i);
        if(val.first<ret) ret=val.first,rx=i,ry=val.second;
    }
    cout<<ret<<endl;
    for(int i=1;i<=rx;i++) printf("B");
    for(int i=1;i<=ry;i++) printf("N");
    return 0;
}