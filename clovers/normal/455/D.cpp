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
int ans=0,a[N],n,bel[N],Blk;
struct Brick{
    int cnt[N],fst=inf,lst=-1;
}B[301];
struct List{
    int pre[N],nxt[N];
    void init(){for(int i=0;i<=n+1;i++) pre[i]=i-1,nxt[i]=i+1;}
    void insert(int x,int y){//before y
        nxt[pre[y]]=x; pre[x]=pre[y];
        nxt[x]=y; pre[y]=x;
    }
    void del(int x){pre[nxt[x]]=pre[x]; nxt[pre[x]]=nxt[x];}
}L;
void init(){
    n=read(); for(int i=1;i<=n;i++) a[i]=read();
    L.init();
    Blk=(int)sqrt(n)+1; 
    if(n<=5) Blk=n; if(n/Blk>290) Blk=400;
    for(int i=1;i<=n;i++) bel[i]=(i+Blk-1)/Blk;
    for(int i=1;i<=n;i++){
        B[bel[i]].fst=(bel[i]-1)*Blk+1;
        B[bel[i]].lst=bel[i]*Blk;
        B[bel[i]].cnt[a[i]]++;
    }
}

void decode(int &x){x=(x+ans-1)%n+1;}
int find(int x){
    int ret=(bel[x]-1)*Blk+1,now=B[bel[x]].fst;
    while(ret!=x) ret++,now=L.nxt[now];
    return now;
}
void solve(){
    int m=read();
    while(m--){
        int opt=read();
        if(opt==1){
            int l=read(),r=read();
            decode(l); decode(r); if(l>r) swap(l,r);
            if(l==r) continue;
            int x=find(l),y=find(r);
            if(B[bel[l]].fst==x) B[bel[l]].fst=y;
            if(B[bel[r]].lst==y){
                B[bel[r]].lst=L.pre[y];
                if(B[bel[r]].lst==B[bel[r]].fst) B[bel[r]].fst==B[bel[r]].lst;
            }
            if(bel[l]==bel[r]) {L.del(y); L.insert(y,x); continue;}
            B[bel[r]].cnt[a[B[bel[r]-1].lst]]++;
            B[bel[r]].cnt[a[y]]--;
            B[bel[l]].cnt[a[y]]++;
            B[bel[l]].cnt[a[B[bel[l]].lst]]--;
            B[bel[r]].fst=B[bel[r]-1].lst;
            for(int i=bel[r]-1;i>bel[l];i--){
                B[i].cnt[a[B[i].lst]]--;
                B[i].cnt[a[B[i-1].lst]]++;
                B[i].lst=L.pre[B[i].lst];
                B[i].fst=B[i-1].lst;
            }
            if(B[bel[l]].lst==x) B[bel[l]].lst=y;
            else B[bel[l]].lst=L.pre[B[bel[l]].lst];
            L.del(y); L.insert(y,x);
        }
        else{
            int l=read(),r=read(),k=read();
            decode(l); decode(r); decode(k);
            if(l>r) swap(l,r);
            int x=find(l),y=find(r);
            ans=0;
            if(bel[l]==bel[r]){
                ans+=(a[x]==k);
                while(x!=y) ans+=(a[L.nxt[x]]==k),x=L.nxt[x];
                printf("%d\n",ans);
                continue;
            }
            for(int i=bel[l]+1;i<bel[r];i++) ans+=B[i].cnt[k];
            ans+=(a[x]==k);
            while(x!=B[bel[l]].lst) ans+=(a[L.nxt[x]]==k),x=L.nxt[x];
            x=B[bel[r]].fst; ans+=(a[x]==k);
            while(x!=y) ans+=(a[L.nxt[x]]==k),x=L.nxt[x];
            printf("%d\n",ans);
        }
    }
}

int main()
{
    init(); solve();
    return 0;
}