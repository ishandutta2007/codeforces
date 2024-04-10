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
const int N=4105;
const int M=66000;
const int B=256;
int n,a[N],pos[N],q,cnt,bel[N];
vector<pii> myy;
int Merge(int x,int y){
    myy.push_back(mk(x,y));
    cnt++; 
    return cnt;
}
struct node{int l,r;}Q[M];
struct node2{int l,r,to;};
vector<int> vl[N],vr[N];
int mp[N][N];
int b[N],top=0;
void solve(int l,int r,vector<int> v){
    if(v.empty()) return;
    if(l==r){mp[v[0]][v[0]]=b[v[0]]; return;}
    int mid=(l+r)>>1;
    vector<int> pl,pr;
    for(auto &u : v){
        if(a[b[u]]<=mid) pl.push_back(u);
        else pr.push_back(u);
    }
    solve(l,mid,pl); solve(mid+1,r,pr);
    vector<node2> tt;
    for(int i=0,j=0;i<sz(pl);i++){
        while(j<sz(pr)&&pr[j]<pl[i]) j++;
        int x=i+1,y=j;
        while(x<sz(pl)||y<sz(pr)){
            if(y==sz(pr)||(x!=sz(pl)&&pl[x]<pr[y])) x++;
            else y++;
            if(y!=j) tt.push_back({pl[i],max(pl[x-1],pr[y-1]),Merge(mp[pl[i]][pl[x-1]],mp[pr[j]][pr[y-1]])});
        }
    }
    for(int i=0,j=0;j<sz(pr);j++){
        while(i<sz(pl)&&pl[i]<pr[j]) i++;
        int x=i,y=j+1;
        while(x<sz(pl)||y<sz(pr)){
            if(y==sz(pr)||(x!=sz(pl)&&pl[x]<pr[y])) x++;
            else y++;
            if(x!=i) tt.push_back({pr[j],max(pl[x-1],pr[y-1]),Merge(mp[pl[i]][pl[x-1]],mp[pr[j]][pr[y-1]])});
        }
    }
    for(auto &u : tt) mp[u.l][u.r]=u.to;
}
vector<int> v[M];
int L[M],R[M];
void run(int id){
    top=0;
    for(int i=1;i<=n;i++) if(bel[i]==id) b[++top]=i;
    vector<int> tt; for(int i=1;i<=top;i++) tt.push_back(i);
    solve((id-1)*B+1,min(n,id*B),tt);
    for(int i=1;i<=q;i++){
        vl[Q[i].l].push_back(i);
        vr[Q[i].r].push_back(i);
    }
    tt.clear();
    b[top+1]=n+1;
    memset(L,-1,sizeof(L));
    memset(R,-1,sizeof(R));
    for(int i=1,j=1;i<=n;i++){
        for(auto &u : vl[i]) tt.push_back(u);
        if(i==b[j]){
            for(auto &u : tt) L[u]=j;
            tt.clear();
            j++;
        }
    }
    tt.clear();
    for(int i=n,j=top;i>=1;i--){
        for(auto &u : vr[i]) tt.push_back(u);
        if(i==b[j]){
            for(auto &u : tt) R[u]=j;
            tt.clear();
            j--;
        }
    }
    for(int i=1;i<=q;i++){
        //out(i); out(L[i]); outln(R[i]);
        if(L[i]==-1||R[i]==-1||L[i]>R[i]) continue;
        v[i].push_back(mp[L[i]][R[i]]);
    }
}

int ans[M];
int main()
{
    n=read(); q=read(); cnt=n;
    for(int i=1;i<=n;i++) a[i]=read(),pos[a[i]]=i;
    for(int i=1;i<=q;i++) Q[i].l=read(),Q[i].r=read();
    for(int i=1;i<=n;i++) bel[i]=(a[i]+B-1)/B;
    for(int i=1;i<=(n+B-1)/B;i++) run(i);
    for(int i=1;i<=q;i++){
        ans[i]=v[i][0];
        for(int j=1;j<sz(v[i]);j++){
            ans[i]=Merge(ans[i],v[i][j]);
        }
    }
    cout<<cnt<<endl;
    for(auto &u : myy) printf("%d %d\n",u.first,u.second);
    for(int i=1;i<=q;i++) printf("%d ",ans[i]); puts("");
    return 0;
}