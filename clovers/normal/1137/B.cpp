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
char s[N],t[N];
int nxt[N],m,n,cnt0=0,cnt1=0;
void KMP(){
    for(int i=1;i<m;i++){
        int j=nxt[i];
        while(j&&t[j+1]!=t[i+1]) j=nxt[j];
        if(t[j+1]==t[i+1]) j++;
        nxt[i+1]=j;
    }
}

int main()
{
    scanf("%s%s",s+1,t+1);
    n=strlen(s+1); m=strlen(t+1);
    KMP();
    for(int i=1;i<=n;i++){
        if(s[i]=='0') cnt0++;
        else cnt1++;
    }
    int flag=1;
    for(int i=1;i<=m;i++){
        if(t[i]=='0'){
            if(!cnt0){flag=0; break;}
            cnt0--; printf("0");
        }
        else{
            if(!cnt1){flag=0; break;}
            cnt1--; printf("1");
        }
    }
    while(true){
        if(!flag) break;
        for(int i=nxt[m]+1;i<=m;i++){
            if(t[i]=='0'){
                if(!cnt0){flag=0; break;}
                cnt0--; printf("0");
            }
            else{
                if(!cnt1){flag=0; break;}
                cnt1--; printf("1");
            }
        }
    }
    while(cnt0--) printf("0");
    while(cnt1--) printf("1");
    return 0;
}