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
int T,n,m,nxt[N][26][2],now[26][2];
char s[N],t[N];

int main()
{
    int T=read();
    while(T--){
        scanf("%s%s",s+1,t+1);
        n=strlen(s+1),m=strlen(t+1);
        for(int i=0;i<=n;i++) memset(nxt[i],-1,sizeof(nxt[i]));
        memset(now,-1,sizeof(now));
        for(int i=n;i>=0;i--){
            memcpy(nxt[i],now,sizeof(now));
            if(i&1) now[s[i]-'a'][1]=i;
            else if(i!=0) now[s[i]-'a'][0]=i;
        }
        int pos0=nxt[0][t[1]-'a'][0],pos1=nxt[0][t[1]-'a'][1];
        for(int i=2;i<=m;i++){
            if(pos0!=-1) pos0=nxt[pos0][t[i]-'a'][1];
            if(pos1!=-1) pos1=nxt[pos1][t[i]-'a'][0];
            swap(pos0,pos1);
        }
        if((pos0!=-1&&n%2==0)||(pos1!=-1&&n%2==1)) puts("YES");
        else puts("NO");
    }
    return 0;
}