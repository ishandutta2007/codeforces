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
int n,a[N],pre[N];
int ans[N][N]; pii id[N];

bool check(){
    for(int i=1;i<=n;i++) if(a[i]) return 1;
    return 0;
}

int rnd=0;
int del(int m,int pos){
    rnd++; int rest=m,restrnd=n+1-rnd;
    int bl=(a[pos]==0);
    for(int i=1;i<=m;i++){
        if(i==pos) continue;
        if(a[i]!=1) bl=0;
    }
    if(bl){
        for(int i=1;i<=m;i++){
            if(i==pos) continue;
            a[i]--; ans[rnd][id[i].second]=1;
        }
        return m;
    }
    for(int i=1;i<=m;i++){
        if(i==pos) continue;
        ans[rnd][id[i].second]=1;
        if(!--a[i]){
            for(int j=i+1;j<=m;j++) if(a[j]!=1){
                ans[rnd][id[j].second]=1;
                a[j]--;
            }
            return i;
        }
    }
    return 0;
}

void solve(int m,int flag){
    if(!check()) return;
    for(int i=1;i<=n;i++) id[i].first=a[i];
    sort(id+1,id+n+1); reverse(id+1,id+n+1);
    for(int i=1;i<=n;i++) a[i]=id[i].first;
    if(!flag){
        int pos=del(m,0);
        if(pos){
            solve(m-1,0);
            return;
        }
    }
    for(int i=m;i>=1;i--){
        int pos=del(m,i);
        //out(m); out(i); outln(pos);
        if(!pos) continue;
        if(pos>=i){
            solve(m-1,1);
            return;
        }
        else{
            solve(m-1,0);
            return;
        }
    }
}

int main()
{
    n=read();
    for(int i=1;i<=n;i++) a[i]=read(),id[i]=mk(a[i],i);
    solve(n,0);
    cout<<rnd<<endl;
    for(int i=1;i<=rnd;i++){
        for(int j=1;j<=n;j++) printf("%d",ans[i][j]);
        puts("");
    }
    return 0;
}