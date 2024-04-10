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
const int N=1000005;
const int M=305;
int dis[M][4005];
int prime[]={2,3,5,7,11,13,17,19};
int id[N],tot=0;
int id2[N],tot2=0;
void dfs(int x,int now,int lim,int lim2,int D,int nowdis){
    if(now==8) return;
    if(!id[x]) id[x]=++tot;
    if(!id2[D]) id2[D]=++tot2;
    checkmin(dis[id[x]][id2[D]],nowdis);
    for(int i=0;i<=lim;i++){
        for(int j=0;j<=lim2;j++) if(nowdis+_abs(i-j)<=15){
            dfs(x,now+1,i,j,D*(j+1),nowdis+_abs(i-j));
        }
        x=x*prime[now]; if(x>1e6) break;
    }
}

void init(){
    memset(dis,0x3f,sizeof(dis));
    dfs(1,0,20,20,1,0);
    int n=1000000;
    for(int i=1;i<=n;i++) if(!id[i]){
        vector<int> v; int x=i;
        for(int j=2;j*j<=x;j++) if(x%j==0){
            int num=0; while(x%j==0) x/=j,num++;
            v.push_back(num);
        }
        if(x!=1) v.push_back(1),x=1;
        sort(v.begin(),v.end(),greater<int>());
        for(int j=0;j<sz(v);j++) x*=qpow(prime[j],v[j]);
        id[i]=id[x];
    }
}

int main()
{
    init();
    int T=read();
    while(T--){
        int x=read(),y=read();
        x=id[x]; y=id[y]; int ans=inf;
        for(int i=1;i<=tot2;i++) checkmin(ans,dis[x][i]+dis[y][i]);
        printf("%d\n",ans);
    }
    return 0;
}