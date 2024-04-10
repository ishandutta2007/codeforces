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
int a[N],b[N],n,ans=0,flag,st;
char s[N];
void insb(int pos,int c); 
void insa(int pos,int c){
    if(a[pos]!=-1){
        if(a[pos]!=c) flag=0; 
        return;
    }
    a[pos]=c; if(s[pos]!='?'&&pos>=st) insb(pos,c^(s[pos]-'0'));
    if(a[n+1-pos]==-1) insa(n+1-pos,c);    
}
void insb(int pos,int c){
    if(b[pos]!=-1){
        if(b[pos]!=c) flag=0; 
        return;
    }
    b[pos]=c; if(s[pos]!='?') insa(pos,c^(s[pos]-'0'));
    if(b[n+st-pos]==-1) insb(n+st-pos,c);
}

int main()
{
    scanf("%s",s+1); n=strlen(s+1);
    for(st=2;st<=n;st++){
        memset(a,-1,sizeof(a)); memset(b,-1,sizeof(b)); flag=1;
        for(int i=1;i<st;i++) if(s[i]!='?') insa(i,s[i]-'0');
        insb(st,1); if(!flag) continue;
        int now=1;
        for(int i=1;i<=n;i++) if(a[i]==-1) insa(i,1),Mul(now,2);
        for(int i=st;i<=n;i++) if(b[i]==-1) insb(i,1),Mul(now,2);
        Add(ans,now);
    }
    cout<<ans<<endl;
    return 0;
}