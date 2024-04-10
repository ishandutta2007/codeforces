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
const int M=251;
int dp[M][M][M],n,q,nxt[N][26];
int s1[M],s2[M],s3[M],top1=0,top2=0,top3=0;
char s[N];
void trans(int i,int j,int k){
    if(i) checkmin(dp[i][j][k],nxt[dp[i-1][j][k]][s1[i]]);
    if(j) checkmin(dp[i][j][k],nxt[dp[i][j-1][k]][s2[j]]);
    if(k) checkmin(dp[i][j][k],nxt[dp[i][j][k-1]][s3[k]]);
}

int main()
{
    n=read(); q=read(); scanf("%s",s+1);
    for(int i=0;i<26;i++) nxt[n][i]=n+1,nxt[n+1][i]=n+1;
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<26;j++) nxt[i][j]=nxt[i+1][j];
        nxt[i][s[i+1]-'a']=i+1;
    }
    for(int i=0;i<=250;i++){
        for(int j=0;j<=250;j++){
            for(int k=0;k<=250;k++) dp[i][j][k]=n+1;
        }
    } dp[0][0][0]=0;
    while(q--){
        char c[2],opt[2]; int num; 
        scanf("%s",opt);
        if(opt[0]=='+'){
            scanf("%d%s",&num,c);
            if(num==1){
                s1[++top1]=c[0]-'a';
                for(int j=0;j<=top2;j++){
                    for(int k=0;k<=top3;k++) trans(top1,j,k);
                }
            }
            else if(num==2){
                s2[++top2]=c[0]-'a';
                for(int i=0;i<=top1;i++){
                    for(int k=0;k<=top3;k++) trans(i,top2,k);
                }
            }
            else{
                s3[++top3]=c[0]-'a';
                for(int i=0;i<=top1;i++){
                    for(int j=0;j<=top2;j++) trans(i,j,top3);
                }
            }
        }
        else{
            num=read();
            if(num==1){
                for(int j=0;j<=top2;j++){
                    for(int k=0;k<=top3;k++) dp[top1][j][k]=n+1;
                }
                top1--;
            }
            else if(num==2){
                for(int i=0;i<=top1;i++){
                    for(int k=0;k<=top3;k++) dp[i][top2][k]=n+1;
                }
                top2--;
            }
            else{
                for(int i=0;i<=top1;i++){
                    for(int j=0;j<=top2;j++) dp[i][j][top3]=n+1;
                }
                top3--;
            }
        }
        puts(dp[top1][top2][top3]<=n ? "YES" : "NO");
    }
    return 0;
}