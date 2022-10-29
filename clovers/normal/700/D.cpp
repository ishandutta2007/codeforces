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
int n,q,a[N],bel[N],B;
struct node{
    int l,r,id;
    bool operator < (const node &rhs) const{
        if(bel[l]==bel[rhs.l]) return r<rhs.r;
        return bel[l]<bel[rhs.l];
    }
}Q[N];
int t[N],cnt[N];
ll ans=0; 
vector<int> v;
priority_queue<int,vector<int>,greater<int> > qq;
void calc(){
    while(sz(qq)>1){
        int x1=qq.top(); qq.pop();
        int x2=qq.top(); qq.pop();
        ans+=x1+x2; qq.push(x1+x2);
    }
}
void insert(int x){
    cnt[t[x]]--;
    t[x]++; cnt[t[x]]++;
}
void del(int x){
    cnt[t[x]]--;
    t[x]--; cnt[t[x]]++;
}
struct myyak{
    int x1,x2,num;
};
vector<myyak> used;
void ready(){
    used.clear();
    while(!qq.empty()) qq.pop();
    ans=0; int pre=-1;
    for(int i=1;i<B;i++) if(cnt[i]){
        if(pre!=-1){
            ans+=i+pre;
            used.push_back({pre,i,1});
            cnt[i]--; cnt[pre]--; cnt[i+pre]++;
            if(i+pre>=B) qq.push(i+pre);
        }
        ans+=2ll*i*(cnt[i]/2);
        used.push_back({i,i,cnt[i]/2});
        cnt[i+i]+=cnt[i]/2;
        if(i+i>=B){
            for(int j=1;j<=cnt[i]/2;j++) qq.push(i+i);
        }
        cnt[i]-=(cnt[i]/2)*2;
        if(cnt[i]) pre=i;
        else pre=-1;
    }
    if(pre!=-1) qq.push(pre);
    for(auto &u : v) if(t[u]>=B) qq.push(t[u]);
    for(auto &u : used){
        cnt[u.x1]+=u.num; cnt[u.x2]+=u.num;
        cnt[u.x1+u.x2]-=u.num;
    }
}

ll ret[N];
int main()
{
    n=read(); for(int i=1;i<=n;i++) a[i]=read(),cnt[a[i]]++;
    q=read(); for(int i=1;i<=q;i++) 
        Q[i].l=read(),Q[i].r=read(),Q[i].id=i;
    int Blk=(int)sqrt(1.0*n+0.5);
    B=(int)sqrt(13.0*n+0.5);
    for(int i=1;i<=100000;i++) if(cnt[i]>=B) v.push_back(i);
    for(int i=1;i<=n;i++) bel[i]=(i+Blk-1)/Blk;
    sort(Q+1,Q+q+1);
    memset(cnt,0,sizeof(cnt));
    int l=1,r=0;
    for(int i=1;i<=q;i++){
        while(r<Q[i].r) r++,insert(a[r]);
        while(r>Q[i].r) del(a[r]),r--;
        while(l<Q[i].l) del(a[l]),l++;
        while(l>Q[i].l) l--,insert(a[l]);
        ready(); calc();
        ret[Q[i].id]=ans;
    }
    for(int i=1;i<=q;i++) printf("%lld\n",ret[i]);
    return 0;
}