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
int n,a[N],T,ans[N],id[N];
vector<int> v[N];
bool cmp(int x,int y){return sz(v[x])>sz(v[y]);}

int main()
{
    T=read();
    while(T--){
        n=read(); int X=read(),Y=read()-X;
        int rest=n-X;
        for(int i=1;i<=n;i++) a[i]=read(),ans[i]=0;
        for(int i=1;i<=n+1;i++) v[i].clear();
        for(int i=1;i<=n;i++) v[a[i]].push_back(i);
        int pos=-1;
        set<pii> st;
        for(int i=1;i<=n+1;i++) 
            if(!v[i].empty()) st.insert(mk(sz(v[i]),i));
            else pos=i;
        while(X--){
            pii u=*(--st.end()); st.erase(u);
            int num=u.second;
            ans[v[num].back()]=num; v[num].pop_back();
            u.first--; if(u.first) st.insert(u);
        }
        for(int i=1;i<=n+1;i++) id[i]=i;
        sort(id+1,id+n+2,cmp);
        int num=sz(v[id[1]]);
        vector<int> seq;
        for(int i=2;i<=n+1;i++) for(auto &u : v[id[i]]) seq.push_back(id[i]);
        for(auto &u : v[id[1]]) seq.push_back(id[1]);
        int nowx=1,nowy=0;
        for(auto &u : seq){
            if(!Y) break;
            if(a[v[id[nowx]][nowy]]==u) ans[v[id[nowx]][nowy]]=pos;
            else ans[v[id[nowx]][nowy]]=u,Y--;
            nowy++;
            if(nowy==sz(v[id[nowx]])) nowx++,nowy=0;
        }
        for(int i=1;i<=n;i++) if(!ans[i]) ans[i]=pos;
        if(Y) {puts("NO"); continue;}
        puts("YES");
        for(int i=1;i<=n;i++) printf("%d ",ans[i]); puts("");
    }
    return 0;
}