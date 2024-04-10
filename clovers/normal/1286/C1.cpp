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
const int N=105;
void ask(int l,int r){
    printf("? %d %d\n",l,r);
    fflush(stdout);
}
char s[N];
struct seq{
    int len,a[27];
    seq(){memset(a,0,sizeof(a));}
    bool operator < (const seq &rhs) const{
        if(len==rhs.len){
            for(int i=0;i<26;i++) if(a[i]>rhs.a[i]) return 0;
            else if(a[i]<rhs.a[i]) return 1;
            return 0;
        }
        return len<rhs.len;
    }
};
multiset<seq> st;
int ans[N];
void solve(int n){
    if(n==1){
        ask(1,1);
        scanf("%s",s+1);
        ans[1]=s[1]-'a';
        return;
    }
    ask(1,n); st.clear();
    for(int i=1;i<=n*(n+1)/2;i++){
        scanf("%s",s+1);
        int len=strlen(s+1);
        seq tmp; tmp.len=len;
        for(int j=1;j<=len;j++){
            tmp.a[s[j]-'a']++;
        }
        st.insert(tmp);
    }
    ask(1,n-1);
    for(int i=1;i<=n*(n-1)/2;i++){
        scanf("%s",s+1);
        int len=strlen(s+1);
        seq tmp; tmp.len=len;
        for(int j=1;j<=len;j++){
            tmp.a[s[j]-'a']++;
        }
        st.erase(st.lower_bound(tmp));
    }
    for(int i=n;i>=1;i--){
        seq now=*st.begin(); st.erase(now);
        for(int j=n;j>i;j--) now.a[ans[j]]--;
        for(int j=0;j<26;j++) if(now.a[j]) ans[i]=j;
    }
}

int f[N][26];
int main()
{
    int n=read();
    if(n==1){
        ask(1,1);       
        scanf("%s",s);
        printf("! %s\n",s);
        fflush(stdout);
        return 0;
    }
    solve((n+1)/2);
    ask(1,n);
    memset(f,0,sizeof(f));
    for(int i=1;i<=n*(n+1)/2;i++){
        scanf("%s",s+1);
        int len=strlen(s+1);
        for(int i=1;i<=len;i++) f[len][s[i]-'a']++;
    }
    for(int i=n;i>1;i--) 
        for(int j=0;j<26;j++) f[i][j]-=f[i-1][j];
    for(int i=1;i<n;i++)
        for(int j=0;j<26;j++) f[i][j]-=f[i+1][j];
    for(int i=1;i<=n/2;i++){
        int R=n-i+1,L=i;
        f[i][ans[L]]--;
        for(int j=0;j<26;j++) if(f[i][j]){
            ans[R]=j;
        }
    }
    printf("! ");
    for(int i=1;i<=n;i++) printf("%c",ans[i]+'a');
    fflush(stdout);
    return 0;
}