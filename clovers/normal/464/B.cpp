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
int a[9][3],id[9][3],b[9][3];
ll sqr(ll x){return x*x;}

void check(){
    int flag=1;
    for(int i=1;i<=8;i++){
        ll t[10],top=0;
        for(int j=1;j<=8;j++) if(i!=j){
            t[++top]=sqr(b[i][0]-b[j][0])+sqr(b[i][1]-b[j][1])+sqr(b[i][2]-b[j][2]);
        }
        sort(t+1,t+top+1);
        if(t[1]==t[3]&&t[4]==t[6]&&t[1]!=0){
            if(t[1]*2==t[4]&&t[1]*3==t[7]) continue;
        }
        return;
    }
    if(flag){
        puts("YES");
        for(int i=1;i<=8;i++){
            for(int j=0;j<=2;j++) printf("%d ",b[i][j]);
            puts("");
        }
        exit(0);
    }
}
void dfs(int now){
    if(now==9){check(); return;}
    do{
        for(int i=0;i<=2;i++) b[now][i]=a[now][id[now][i]];
        dfs(now+1);
    }while(next_permutation(id[now],id[now]+3));
}

int main()
{
    for(int i=1;i<=8;i++){
        for(int j=0;j<=2;j++) a[i][j]=read(),id[i][j]=j;
    }
    dfs(1);
    puts("NO");
    return 0;
}