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
int n,q;
char s[N];
struct Segment_Tree{
    int sum[N<<2],lmx[N<<2],rmi[N<<2],lans[N<<2],rans[N<<2],aans[N<<2],ans[N<<2];
    void pushup(int x){
        sum[x]=sum[x<<1]+sum[x<<1|1];
        lmx[x]=max(lmx[x<<1],sum[x<<1]+lmx[x<<1|1]);
        rmi[x]=min(rmi[x<<1|1],sum[x<<1|1]+rmi[x<<1]);
        aans[x]=max(aans[x<<1]+sum[x<<1|1],aans[x<<1|1]-sum[x<<1]);
        lans[x]=max(max(lans[x<<1],lans[x<<1|1]-sum[x<<1]),aans[x<<1]+lmx[x<<1|1]);
        rans[x]=max(max(rans[x<<1|1],sum[x<<1|1]+rans[x<<1]),aans[x<<1|1]-rmi[x<<1]);
        ans[x]=max(ans[x<<1],ans[x<<1|1]);
        checkmax(ans[x],max(rans[x<<1]+lmx[x<<1|1],lans[x<<1|1]-rmi[x<<1]));
    }
    void build(int x,int l,int r){
        if(l==r){
            int val=(s[l]=='(' ? 1 : -1);
            sum[x]=val; lmx[x]=max(val,0); rmi[x]=min(0,val);
            aans[x]=1; lans[x]=1; rans[x]=1; ans[x]=1;
            //out(l); out(r); out(sum[x]); out(lmx[x]); out(rmi[x]);
            //out(lans[x]); out(rans[x]); out(aans[x]); outln(ans[x]);
            return;
        }
        int mid=(l+r)>>1;
        build(x<<1,l,mid); build(x<<1|1,mid+1,r);
        pushup(x);
        //out(l); out(r); out(sum[x]); out(lmx[x]); out(rmi[x]);
        //out(lans[x]); out(rans[x]); out(aans[x]); outln(ans[x]);
    }
    void update(int x,int l,int r,int pos,int val){
        if(l==r){
            sum[x]=val; lmx[x]=max(val,0); rmi[x]=min(0,val);
            aans[x]=1; lans[x]=1; rans[x]=1; ans[x]=1;
            return;
        }
        int mid=(l+r)>>1;
        if(mid>=pos) update(x<<1,l,mid,pos,val);
        else update(x<<1|1,mid+1,r,pos,val);
        pushup(x);
    }
}T;

int main()
{
    n=read(); q=read();
    n--; n*=2;
    scanf("%s",s+1);
    T.build(1,1,n);
    printf("%d\n",T.ans[1]);
    while(q--){
        int x=read(),y=read();
        if(s[x]==s[y]){
            printf("%d\n",T.ans[1]);
            continue;
        }
        if(s[x]==')') swap(x,y);
        T.update(1,1,n,x,-1);
        T.update(1,1,n,y,1);
        swap(s[x],s[y]);
        printf("%d\n",T.ans[1]);
    }
    return 0;
}