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
const int N=205;
int n,t,ans=0;
struct node{
    int x,y;
}a[N];
struct Line{
    int sx,ex,y,flag;
    bool operator < (const Line &rhs) const{
        return y<rhs.y;
    }
}A[N];

int val[N];
struct Segment_Tree{
    int cover[N<<2],len[N<<2],bl[N<<2];
    void pushup(int x,int l,int mid,int r){
        if(cover[x]) len[x]=val[r]-val[l]+1;
        else{
            len[x]=(1ll*len[x<<1]+len[x<<1|1])%MOD;
            if(bl[x]) Add(len[x],val[mid+1]-val[mid]-1);
        }
    }
    void update(int x,int l,int r,int L,int R,int val){
        int mid=(l+r)>>1;
        if(L<=l&&r<=R){
            cover[x]+=val;
            pushup(x,l,mid,r);
            return;
        }
        if(mid>=L&&mid<R) bl[x]+=val;
        if(mid>=L) update(x<<1,l,mid,L,R,val);
        if(mid<R) update(x<<1|1,mid+1,r,L,R,val);
        pushup(x,l,mid,r);
    }
}tree;

int calc(int t){
    int tot=0,ret=0;
    memset(tree.len,0,sizeof(tree.len)); 
    memset(tree.cover,0,sizeof(tree.cover));
    memset(tree.bl,0,sizeof(tree.bl));
    for(int i=1;i<=n;i++){
        int sx=a[i].x-t,sy=a[i].y-t,ex=a[i].x+t,ey=a[i].y+t+1;
        A[++tot]={sx,ex,sy,1}; val[tot]=sx;
        A[++tot]={sx,ex,ey,-1}; val[tot]=ex;
    }
    sort(val+1,val+tot+1);
    int m=unique(val+1,val+tot+1)-val-1;
    for(int i=1;i<=tot;i++){
        A[i].sx=lower_bound(val+1,val+m+1,A[i].sx)-val;
        A[i].ex=lower_bound(val+1,val+m+1,A[i].ex)-val;
    }
    sort(A+1,A+tot+1);
    for(int i=1;i<=tot;i++){
        Add(ret,mul(tree.len[1],A[i].y-A[i-1].y));
        tree.update(1,1,m,A[i].sx,A[i].ex,A[i].flag);
    }
    return sub(ret,n);
}
int Colli[N*N],cnt=0;

void init(){
    n=read(); t=read();
    for(int i=1;i<=n;i++) a[i].x=read(),a[i].y=read();
    Colli[++cnt]=1;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            Colli[++cnt]=max((_abs(a[i].x-a[j].x)+1)/2,(_abs(a[i].y-a[j].y)+1)/2);
        }
    }
    sort(Colli+1,Colli+cnt+1); cnt=unique(Colli+1,Colli+cnt+1)-Colli-1;   
}

void solve(){
    int ti=1; Colli[++cnt]=inf;
    Add(ans,mul(t,calc(t)));
    while(Colli[ti]<t){
        static int f[5],id[5];
        if(Colli[ti+1]-Colli[ti]<=4){
            for(int i=Colli[ti];i<Colli[ti+1];i++){
                if(i==t){cout<<ans<<endl; return;}
                else Sub(ans,calc(i));
            }
        }
        else{
            for(int i=1;i<=4;i++){
                id[i]=Colli[ti]+i-1;
                f[i]=add(calc(id[i]),f[i-1]);
            }
            int R=min(Colli[ti+1]-1,t-1),tmp=0;
            for(int i=1;i<=4;i++){
                int s=1;
                for(int j=1;j<=4;j++) if(i!=j){
                    Mul(s,mul(sub(R,id[j]),qpow(sub(i,j),MOD-2)));
                }
                Sub(ans,mul(f[i],s));
            }
            Sub(ans,tmp);
        }
        ti++;
    }
    cout<<ans<<endl;
}

int main()
{
    init(); solve();
    return 0;
}