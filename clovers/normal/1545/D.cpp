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
const int N=1005;
int m,n,a[N][N];
ll sum1[N],sum2[N];

int main()
{
    m=read(); n=read();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) 
            a[i][j]=read(),sum1[i]+=a[i][j],sum2[i]+=(ll)a[i][j]*a[i][j];
    }
    int pos,delta=inf,num=0;
    for(int i=1;i<n;i++){
        if(delta!=sum1[i]-sum1[i-1]){
            if(!num) delta=sum1[i]-sum1[i-1];
            else num--;
        }
        else num++;
    }
    for(int i=1;i<n-1;i++) if(sum1[i]-sum1[i-1]!=delta&&sum1[i+1]-sum1[i]!=delta) pos=i;
    ll sumv2,delv=sum1[pos-1]+delta-sum1[pos];
    if(pos>2) sumv2=(sum2[2]+sum2[0]-2*sum2[1])/2;
    else sumv2=(sum2[n-1]+sum2[n-3]-2*sum2[n-2])/2;
    for(int j=0;j<m;j++){
        int now=a[pos][j]+delv;
        ll nows=sum2[pos]-(ll)a[pos][j]*a[pos][j]+(ll)now*now;
        if(sum2[pos+1]+sum2[pos-1]-2*nows==2*sumv2){
            printf("%d %d\n",pos,now);
            return 0;
        }
    }
    return 0;
}