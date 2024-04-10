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
const int N=6005;
int n; pii a[N];
ll ans=0; int num[4][4];

int main()
{
    n=read();
    for(int i=1;i<=n;i++) a[i].first=read(),a[i].second=read();
    for(int i=1;i<=n;i++){
        memset(num,0,sizeof(num));
        for(int j=i+1;j<=n;j++){
            int x=_abs(a[i].first-a[j].first),y=_abs(a[i].second-a[j].second);
            num[x%4][y%4]++;
        }
        for(int x=0;x<4;x+=2){
            for(int y=0;y<4;y+=2){
                int num1=(x==0&&y==0);
                for(int xx=x;xx<4;xx+=2){
                    for(int yy=y;yy<4;yy+=2){
                        int num2=(xx==0&&yy==0),num3=(xx-x==0&&yy-y==0);
                        if((num1+num2+num3)&1){
                            if(num3) ans+=(num[x][y]-1)*num[x][y]/2;
                            else ans+=num[x][y]*num[xx][yy];
                        }
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}