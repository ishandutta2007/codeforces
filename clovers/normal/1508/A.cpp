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
const int N=300005;
int n; char s[3][N],a[N];
int cnt[2];
void build(char *s1,char *s2,char c){
    int top=0,tot=0,i1=1,i2=1;
    while(tot<n){
        while(s1[i1]!=c) a[++top]=s1[i1],i1++;
        while(s2[i2]!=c) a[++top]=s2[i2],i2++;
        tot++; a[++top]=c; i1++; i2++;
    }
    for(int i=i1;i<=n+n;i++) a[++top]=s1[i];
    for(int i=i2;i<=n+n;i++) a[++top]=s2[i];
}

int main()
{
    int T=read();
    while(T--){
        n=read();
        for(int i=0;i<=2;i++){
            cnt[i]=0;
            scanf("%s",s[i]+1);
            for(int j=1;j<=n+n;j++) cnt[i]+=s[i][j]-'0';
        }
        int flag=0;
        for(int i=0;i<=2;i++){
            for(int j=i+1;j<=2;j++){
                if(flag) continue;
                if(cnt[i]>=n&&cnt[j]>=n){
                    flag=1;
                    build(s[i],s[j],'1');
                }
                if(cnt[i]<n&&cnt[j]<n){
                    flag=1;
                    build(s[i],s[j],'0');
                }
            }
        }
        for(int i=1;i<=n*3;i++) printf("%c",a[i]);
        puts("");
    }
    return 0;
}