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
const int N=200005;
int n,k,tot=1;
char s[N];
struct Trie{
    int son[N][26],dp1[N],dp2[N],sz[N];
    void insert(){
        int x=1,len=strlen(s+1);
        for(int i=1;i<=len;i++){
            int c=s[i]-'a';
            if(!son[x][c]) son[x][c]=++tot,sz[x]++;
            x=son[x][c];
        }
    }
    void dfs(int u){
        for(int i=0;i<26;i++){
            if(son[u][i]){
                dfs(son[u][i]);
                dp1[u]|=(dp1[son[u][i]]^1);
                dp2[u]|=(dp2[son[u][i]]^1);
            }
        }
        if(!sz[u]) dp2[u]=1;        
    }
}tree;

int main()
{
    n=read(); k=read();
    for(int i=1;i<=n;i++){
        scanf("%s",s+1);
        tree.insert();
    }
    tree.dfs(1);
    if(tree.dp1[1]==0) puts("Second");
    else{
        if(tree.dp2[1]) puts("First");
        else{
            if(k&1) puts("First");
            else puts("Second");
        }
    }
    return 0;
}