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
int n,m,num[N],vis[N],bl[N]; char opt[N][2];
vector<int> ans,v;

int main()
{
    n=read(); m=read();
    for(int i=1;i<=m;i++) scanf("%s%d",opt[i],&num[i]);
    memset(vis,-1,sizeof(vis));
    for(int i=1;i<=m;i++){
        if(vis[num[i]]!=-1) continue;
        if(opt[i][0]=='+') vis[num[i]]=0;
        else vis[num[i]]=1;
    }
    int now=0;
    for(int i=1;i<=n;i++) if(vis[i]==1) now++;
    if(now){
        for(int i=1;i<=n;i++) if(vis[i]==0) bl[i]=1;
    }
    else for(int i=1;i<=n;i++) if(vis[i]==0) v.push_back(i);
    for(int i=1;i<=m;i++){
        if(opt[i][0]=='+'){
            vis[num[i]]=1,now++;
            for(auto &u : v) if(u!=num[i]) bl[u]=1;
            v.clear();
        }
        else{
            vis[num[i]]=0; now--;
            if(now>0) bl[num[i]]=1;
            else if(!bl[num[i]]) v.push_back(num[i]);
        }
    }
    for(int i=1;i<=n;i++) if(!bl[i])  ans.push_back(i);
    cout<<sz(ans)<<endl;
    for(auto &u : ans) printf("%d ",u);
    return 0;
}