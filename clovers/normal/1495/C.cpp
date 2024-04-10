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
const int N=605;
int T,n,m;
char s[N][N];

int main()
{
    T=read();
    while(T--){
        n=read(); m=read();
        for(int i=1;i<=n+3;i++){
            for(int j=1;j<=m+3;j++) s[i][j]='.';
        }
        for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
        for(int i=1;i<=n;i+=3){
            for(int j=1;j<=m;j++) s[i][j]='X';
        }
        int lst=1;
        for(int i=1;i<=n-3;i+=3){
            int flag=0;
            for(int j=1;j<=m;j++){
                if(s[i+1][j]=='X'||s[i+2][j]=='X'){
                    s[i+1][j]='X'; s[i+2][j]='X';
                    flag=1; break;
                }
            }
            if(!flag) s[i+1][1]='X',s[i+2][1]='X';
            lst=i+3;
        }
        if(n-lst==2){
            for(int j=1;j<=m;j++){
                if(s[lst+2][j]=='X'){
                    s[lst+1][j]='X';
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++) printf("%c",s[i][j]);
            puts("");
        }
    }
    return 0;
}