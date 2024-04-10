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
const ll INF=(ll)2e18;
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
const int N=1000005;
int n,m; 
char s[N],t[N],t2[N];
int nxt[N];

int main()
{
    int T=read();
    while(T--){
        scanf("%s",s+1); n=strlen(s+1);
        int f=0,b=n+1;
        while(f+1<=b-1&&s[f+1]==s[b-1]) f++,b--;
        m=0; 
        for(int i=f+1;i<=b-1;i++) t[++m]=s[i],t2[m]=t[m];
        reverse(t2+1,t2+m+1);
        for(int i=0;i<=m;i++) nxt[i]=0;
        for(int i=1;i<m;i++){
            int j=nxt[i];
            while(j&&t[j+1]!=t[i+1]) j=nxt[j];
            if(t[j+1]==t[i+1]) j++;
            nxt[i+1]=j;
        }
        int now1=0;
        for(int i=0;i<m;i++){
            while(now1&&t2[i+1]!=t[now1+1]) now1=nxt[now1];
            if(t[now1+1]==t2[i+1]) now1++;
        }

        for(int i=0;i<=m;i++) nxt[i]=0;
        for(int i=1;i<m;i++){
            int j=nxt[i];
            while(j&&t2[j+1]!=t2[i+1]) j=nxt[j];
            if(t2[j+1]==t2[i+1]) j++;
            nxt[i+1]=j;
        }
        int now2=0;
        for(int i=0;i<m;i++){
            while(now2&&t[i+1]!=t2[now2+1]) now2=nxt[now2];
            if(t2[now2+1]==t[i+1]) now2++;
        }
        for(int i=1;i<=f;i++) printf("%c",s[i]);
        if(now1>now2) for(int i=1;i<=now1;i++) printf("%c",t[i]);
        else for(int i=1;i<=now2;i++) printf("%c",t2[i]);
        for(int i=b+(f==b);i<=n;i++) printf("%c",s[i]);
        //cout<<f+max(now1,now2)+n-b-(f==b)+1;
        puts("");
    }
    return 0;
}